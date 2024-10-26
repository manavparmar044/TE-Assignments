import threading
import time
import random

# Shared buffer and capacity
buffer = []
buffer_capacity = 5

# Mutex lock for accessing the buffer
buffer_lock = threading.Lock()

# Stop event to stop threads
stop_event = threading.Event()

# Producer function
def producer():
    while not stop_event.is_set():
        with buffer_lock:
            if len(buffer) < buffer_capacity:
                item = random.randint(1, 100)
                buffer.append(item)
                print(f"Produced: {item}")
        time.sleep(random.random())  # Simulate production time

# Consumer function
def consumer():
    while not stop_event.is_set():
        with buffer_lock:
            if buffer:
                item = buffer.pop(0)
                print(f"Consumed: {item}")
        time.sleep(random.random())  # Simulate consumption time

# Create producer and consumer threads
producer_thread = threading.Thread(target=producer)
consumer_thread = threading.Thread(target=consumer)

# Start threads
producer_thread.start()
consumer_thread.start()

# Let the producer and consumer run for a while, then stop
time.sleep(10)
stop_event.set()  # Signal threads to stop

# Wait for both threads to finish
producer_thread.join()
consumer_thread.join()

print("Stopped")