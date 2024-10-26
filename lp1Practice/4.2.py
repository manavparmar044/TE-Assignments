import threading
import time
import random

buffer = []
buffer_capacity = 5

buffer_lock = threading.Lock()
stop_event = threading.Event()

def producer():
    while not stop_event.is_set():
        if(len(buffer)<buffer_capacity):
            item = random.randint(1,100)
            buffer.append(item)
            print(f"Produced: {item}")
        time.sleep(random.random())

def consumer():
    while not stop_event.is_set():
        with buffer_lock:
            if buffer:
                item = buffer.pop(0)
                print(f"Consumed: {item}")
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
