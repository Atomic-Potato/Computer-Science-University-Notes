![[Computer Science LU/Year 2/Semester 1/DONE[35.00] - S2250 Stats/Chapter 2/Exercises/Pictures/ex 4.jpg]]

# Ex 1
- (A)
$$26*26*10*8*9$$
- (B)
$$\frac{26!}{(26-2)!}*\frac{10!}{(10-3)!}*5!$$
- (C)
$$P = \frac{5!*4!}{9!}$$
- (D)
$$2^4+2^5-2^3$$
- (E)
When even: $$26^\frac{n}{2}$$
When odd: $$26\frac{n+1}{2}$$
- (F)
$$C^2_{20}$$
- (G)
$$\frac{6!}{3!*3!}*C^3_7$$

# EX 6
$$P(A\cap B) = P(B|A)*P(A)$$
$$= \frac{(C^4_9)*(C^2_3)}{C^6_{12}} * \frac{1}{6}$$
$$or$$
$$\frac{3}{12}*\frac{2}{11}*\frac{9}{10}*\frac{8}{9}*\frac{7}{8}*\frac{6}{7}*\frac{6!}{4!*2!}$$
`Further explanation: The event A is the event when A is the 7th picked pc and is defective, while the event A intersect B is the event where the event A happens AND the event B happens`

# EX 7
- a, without replacement
$$P(A wins) = P(R) + P(BBR) + P(BBBBR) + P(BBBBBBR)$$
$$P(R) = \frac{3}{10}$$
$$P(BBR) = \frac{C^2_7}{C^2_{10}} * \frac{3}{8}$$
$$P(BBBBR) = \frac{C^4_7}{C^4_{10}}*\frac{3}{6}$$
$$P(BBBBBBR) = \frac{C^6_7}{C^6_{10}}*\frac{3}{4}$$
`um i took a pic of it`
- b, what if there was replacement?
{A wins} = {R, BBR, BBBBR, ...}
P(A) = P(R) + P(BBR) ...
=$\frac{3}{10} + \frac{7}{10}*\frac{7}{10}*\frac{3}{10}...$
=$\frac{3}{10}*sum((\frac{7}{10}^{2n}, \space from \space n=0 \space to \space infinity)$

# EX 9
$$P((\overline{A} \cup \overline{B})\cap C) = P(\overline{A} \cup \overline{B}) *P(C)$$
$$P(\overline{A} \cup \overline{B}) = P(\overline{A})+P(\overline B) - P(\overline A)*P(\overline B) = \frac{5}{6}$$
# EXTRA
## Ex1 
![[ex1.jpg | 600]]
$$P(A) = P(HTTHH) + P(THTHH) + P(TTTHH) = \frac{3}{2^5}$$

## Ex2
![[Ex 2.jpg | 600]]
$$P = \frac{1}{7}$$

## Ex3
![[Pasted image 20220317194742.png | 600]]

$$P(A|\overline{B}) = \frac{P(A) - P(B)P(A|B)}{1-P(B)} = \frac{3}{8}$$

## Ex4
![[Ex4.jpg | 600]]
![[Ex 3 solution.jpg | 600]]

## Ex 5
![[ex ex5.jpg | 600]]
`a` Find the probability that the system function
- Let S = {event the system functions}, and A = {component A works} (resp. B,C and D)
The probability that the system functions is
$$p = P(A \cap B \cap (C \cup D))$$
$$= P(A)P(B)P(C \cup D)$$
$$P(A)P(B)[P(C)+P(D)-P(C)P(D)] = 0.7776$$
$$or \space S = (ABCD) \cup (ABC\overline{D}) \cup (AB\overline{C}D)$$

`b` Find the probability that component C is not working given that the system functions
$$P(\overline C | S) = \frac{P(\overline C \cap S)}{P(S)} = \frac{P(AB\overline C D)}{P(S)} = 0.1666$$

## Ex 6
![[ex ex6.jpg | 600]]
$$p = P(C_1C_2C_3) = (1-p)^3 => p = 0.034$$

## Ex 7
![[ex ex7 1.jpg | 600]]
![[Pasted image 20220317204517.png | 600]]
![[extra ex 7 solution.jpg | 600]]

## Ex 8
![[ex ex8.jpg  | 600]]
**standard way**
A = {sum is 5}
B = {sum is 7}
C = {sum is neither 5 nor 7}
$$p = P(A)+ P(CA) + P(CCA)...$$
$$= \frac{4}{36} + \frac{26}{36}*\frac{4}{36} + (\frac{26}{36})^2*\frac{4}{36}$$
$$ = \frac{4}{36}\sum^\infty_{n=0}(\frac{26}{36})^n = \frac{4}{10}$$

**other solution**
look in the damn pdf im lazy