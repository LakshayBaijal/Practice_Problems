import socket

client = socket.socket()
client.connect(("127.0.0.1",8080))



s = input()
client.send(s.encode())

data = client.recv(1024)

get = data.decode()

print(get)


client.close()
