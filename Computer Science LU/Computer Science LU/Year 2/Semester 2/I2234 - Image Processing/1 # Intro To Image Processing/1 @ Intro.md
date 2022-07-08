What is an image: A matrix of pixels or dots (picture elements) arranged in rows and columns.
# Color systems
- `Gray scale (Black & white):` pixel’s color is represented on 8 bits (1 Byte)
- `RGB (Red, Green, Blue):` pixel’s color is represented on 24 bits (3 bytes)

## Grayscale system
`Gray scale (Black & white):` each pixel has an intensity (brightness) that ranges from 0 (Black) to 255 (White).
![[Pasted image 20220625095407.png | 500]]
![[Pasted image 20220625094127.png | 500]]

## RGB system
Pixel’s color is formed from 3 colors: $\large \color{red}Red$, $\large \color{green}Green$, $\large \color{blue}Blue$. The eye aggregates these 3 colors and perceives the resulting color.
![[Pasted image 20220625094416.png]]
The `brightness` of each color takes value from **0 to 255**. Therefore we can obtain $\large 2^8 × 2^8 × 2^8 = 256 × 256 × 256$ ≅ 16 millions different colors

# Matlab
Is a programming language that contains useful libraries to deal with images. Some syntax:
- Type of variable is not to be defined by the user
- The semicolon ; allows to hide the result
- The percentage symbol % is used to write comment

## Matrix
Declaration of matrix:
```matlab
M=[1, 2, 3 ; 4, 5, 6 ; 7, 8, 9]
% {1st row }{2nd row }{3rd row}
```
- To access the element at the row i and the column j: `M(i, j)`
- To access the the row i: `M(i, :)`
- To access the the column j: `M(:, j)`
`The first index is 1 and not 0 (cringe)`
## Displaying grayscale image
Values of declared matrix are of type **double by default**.
The matrix must be converted from double to **unsigned int 8 bits (0-255)** using:
```matlab
B = uint8(M)
```
To display a matrix image: 
```matlab
imshow(B)
```

*Example:*
```matlab
M=[0,50;150,255];
B=uint8(M);
imshow(B)
```
![[Pasted image 20220625095323.png]]

# Displaying gray range
```matlab
M=[0:255]; % Fills the matrix M with a single row with entries from 0 to 255
B=uint8(M);
imshow(B)
```
![[Pasted image 20220625095537.png]]