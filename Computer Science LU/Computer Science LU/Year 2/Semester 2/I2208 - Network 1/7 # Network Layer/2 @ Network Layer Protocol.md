_Previous:_ [[1 @ Network Layer & Addressing]]

---

# IPv4
idk didnt really get much explanation on it:

![[Pasted image 20220823195235.png]]
- `VER:`  IP protocol version number
- `HLEN:` header length (bytes)
- `Service:` “type” of data
- `Total Length:` The length in bytes of the data this layer is encapsulating
- `Flags:` Marks if this encapsulation is part of a fragmentation or the end of one
- `Fragmentation offset:` helps in reassembly of fragments
- `Time to live:` how many routers this can pass before its declared an infinite loop and gets canceled
- `Protocol`: The value of the protocol defines to which protocol the data belongs
![[Pasted image 20220823195738.png]]
![[Pasted image 20220823195750.png]]

--- 

# IP Fragmentation & Reassembly
Network links have a MTU (max transfer size/unit). 
So large IP datagram divided (“fragmented”) within a network and only “reassembled” only at final destination.
IP header bits used to identify and order related fragments. (`Flags` and `Offset`)

>**Steps of fragmentation:**
>1) Subtract 20 from original length: _(bytes of "IP header data")_
>2) Subtract 20 from the `MTU`: _(max. bytes of data in each fragment)_
>3) Divide "maximum data bytes" by `8`: **to get offset increment**
>4) Offset of each fragment "n" (n = 0, 1, 2, ...) = n x "offset increment"
>5) Length of each fragment (except last) = 20 + "max. data bytes“
>6) Length of last fragment = 20 + remaining data bytes
>
>(Note that each fragment has the same ID and a flag of 1 except for the last has a flag of 0)

*Example:*
![[Pasted image 20220823200529.png | 600]]
> **For reassembly:**
> Simply get all the fragments with the same ID
> And order them depending on the offset until you reach the one with flag 0
> And with some magic they fall back into one (amazing!)

--- 
_Previous:_ [[1 @ Network Layer & Addressing]]
