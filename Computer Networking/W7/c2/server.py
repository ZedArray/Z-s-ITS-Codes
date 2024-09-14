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
            if message[0].isdigit():
                result = str(eval(message))
                message = message[:-1] + ' = ' + result + '\n'
                print('<' + addr[0] + '>' + message)
                message_to_send = '<' + addr[0] + '>' + message
                broadcast(message_to_send, conn)
            elif not message[0].isdigit():
                if message[:-1].lower() == 'list':
                    idlist = ("List of IDs: \n")
                    conn.send(idlist.encode())
                    for i in range(1, len(list_of_clients)+1):
                        message = str(i) + '\n'
                        try:
                            conn.send(message.encode())
                        except:
                            conn.close()
                            remove(conn)
                    continue
                else:
                    splitMessage = message.split(' ', 2)
                if splitMessage[0].lower() == 'private':
                    print('<' + addr[0] + '>' + message)
                    message_to_send = '<' + addr[0] + '>' + splitMessage[2] + '\n'
                    list_of_clients[int(splitMessage[1])-1].send(message_to_send.encode())
                else:
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
    # if dest == -1:
    #     for clients in list_of_clients:
    #         if clients == conn:
    #             try:
    #                 conn.send(message.encode())
    #                 for i in range(1, len(list_of_clients)+1):
    #                     message = str(i) + '\n'
    #                     conn.send(message.encode())
    #             except:
    #                 conn.close()
    #                 remove(conn)
    # elif dest == 0:
    #     for clients in list_of_clients:
    #         if clients != conn: 
    #             try:
    #                 clients.send(message.encode())
    #             except:
    #                 clients.close()
    #                 remove(clients)
    # else:
    #     count = 1
    #     for clients in list_of_clients:
    #         if str(count) == dest:
    #             try:
    #                 clients.send(message.encode())
    #             except:
    #                 clients.close()
    #                 remove(clients)
            # else:
            #     count = count + 1
            

def remove(connection):
    if connection in  list_of_clients:
        list_of_clients.remove(connection)

while True:
    conn, addr = server.accept()
    list_of_clients.append(conn)
    print(addr[0] + 'connected with ID: ' + str(len(list_of_clients)))
    showID = "Your ID is: " + str(len(list_of_clients)) + '\n'
    conn.send(showID.encode())
    threading.Thread(target=clientThread, args=(conn, addr)).start()

conn.close()