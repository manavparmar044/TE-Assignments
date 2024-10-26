import threading
import time
import random

buffer = []
buffer_capacity = 5

empty = threading.Semaphore(buffer_capacity)
full = threading.Semaphore(0)

buffer_lock = threading.Lock()
stop_event = threading.Event()

def producer():
    while not stop_event.is_set():
        item = random.randint(1,100)
        empty.acquire()
        with buffer_lock:
            buffer.append(item)
            print(f"Produced: {item}")
        full.release()
        time.sleep(random.random())

def consumer():
    while not stop_event.is_set():
        full.acquire()
        with buffer_lock:
            if buffer:
                item = buffer.pop(0)
                print(f"Consumed: {item}")
        empty.release()
        time.sleep(random.random())

producer_thread = threading.Thread(target=producer)
consumer_thread = threading.Thread(target=consumer)

producer_thread.start()
consumer_thread.start()

time.sleep(10)
stop_event.set()

producer_thread.join()
consumer_thread.join()

print("Stopped")