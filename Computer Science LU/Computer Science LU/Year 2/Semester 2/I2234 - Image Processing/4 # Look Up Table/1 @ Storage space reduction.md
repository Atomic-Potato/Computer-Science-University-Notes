To reduce storage space, RGB image is converted into `indexed image` using `colormap`.

- RGB image ^rgbImage
![[Pasted image 20220704163418.png]]

- Colormap ^colormap
![[Pasted image 20220704163458.png]]

- Indexed image ^iindexedImage
![[Pasted image 20220704163538.png]]

*The size of the RGB image = 9(pixels) \* 3(red, green, blue) = 27 Bytes*
*Size after compression = 12(size of the colormap) + 9 (size of indexed image) = 21 Bytes*

# Convert RGB to indexed image
```matlab
im=imread(‘Location\FileName.Format');

% n is the number of entries in the LUT (look up table / colormap)
[indim, colmap]=rgb2ind(im, n);

% Display the indexed image using LUT
imshow(indim,colmap)
```
If the colormap does not contain a given color (n is exceeded), the corresponding pixel in the indexed image gets the index of the nearest color in the colormap