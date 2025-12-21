import socket

server = socket.socket()
server.bind(("0.0.0.0",8080))
server.listen(1)

print("Server waiting for connection...")
client , addr = server.accept()
print("Client connected")

data = client.recv(1024)
print("Client says:", data.decode())

client.send(b"Hello Client")

client.close()
server.close()
