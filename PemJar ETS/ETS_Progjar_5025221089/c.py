import socket
import select
import sys
from threading import Thread

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
ip_address = '127.0.0.1'
port = 8081
server.connect((ip_address, port))

def send_msg(sock):
    while True:
        data = sys.stdin.readline()
        sock.send(data.encode())
        sys.stdout.write('<You>')
        sys.stdout.write(data)
        sys.stdout.flush()
        splitData = data.split(' ', 1)
        if splitData[0].lower() == "upload":
            filename = splitData[1]
            # read file and send
            try: 
                fi = open(filename[:-1], "r") 
                data = fi.read() 
                if not data: 
                    break
                while data: 
                    sock.send(str(data).encode()) 
                    data = fi.read() 
                # File is closed after data is sent 
                fi.close() 
  
            except IOError: 
                print('You entered an invalid filename!\nPlease enter a valid name') 

        
def recv_msg(sock):
    while True:
        data = sock.recv(2048)
        sys.stdout.write(data.decode())
        
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