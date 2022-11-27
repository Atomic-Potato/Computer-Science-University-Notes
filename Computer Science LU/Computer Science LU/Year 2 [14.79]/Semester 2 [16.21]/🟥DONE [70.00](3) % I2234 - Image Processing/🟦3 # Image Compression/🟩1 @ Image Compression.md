Image compression aims to reduce the number of bytes required to store an image.

There are two types of compression:
- `Lossless`: The size of an image is reduced without any quality loss. The compression is `reversible`. *Example: PNG.*
- `Lossy`: some data from the original image is lost. The compression process is `irreversible`. *Example: JPEG.*
![[Pasted image 20220626131840.png | 600]]

How to draw the above histogram
```matlab
im=imread('AE.jpg');
[Nop,Int]=imhist(im);
plot(Int,Nop,'r','linewidth',8) % Plot the corresponding histogram in red with a linewidth=8
hold on % plot several histograms on top of eachother

imwrite(im,'Pho.png'); % save the original image in png format
imwrite(im,'Pho.jpg'); % save the original image in jpg format
imJ=imread('Pho.jpg'); % Read the jpg-image
[NopJ,IntJ]=imhist(imJ);
plot(IntJ,NopJ,'b','linewidth',8) % Plot the corresponding histogram in blue with a linewidth=8

imP=imread('Pho.png');
[NopP,IntP]=imhist(imP);
plot(IntP,NopP,'g','linewidth',2) % Plot the PNG histogram in green with linewidth=2

legend('Original','JPG', 'PNG') % Give legends
```

# PNG format
The PNG format uses the `Deflate algorithm` which is a combination of the `Huffman coding` and the `LZ77 algorithm.`

## Huffman coding
**Given a set of redundant symbols, assign to each distinct symbol a minimum number of bits (variable-length encoding) by starting with the most repeated symbol.**

*Example:*
E= {A, B, C, A, C, A, B, B, A}
A: 4 times   -> A: 0
B: 3 times   -> B: 10
C: 2 times   -> C: 11

The size of each character is 1 Byte, so in total we have 9 bytes. But If we use huffman coding we will get roughly around 2 Bytes

### Bit order
Bit codes must be given without confusion in order to facilitate the decoding.

- *Example with confusion:*
E= {A, B, C, A, C, A, B, B, A}
A: 4 times  -> A: 0
B: 3 times  -> B: 1
C: 2 times  -> C: 01
The sequence 01 can be treated as AB or C !
- *Example without confusion:*
E= {A, B, C, A, C, A, B, B, A}
A: 4 times  -> A: 0
B: 3 times  -> B: 10
C: 2 times  -> C: 111
The sequence100111 is treated as BAC.

**`To avoid confusion, a given bit code must not be the prefix(start of another word) of another one.`**

- *Example:*
A: 0
C: 01
The bit code 0 is the prefix of the bit code 01.

The Huffman algorithm allows to generate bit codes without confusion, which uses a Huffman Tree

### Huffman Tree 
Consider a set of symbols.
- `Step1:` Compute the frequency of each distinct symbol i.e. the number of occurrences.
- `Step2:` Each distinct symbol constitutes a leaf node.
- `Step3:` Select the two nodes with the smallest frequencies *(to minimize bit codes)*, then create a parent node. The parent node gets the sum of the two frequencies.
**Repeat the Step 3 until there is only one node (root node).**
- `Verification:` the root node has a frequency equal to the size of the set.

*Example:*
![[Pasted image 20220626154832.png]]
![[Pasted image 20220626154848.png | 500]]

### Decoding using Tree
Start from the first bit and then traverse the tree until a leaf is found. Give the corresponding symbol and then continue until all bits of the given stream are treated.

*Example:*
Decode the sequence 011011010 using the previous tree.
Result: ACACAB

**If you dont reach a leaf then the sequence is just considered incomplete**