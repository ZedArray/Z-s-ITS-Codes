import threading

def worker():
    print(threading.current_thread().name + ' Worker\n')

threads = []
for i in range(5):
    t = threading.Thread(target=worker)
    threads.append(t)
    t.start()