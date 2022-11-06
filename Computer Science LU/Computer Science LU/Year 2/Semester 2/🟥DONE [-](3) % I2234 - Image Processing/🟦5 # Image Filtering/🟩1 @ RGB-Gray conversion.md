There are 3 methods:
- Lightness
- Average
- Luminosity (weighted average)

# Lightness
Averages the highest and lowest colors.
$$\huge g(x,y) = \frac{max [ f(x,y,1), f(x,y,2), f(x,y,3)] + min [ f(x,y,1), f(x,y,2), f(x,y,3) ]}{2}$$
Where `g(x,y)` is the resulting image in gray scale, and `f(x,y,z)` is the RGB image.

Implementation:
```matlab
M=imread('C:\Users\HP\Desktop\Test\Tulips.jpg');
N=M(:, :,1); %Create a grayscale image

for i=1:size(M,1)
	for j=1:size(M,2)
		N(i,j)=(max(max(M(i,j,1), M(i,j,2)), M(i,j,3)) + min(min(M(i,j,1), M(i,j,2)), M(i,j,3))) / 2;
		%Remember that max() and min() only take 2 parameters
	end
end

imshow(N);
```

# Average
Averages the three colors 
$$\huge g(x,y) = \frac{f(x,y,1)+f(x,y,2)+f(x,y,3)}{3}$$
Where `g(x,y)` is the resulting image in gray scale, and `f(x,y,z)` is the RGB image.

Implementation:
```matlab
M=imread('C:\Users\HP\Desktop\Test\Tulips.jpg');
N=M(:,:,1); %Create a grayscale image

for i=1:size(M,1)
	for j=1:size(M,2)
		N(i,j)=(M(i,j,1)+M(i,j,2)+M(i,j,3))/3;
	end
end

imshow(N);
```

# Luminosity (best babe)
Human eyes are more sensitive to $\large \color{green} green$ than other colors. So $\large \color{green} green$ is weighted most heavily.
$$\huge g(x,y) =  0.21 × f(x,y,1) + 0.72 × f(x,y,2) + 0.07 × f(x,y,3)]$$
Implementation:
```matlab
M=imread('C:\Users\HP\Desktop\Test\Tulips.jpg');
N=M(:, :,1);%Create a grayscale image

for i=1:size(M,1)
	for j=1:size(M,2)
		N(i,j)=0.21*M(i,j,1)+0.72*M(i,j,2)+0.07*M(i,j,3);
	end
end

imshow(N);
```