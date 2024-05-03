import threading
import datetime

class TestDiff(threading.Thread):
    def run(self):
        now = datetime.datetime.now()
        print(self.name + 'says Hello World at time: ' + str(now) + '\n')

for i in range(10):
    t = TestDiff()
    t.start()