import socket
import select
import sys
import threading

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
ip_address = '127.0.0.1'
port = 5000
server.bind((ip_address, port))
server.listen(100)
list_of_clients = []

def clientThread(conn, addr):
    while True:
        try:
            message = conn.recv(2048).decode()
            if message:
                result = str(eval(message))
                message = message[:-1] + ' = ' + result + '\n'
                print('<' + addr[0] + '>' + message)
                message_to_send = '<' + addr[0] + '>' + message
                broadcast(message_to_send, conn)

            else:
                remove(conn)
        except:
            continue

def broadcast(message, conn):
    for clients in list_of_clients:
        if clients != conn:
            try:
                clients.send(message.encode())
            except:
                clients.close()
                remove(clients)

def remove(connection):
    if connection in  list_of_clients:
        list_of_clients.remove(connection)

while True:
    conn, addr = server.accept()
    list_of_clients.append(conn)
    print(addr[0] + 'connected')
    threading.Thread(target=clientThread, args=(conn, addr)).start()

conn.close()