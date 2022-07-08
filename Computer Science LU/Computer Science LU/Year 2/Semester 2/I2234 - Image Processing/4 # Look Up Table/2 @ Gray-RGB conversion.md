# Conversion
```matlab
im=imread('C:\Users\HP\Desktop\Test\Photographer.png');

im=cat(3, im, im, im);  % create an RGB image using concatenate function
						% The 3 means how many images you want to concatenate
						
indim=rgb2ind(im,3); % create the indexed image without getting the colormap

% Get another image, and take its colors
in=imread('C:\Users\HP\Desktop\Test\Belle.jpg');
[ini, colmap]=rgb2ind(in, 3);
imshow(ini, colmap)

% Display the first image using the colors/colormap of the second image
imshow(indim, colmap)
```

# Creating custom color maps
```matlab
% Colors in matlab map must range from 0 (0) to 1 (255)
R=[1, 0, 0];
G=[0, 1, 0];
B=[0, 0, 1];
MyMap=[R;G;B];

% Display the converted image using the new colormap
imshow(indim, MyMap)
```