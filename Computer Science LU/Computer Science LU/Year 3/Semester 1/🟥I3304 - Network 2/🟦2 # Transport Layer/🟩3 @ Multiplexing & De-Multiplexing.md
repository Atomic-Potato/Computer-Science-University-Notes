_Next [[🟩4 @ User Datagram Protocol (UDP)]]_
_Previous [[🟩2 @ Transport Layer Services]]_

---
Say we have 2 applications in the host sending out data to separate servers. And the servers want to reply back but dont know what application they need to reply to, they only know the IP address of the hosting machine.

Thats why Multiplexing & De-Multiplexing is used in the transport layer, which assigns a port number to each app and gets the port address of the server, and send them with the datagram.

![[Pasted image 20230222172026.png]]

# How demultiplexing works
Host receives IP datagrams:
- Each datagram has source IP address, destination IP address
- Each datagram carries one transport- layer segment
- Each segment has source, destination port number

Host uses IP addresses & port numbers to direct segment to appropriate socket
![[Pasted image 20230222172131.png]]
_(each port is 16 bits in size)_

---
_Next [[🟩4 @ User Datagram Protocol (UDP)]]_
_Previous [[🟩2 @ Transport Layer Services]]_
