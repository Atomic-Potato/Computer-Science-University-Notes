Error Detection and Correction are implemented at the [[🟩1 @ Data Link Layer|data link]] layer and the transport layer of the internet model.

# Types of Errors
- `Single-bit:`
	![[Pasted image 20220707144651.png | 300]]
- `Bust-bit:`
	The length of the burst is measured from the 1 st corrupted bit to the last corrupted bit.
	Some bits in between may not have been corrupted.
	![[Pasted image 20220707144758.png | 300]]

# Redundancy bits
We split the transmitted bits into parts and we add a redundant bit at the end of each part. 
This bit will help us detect any error, and which will be discarded at the end.
![[Pasted image 20220707145346.png | 500]]

Theres 2 ways to correct errors:
- `Forward Error Correction:`  is the process in which the receiver tries to guess the message by using redundant bits.
- `Retransmission:`  is a technique in which the receiver detects the occurrence of an error and asks the sender to resend the message.

## Reminder of Modulo-2 Arithmetic
- `Addition:`
	```c
	0+0=0 0+1=1 1+0=1 1+1=0
	```
- `Subtraction:`
	```c
	0-0=0 0-1=1 1-0=1 1-1=0
	```

And the [[Chp 3#The XOR gate|XOR gate]]

---

# Simple parity-Check code
- In Simple parity-check code, a `k-bit dataword` is changed to an `n-bit codeword` where `n=k+1`.
- The extra bit, called the parity bit, is selected to make the total number of 1s in the codeword **even or odd.**
- This code is a `single-bit error-detecting code`; **it cannot correct any error.**

**How it works:**
1. Choose `k` and `n` depending on the sent message in **(2)**
2. Split the message into parts where each part has `k bits`
3. Start preforming `XOR` operations from **left to right** on the bits and keep the result (preform on each part separately)
4. Send the string of bit but order the parts such that the result is the last bit on the right (same order for the parts as the original)
5. In part **(4)** we surrounded with yellow the parts that contain an error, now we split the received message into `n` parts and preform the same step in part **(3)**. If the result is `1` then **there is an error** if the result is `0` then **there's no error**
![[Pasted image 20220707151123.png | 500]]

**Note:** the problem with this method is that it only detects an **odd** amount of errors only

Encoder and decoder for simple parity-check code:
![[Pasted image 20220707152350.png | 500]]

---

# Two-dimensional parity Check Code
In Two-dimensional parity-check code, the data code is organized in a table (rows and columns).

The original message is:
```c
1100111 1011101 0111001 0101001
```
Ordered into a table:
![[Pasted image 20220707152516.png]]
- We preform `XOR` from **left to right** in the **rows** to receive the red result
- We preform `XOR` from **top to bottom** in the **columns** to receive the red result
- The same thing for the resulting row of columns and the resulting column of rows to receive the corner result

## Detecting errors
In image **b** we preform the `simple parity check (SPC)` on the column to detect the error
In image **c** we can detect it by applying `SPC` on the row, so we apply it on each column
![[Pasted image 20220707153353.png | 500]]

But here in image **e** we can see that we can still not detect the error because its **even on both the rows and the columns** 
![[Pasted image 20220707153549.png | 500]]

---

# Polynomial Code (CRC)
Let `T = 1011` be the original message. We want to add redundant bits to help us detect errors at the receiver
Let `T' = 1011 000 (4,7) - (k,n)` be the message with redundant bits *(000)* where `k` is the **size of the original message** and `n` the **size with redundant bits**
(Return to this note after reading the later steps.... : These 3 bits are **shifted** depending on the degree of the generator which has a degree of 3)
- `Polynom generator:` is a polynom that will generate the redundant bits
	- The generator `G` must be predefined, take for example in this case $\large G = x^3+1$
	1. Write `T` as polynom: $\large 1x^0+0x^1+1x^2+1x^3 = x^3+x^2+1$
	 ![[Pasted image 20220823145743.png | 500]]
	3. **Shift** `T` with 3 bits, i.e. multiply by $\large x^3$: `T'` = $x^3 * (x^3+x^2+1) = x^6 +x^5+x^3$
	4. To generate redundant bits, divide `T'` by the polynom generator to get `R = T'/G` using **Euclidean division** (in our case `R = x^2`)
	![[Pasted image 20220707200513.png | 300]]
	(The `XOR` here means that if they are equal then their addition is 0, pretty much the same if you just reduce them from eachother)
	4. `T' = T' + R` = $\large x^6 +x^5+x^3+x^2$ <=> $\large 1x^6 + 1x^5 + 0 + 1x^3 + 1x^2 + 0 + 0$ <=> 1101100 which is now our new message to be sent
		`Note that X/Y yeilds R and then (X+R)/Y is divisible by R`
	5. At the receiver simply check if `G` divides `T'`
		- If yes then the message is correct
		- otherwise its not correct

`Note:` when adding polynoms, we divide by 2 the result, then we take the remainder, so $x^2+x^2 = 0x^2 = 0$ and $x^2 + x^2 + x^2 = 3x^2 = x^2$ (Same for subtraction)

## Shifting
![[Pasted image 20220712175455.png]]

## CRC at the receiver end
In this method, there's a chance that the code cannot be detected.
Let `E(x) = T(x) - T'(x)` *(this will extract the error)*, if **E(x)**  can be divided by the generator **G(x)**, then the error cannot be detected.

*Example on E(x):*
![[Pasted image 20220712192034.png | 400]]

Here's some well known generators that are reliable:
![[Pasted image 20220712192122.png | 400]]

---

# Checksum
Take the set of numbers _(7, 11, 12, 0, 6)_ as the message that we want to send. There are two methods we can do this:
- `method 1:`
	- Add all the numbers for the set to become _(7, 11, 12, 0, 6, 36)_
	- Convert the sum to binary
	- Here all the numbers can be represented in **4 bits** (take it as `n`) except for the last one that takes which needs **6 bits**. So we add zeros at the left so it would become a **multiple of n**. Now split the result in half, and add both halfs, then convert the result using [[Chapter 2 Conversions#Complements|1's complement]] by adding a row of 1's
- `method 2:`
	- Convert all numbers to binary
	- add them up
	- convert to 1's complement

- SENDER SIDE:
	1. The message is divided into 16-bit words.
	2. The value of the checksum word is set to 0.
	3. All words including the checksum are added using one’s complement addition.
	4. The sum is complemented and becomes the checksum.
	5. The checksum is sent with the data.
- RECEIVER SIDE:
	1. The message (including checksum) is divided into 16-bit words.
	2. All words are added using one’s complement addition.
	3. The sum is complemented and becomes the new checksum.
	4. If the value of checksum is 0, the message is accepted; otherwise, it is rejected.

## How to read the sequence
If he tells you that the check sum is 16 bits, you divide it in half, each half is 16 bits 
![[Pasted image 20220712200037.png]]