import socket

# Create a socket object
server_socket=socket.socket(socket.AF_INET,socket.SOCK_STREAM)

# Bind the socket to an address and port
server_socket.bind(('localhost',3100))
server_socket.listen(1)  # 1- specifying the max number of pending request in a queue

print("Server is listening...")

conn,addr=server_socket.accept()
print(f"Connected by {addr}")

# Send and recieve data
conn.sendall(b"Hello, Client!")
data=conn.recv(1024)
print(f"Recieved: {data.decode()}")

conn.close()








# Activating the client

# Create a socket object
client_socket=socket.socket(socket.AF_INET,socket.SOCK_STREAM)

# Connect to the server
client_socket.connect(('localhost',3100))

# Recieve and print the server's message
data=client_socket.recv(1024)
print(f"Server: {data.decode()}")

# Send a response to the server
client_socket.sendall(b"Hello, Server!")

# Close the connection
client_socket.close()