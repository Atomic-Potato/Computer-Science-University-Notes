# If statements
```matlab
if condition1
	instruction1;
	instruction2;
else if condition2
	instruction3;
else
	instruction4;
end
```
`comparison opperators work like in the C languages i think`

# For loops
```matlab
for index=range
	instruction1;
	instruction2;
end
```
**range** has one of the following forms:
- `InitialValue : EndValue` – increment the index variable from **InitialValue** to **EndValue** by 1
- `InitialValue : step : EndValue` – increment index by the step value on each iteration or decrements index when step is negative

*Examples:*
![[Pasted image 20220625232210.png]]

# Read / Write image
```matlab
%Read image
M=imread(‘\Location\filename.format’)

%Get the image size:
s=size(M)

%Get the number of dimensions:
d=ndims(M)

%Get information about M:
whos M

%Convert rgb image to gray image:
Mg=rgb2gray(M)

%Write an image:
Imwrite(Mg, ‘\Location\filename.format’)
```

# Intensity histogram
A histogram is a graph that represents the number of pixels of each intensity value.
In gray scale system, the histogram displays 256 different intensity levels. (In RGB i think you would get 3 histograms)
![[Pasted image 20220625232511.png|450]]

```matlab
Intensity=0:255;
M=imread('image path’);

% Create 1×256 matrix (row vector) filled with 0's
Nb_Of_Pixels=zeros(1,256);

%loop over the matrix and just increment by 1 the array deppending on the cell number in the image
for i=1:size(M,1)
	for j=1:size(M,2)
		Nb_Of_Pixels(M(i,j)+1)=Nb_Of_Pixels(M(i,j)+1)+1;
	end
end

% Plot the result / shows the image of the histogram
plot(Intensity, Nb_Of_Pixels);
```

## imhist
basically does automatically what we did above
This function takes one value as input and returns one or two values as output.

Syntax:
```matlab
[Number_of_pixels, Intensity] = imhist (M)

%Or

Number_of_pixels= imhist (M);
Intensity=0:255;
```

# Binarization
Converting a grayscale image into a binary / pure black and white image
The basic method is having a threshold in the grayscale to decide what value is back and what value is white
![[Pasted image 20220625233350.png]]
- Display the histogram of the image.
- Choose `threshold t` that separates object from background.
![[Pasted image 20220625233446.png | 400]]

*Example:*
```matlab
M=imread('C:\Users\HP\Desktop\Test\Photographer.png');

%Solution 1:
N=logical(M);   % convert M to binary image (0 -> 0, positive values -> 1)
				% Also it converts the image from uint8 to logical
for i=1:size(M,1)
	for j=1:size(M,2)
		if M(i,j)>=75 %75 is the threshold
			N(i,j)=1;
		else
			N(i,j)=0;
		end
	end
end

imshow(N)

%Solution 2:
N=M>=75; %Here it gets automatically converted from uint8 to logical
Imshow(N);
```

# Equalization
Increases the global contrast of an image by assigning equal number of pixels to all intensity values.
![[Pasted image 20220626131505.png]]
![[Pasted image 20220626131509.png]]
![[Pasted image 20220626131513.png]]
![[Pasted image 20220626131516.png]]