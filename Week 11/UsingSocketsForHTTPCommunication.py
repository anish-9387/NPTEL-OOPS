import socket

host="www.french-cuisines.vercel.app"
port=80

client=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
client.connect((host,port))

request="GET / HTTP/1.1\r\nHost: {}\r\n\r\n".format(host)
client.send(request.encode())

response=client.recv(4096)
print(response.decode())

client.close()