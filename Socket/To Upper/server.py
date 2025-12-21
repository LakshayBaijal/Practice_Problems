import socket

server = socket.socket()

server.bind(("0.0.0.0",8080))
server.listen(1)

client , addr = server.accept()

data = client.recv(1024)

message = data.decode()

up = message.upper()

client.send(up.encode())

client.close()
server.close()
