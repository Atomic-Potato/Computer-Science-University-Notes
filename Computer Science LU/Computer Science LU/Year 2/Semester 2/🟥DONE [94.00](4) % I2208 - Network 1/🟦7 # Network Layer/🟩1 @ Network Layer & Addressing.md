_Next:_ [[🟩2 @ Network Layer Protocol]]

---

The network layer:
- Provides services to allow end devices to exchange data
- and `IPv4` & `IPv6` are the principle network layer communication protocols.

The network layer performs four basic operations:
- Addressing end devices
- Encapsulation
- Routing
- De-encapsulation

# IP Encapsulation
![[Pasted image 20220811121911.png | 400]]
i dont feel like the need to explain this, the image says it all

--- 

# IPv4 Addresses
An `IPv4` address is a **32-bit address** that uniquely and universally defines the connection of a device (for example, a computer or a router) to the Internet.
![[Pasted image 20220811122122.png | 300]]

## Classful Addressing
An IP is divided into 5 classes: `A,B,C,D,E` (D and E are not as important right now)

If the address is in binary, then the first few bits tell us the class. Otherwise in decimal, the first byte
![[Pasted image 20220811122412.png | 500]]
In classes `A,B,C` the cells/bytes marked in yellow are the `Network Address` _(e.g. 192.68.80.42 Network address is 192.68.80.0)_ and the remaining are the `Host ID` **where 255 is for broadcasting and 0 for network,** this also means that everything sent to the broadcasting address, will be sent for everyone with the network address.

## Router Packet forwarding decision
Two hosts can only communicate with eachother if they are in the same network (`Network ID`). If they are in different networks then a router will handle the communication.
![[Pasted image 20220811131414.png | 600]]

---

## Mask
The `mask` is a **32-bit binary number**, and the mask can help to find the `network` and `subnetwork` address.
- The routers outside the organization use a **Default Mask** to find the `network address`
- The routers inside the organization use a **Subnet Mask** to find the `subnetwork address`

The `default masks` are:
![[Pasted image 20220811131727.png | 500]]
(The CIDR is the prefix / number of ones)
Default mask gives the network address when `AND`ed with an address in the block. 

>**_What if the number of is none of the default masks?_**
Consider the IP: _192.168.80.46_
And the subnet /26 => 11111111.11111111.11111111.11000000
>
Then the subnetwork address is: _192.168.80.--_
And the number of 1s in 11000000 is 2 which means the network is divided in $\large 2^2$ subnetworks:
256/4 = 64, then 64 hosts in each subnetwork
>
OR the number of 0s is 6, then each network has $\large2^6 - 2 = 62 \space hosts$ (64 IPs  in each subnetwork)

### Subnetting
A network is divided into several smaller networks with each subnetwork (or subnet) having its subnetwork address.
This is used to resolve the problem of large network sizes.


>To make a subnet mask we change the 0s inside the `default mask`
>The number of subnets is determined by the number of extra 1s.
> - If the number of extra 1s in `n`, **the number of subnets is 2^n** .
 >- If the number of subnets is `N`, **the number of extra 1s is $\large log_2(N)$**.

*For example:*
Take class C, it can be divided into 4 subnets each of size 64: 1 subnet address, 1 broadcast address for the subnet and 62 for hosts in the subnet.

The `subnet address` is the first address of a subnet, and the `broadcast address` is the last address of the subnet.
==(2 subnetworks need a router to communicate)==


- This may help more:
![[Pasted image 20221001202457.png | 500]]
![[Pasted image 20221001202535.png]]

---
_Next:_ [[🟩2 @ Network Layer Protocol]]