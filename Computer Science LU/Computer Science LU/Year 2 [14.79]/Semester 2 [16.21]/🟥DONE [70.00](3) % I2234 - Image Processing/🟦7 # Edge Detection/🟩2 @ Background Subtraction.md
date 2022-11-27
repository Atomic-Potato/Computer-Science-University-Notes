This technique is used to detect moving objects. It allows to separate foreground objects from the background.
The idea is to subtract the current frame from a reference frame.

![[Pasted image 20220727231547.png | 200]]
![[Pasted image 20220727231550.png | 200]]
![[Pasted image 20220727231554.png | 200]]

# Technique
- Convert frames of same size to gray.
- Subtract frames.
- Convert the resulting gray image to a binary image using a `threshold t.`

# Morphological Operations
The difference between the current frame and the reference frame may include some errors due to threshold inaccuracy, to luminosity and wind changes, for example.

Morphological operations can be used, in complementary to the thresholding technique, to enhance the visibility of the resulting binary image.

We have 4 types:
- `Erosion:` remove pixels from object boundaries.
- `Dilation:` add pixels to object boundaries.
- `Opening:` an erosion followed by a dilation.
- `Closing:` a dilation followed by an erosion.
![[Pasted image 20220727231900.png | 300]]
![[Pasted image 20220727231911.png | 200]]

## Structuring element
This section we will use `morphological operations` to structure the resulting image after background subtraction

A structuring element is a binary matrix, for example:
![[Pasted image 20220727232337.png | 150]]
or
![[Pasted image 20220727232458.png | 150]]

The center pixel of the structuring element is called origin.

### Applying the Structuring element
Consider the structuring element S.
Move S over B, placing origin at each pixel.

`S:`
![[Pasted image 20220727232600.png | 100]]

`B:`
![[Pasted image 20220727232629.png | 150]]

- Using `Diliation:`
If at least one 1-pixel matches any entries from `S` after overlapping it with `B` then the corresponding pixel is set to 1. Otherwise 0.
![[Pasted image 20220727232847.png | 100]]
- Using `Erosion:`
If all 1-pixels match then the corresponding pixel is set to 1. Otherwise 0.
![[Pasted image 20220727232906.png | 100]]

**`NOTE:`** note that here that if we update a pixel we dont compare the new matrix with the structuring element but we only compare it with the original, so you have to make a copy of the matrix of which you make the changes to