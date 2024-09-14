import socket

client = False
server = False

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

if server:
    s.bind(("127.0.0.1", 8080))
    s.listen()
    input()

    while True:
        connect, addr = s.accept()
        connect.send(b"You have made the connection to the server!!")
        connect.close()
