# Evolution
The ethernet cable has a max capacity, just like a water hose
![[Pasted image 20220712200753.png | 400]]

# [[1 @ Data Link Layer#DLC MAC| MAC Frame]]
Physical Layer
![[Pasted image 20220712201235.png]]
This is basically all the layers encapsulating, this is the data link layer
![[Pasted image 20220712201022.png]]

# Categories of ethernet
![[Pasted image 20220712201518.png]]
![[Pasted image 20220712201526.png]]

---
# Ethernet Address
![[Pasted image 20220712201617.png]]

# Frame Processing
The source sends its address and the destination address, and the message is sent, if a user receives the message but has a different destination address, then they ignore it, otherwise they accept it.
![[Pasted image 20220712201650.png]]

## Types of MAC address
- `Unicast:`
Same as above
![[Pasted image 20220712201834.png]] 
- `Broadcast:`
The destination address is `FF:FF:FF:FF:FF:FF`, this means if a user receives this destination address, it means its not meant for them but its meant for everyone so they accept the message
![[Pasted image 20220712202003.png]]
- `Multicast:`
Same as `Broadcast`, but the destination source is the same destination address (predefined) for multiple users.
![[Pasted image 20220712202119.png]]

---
# Switch
A switch has `ports`, these ports should be assigned to a `MAC address` of machine.
When the switch boots up, each port's mac address is **NULL**. So as time goes, when machine sends a message, it does the same process in **Forward Processing** and once it reaches the destination, it saves the `MAC address` of this machine to the port, so next time a message gets sent to **this** MAC address, it goes to it directly.

Note that if the switch reboots, the MAC addresses are reset to NULL.

![[Pasted image 20220712202525.png]]
![[Pasted image 20220712202530.png]]
![[Pasted image 20220712202537.png]]
![[Pasted image 20220712202545.png]]
![[Pasted image 20220712202554.png]]