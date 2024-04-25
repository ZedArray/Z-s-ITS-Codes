import socket
import threading

class Server:
    def __init__(self):
        self.host = 'localhost'
        self.port = 5000
        self.backlog = 5
        self.size = 1024
        self.server = None
        self.threads = []

    def open_socket(self):
        self.server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.server.bind((self.host, self.port))
        self.server.listen(5)

    def handle_client(self, client_socket, client_address):
        while True:
            data = client_socket.recv(self.size)
            if not data:
                break
            self.broadcast(data, client_socket)
        client_socket.close()

    def broadcast(self, data, sender_socket):
        for thread in self.threads:
            if thread != sender_socket:
                thread.sendall(data)

    def run(self):
        self.open_socket()
        while True:
            client_socket, client_address = self.server.accept()
            client_thread = threading.Thread(target=self.handle_client, args=(client_socket, client_address))
            client_thread.start()
            self.threads.append(client_socket)

if __name__ == "__main__":
    s = Server()
    s.run()
