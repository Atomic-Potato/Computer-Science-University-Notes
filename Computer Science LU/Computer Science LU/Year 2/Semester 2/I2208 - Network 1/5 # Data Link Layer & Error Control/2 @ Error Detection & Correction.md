Error Detection and Correction are implemented at the [[1 @ Data Link Layer|data link]] layer and the transport layer of the internet model.

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

# Polynomial Code
Let `T = 1011` be the original message. We want to add redundant to help us detect errors at the receiver
Let `T' = 1011 000 (4,7) - (k,n)` be the message with redundant bits *(000)* where `k` is the **size of the original message** and `n` the **size with redundant bits**

- `Polynom generator:` is a polynom that will generate the redundant bits
	- The generator `G` must be predefined, take for example in this case $\large G = x^3+1$
	1. Write `T` as polynom: $\large 1x^0+1x^1+1x^2+1x^3 = x^3+x^2+1$
	2. **Shift** `T` with 3 bits, i.e. multiply by $\large x^3$: `T'` = $x^3 * (x^3+x^2+1) = x^6 +x^5+x^3$
	3. To generate redundant bits, divide `T'` by the polynom generator to get `R = T'/G` using **Euclidean division** (in our case `R = x^2`)
	![[Pasted image 20220707200513.png | 300]]
	(The `XOR` here means that if they are equal then their addition is 0, pretty much the same if you just reduce them from eachother)
	4. `T' = T' + R` = $\large x^6 +x^5+x^3+x^2$ <=> $\large 1x^6 + 1x^5 + 0 + 1x^3 + 1x^2 + 0 + 0$ <=> 1101100 which is now our new message to be sent
		`Note that X/Y yeilds R and then (X+R)/Y is divisible by R`
	5. At the receiver simply check if `G` divides `T'`
		- If yes then the message is correct
		- otherwise its not correct