import socket

host="www.hotstar.com"
port=80   # standardd port for HTTP traffic
# port=443   # standard port for HTTPS traffic

client=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
client.connect((host,port))

request="GET / HTTP/1.1\r\nHost: {}\r\n\r\n".format(host)
client.send(request.encode())

response=client.recv(4096)  # 4096- maximum bytes to receive at once
print(response.decode())

client.close()