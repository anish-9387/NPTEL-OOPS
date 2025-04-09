import socket

sock=socket.socket(socket.AF_INET,socket.SOCK_DGRAM,socket.IPPROTO_UDP)

sock.setsockopt(socket.IPPROTO_IP,socket.IP_MULTICAST_TTL,2)  # IPPROTO_IP --> specifying option for IP level, TTL --> Time to live for multicast packet, 2 --> allows the packet to travel across 2 routers

sock.sendto(b"Multicast Message",("224.0.0.1",5000))