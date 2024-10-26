import threading
import time
import random

# Buffer and buffer capacity
buffer = []
buffer_capacity = 5

# Semaphores for empty and full slots
empty = threading.Semaphore(buffer_capacity)  # initially all slots are empty
full = threading.Semaphore(0)  # initially, no slots are full

# Lock for buffer access
buffer_lock = threading.Lock()

# Event to stop threads
stop_event = threading.Event()

# Producer function
def producer():
    while not stop_event.is_set():  # Check if the stop_event is set
        item = random.randint(1, 100)  # produce an item
        empty.acquire()  # wait if no empty slot
        with buffer_lock:
            buffer.append(item)
            print(f"Produced: {item}")
        full.release()  # increase full slots count
        time.sleep(random.random())  # simulate production time

# Consumer function
def consumer():
    while not stop_event.is_set():  # Check if the stop_event is set
        full.acquire()  # wait if no full slot
        with buffer_lock:
            if buffer:  # Check if buffer is not empty
                item = buffer.pop(0)
                print(f"Consumed: {item}")
        empty.release()  # increase empty slots count
        time.sleep(random.random())  # simulate consumption time

# Create producer and consumer threads
producer_thread = threading.Thread(target=producer)
consumer_thread = threading.Thread(target=consumer)

# Start threads
producer_thread.start()
consumer_thread.start()

# Run for a specified time (e.g., 10 seconds) and then stop
time.sleep(10)
stop_event.set()  # Signal both threads to stop

# Wait for both threads to finish
producer_thread.join()
consumer_thread.join()

print("Producer and Consumer have stopped.")
