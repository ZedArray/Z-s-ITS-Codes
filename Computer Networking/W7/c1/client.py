import socket
import select
import sys
from threading import Thread

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
ip_address = '127.0.0.1'
port = 5000
server.connect((ip_address, port))

def send_msg(sock):
    while True:
        data = sys.stdin.readline()
        sock.send(data.encode())
        sys.stdout.write('<You>')
        sys.stdout.write(data)
        sys.stdout.flush()

def recv_msg(sock):
    while True:
        try:
            data = sock.recv(2048)
            if not data:
                print("Disconnected from server.")
                break
            sys.stdout.write(data.decode())
        except ConnectionResetError:
            print("Connection reset by peer.")
            break
        except Exception as e:
            print("Error receiving message:", e)
            break

Thread(target=send_msg, args=(server,)).start()
Thread(target=recv_msg, args=(server,)).start()

while True:
    sockets_list = [server]
    read_socket, write_socket, error_socket = select.select(sockets_list, [], [])
    for socks in read_socket:
        if socks == server:
            recv_msg(socks)
        else:
            send_msg(socks)

server.close()