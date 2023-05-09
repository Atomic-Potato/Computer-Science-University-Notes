_Next [[🟩4 @ Digital Signature]]_
_Previous [[🟩2 @ Security Services]]_

---

![[Pasted image 20230301095549.png|700]]

# Symmetric Key Cryptography
![[Pasted image 20230301095647.png]]
Bob and Alice share same _(symmetric)_ key Ks

## Simple Encryption Scheme
substitution cipher:  substituting one thing for another
![[Pasted image 20230301095804.png|400]]

## Data Encryption Standard (DES)
DES is a block cipher, which means that it encrypts data in fixed-size blocks of 64 bits at a time. 
It uses a secret key of 56 bits to encrypt and decrypt data. The algorithm uses a series of mathematical operations, including substitution and permutation, to scramble the plaintext into ciphertext, and vice versa.

_For example:_ We here have an initial permutation and  16 identical “rounds” of function application, each using different 48 bits of key. And then the final permutation.
![[Pasted image 20230301100427.png|400]]

## Advanced Encryption Standard (AES)
AES is the successor of DES. Since DES 56 bit key block length has become too short for today's standards and AES uses 128 bit blocks.

_(brute force decryption (try each key) taking less than 1 sec on
DES, takes 149 trillion years for AES)_

## Public Key Cryptography
In PKC, the sender and receiver do not share secret key. 
Theres a **public**  encryption key known to all and a **private**  decryption key known only to receiver.
![[Pasted image 20230301101433.png]]

Requirements:
1. We need $\large K^+_{B}(.)$ and $\large K^-_{B}(.)$ such that:
   $$\large K^-_{B}(K^+_{B}(m))$$
2. given public key $\large K^+_{B}$ , it should be impossible to compute private key $\large K^-_{B}$

---
_Next [[🟩4 @ Digital Signature]]_
_Previous [[🟩2 @ Security Services]]_