import socket

client = socket.socket()

client.connect(("127.0.0.1",8080))


client.send(b"Hello Server")

data = client.recv(1024)

client.close()
