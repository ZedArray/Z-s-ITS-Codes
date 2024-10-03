import socket
import select
import sys
import threading
from os import listdir

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
ip_address = '127.0.0.1'
port = 8081
server.bind((ip_address, port))
server.listen(100)
list_of_clients = []
chatlog = ''

def clientThread(conn, addr):
    while True:
        try:
            message = conn.recv(2048).decode()
            currId = getId(conn)
            splitmsg = message.split(' ', 1)
            if message[:-1].lower() == 'list':
                print('<Person ' + currId + '> requested file list')
                # chatlog.append('<Person ' + currId + '> requested file list\n')
                fileList = listdir("./chatstorage")
                for files in fileList:
                    files = str(files) + '\n'
                    conn.send(files.encode())
            elif splitmsg[0].lower() == 'upload':
            # Creating a new file at server end and writing the data 
                filename = splitmsg[1]
                filename = filename[:-1]
                fo = open("./chatstorage/" + filename, "w") 
                data = conn.recv(1024).decode()
                if not data: 
                    continue
                fo.write("balls")
                while data: 
                    if not data: 
                        break
                    else: 
                        print("asdflsdjflsdkfj")
                        fo.write("a") 
                        print("bruh")
                        data = conn.recv(1024).decode() 
                        print("lmao")
        
                print() 
                print('Receiving file from client ', currId) 
                print() 
                print('Received successfully! New filename is:', filename) 
                fo.close() 
            elif message[:-1].lower() == 'log':
                pass
            elif message[:-1] == 'downzip':
                pass
            elif message:
                print('<Person ' + currId + '>' + message)
                message_to_send = '<Person ' + currId + '>' + message
                broadcast(message_to_send, conn)

            else:
                remove(conn)
        except:
            continue

def getId(conn):
    clientcounter = 1
    for clients in list_of_clients:
        if clients == conn:
            return str(clientcounter)
        else:
            clientcounter += 1

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
    print(addr[0] + ' connected')
    threading.Thread(target=clientThread, args=(conn, addr)).start()

conn.close()