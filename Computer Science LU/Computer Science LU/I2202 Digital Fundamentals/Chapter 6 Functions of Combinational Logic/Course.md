# Half-Adder
Basic rules of binary addition are performed by a `half adder` which has 2 binary inputs (A and B) and 2 binary outputs (Carry out and Sum).
The operations are represented in the following truth table
![[Pasted image 20211226131709.png | 150]]

The logic symbol and equivalent circuit are:
![[Pasted image 20211226131751.png | 350]]
`But a half adder cannot calculate an addition containing a carry`

# Full-Adder
![[Pasted image 20211226133248.png | 500]]
- By adding A and B we obtain $\sum_1$ and $C_{out1}$ 
- By adding $\sum_1$ with $C_{in}$ we obtain $Sum$ and $C_{out2}$

# Parallel Adders
We learned how to add 2 numbers with each 1 bit and we learned how to add 3 numbers with each 1 bit, now we will use Parallel Adders to add 2 numbers with more than 1 bit. Its pretty simple if you understand how a full adder works out, heres a 4-bit number example:
![[Pasted image 20211226134301.png | 300]]
The output carry ($C_4$) is not ready until it propagates through all of the adders. This is called *`ripple carry`*, delaying the addition process.
Also usually $C_0$ has a value of 0 ==(It will be useful when we do subtraction)==.

This is the logic symbol for a 5-bit parallel adder:
![[Pasted image 20211226134630.png | 300]]

# Comparators
![[Pasted image 20211226135157.png | 500]]
![[Pasted image 20211226135730.png | 500]]
*By cascading we mean splitting the numbers into 2 parts and comparing each part by itself, if the result is > < for the last part then all the previous parts are ignored, if its equal then the result will depend on the previous part*
**Example of cascading**
![[Pasted image 20211226140144.png | 500]]

# Decoders
Decoders just detect if a given binary number is in your input
Example for detecting 0011 in the input
![[Pasted image 20211226140614.png | 400]]
![[Pasted image 20211226140832.png | 400]]

More example of decoders:

**binary to decimal**
![[Pasted image 20211226141216.png | 400]]

**BCD to decimal**
![[Pasted image 20211226141307.png | 400]]

# BCD Decoder/Driver
![[Pasted image 20211226143323.png | 500]]

%%dude wtf are all of these examples with very little explanation%%

# Encoders
![[Pasted image 20211226143852.png | 400]]
Example
![[Pasted image 20211226144340.png | 400]]

# Code converters
![[Pasted image 20211226144652.png | 400]]

# Multiplexers
![[Pasted image 20211226144958.png | 400]]

# Demultiplexers
![[Pasted image 20211226145725.png | 400]]

# Parity Generators / Checkers
![[Pasted image 20211226150055.png| 500]]