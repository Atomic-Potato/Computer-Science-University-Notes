![[Pasted image 20220727230927.png]]

To find the image edges, we look for sudden changes in color intensity on the horizontal, vertical and diagonal

# Prewitt filter
Calculates the difference (derivative) of pixel intensities.
Use 3×3 convolution mask.
Prewitt operator generates two masks, one for detecting edges in horizontal direction and other for vertical direction.

## Horizontal 
![[Pasted image 20220727231131.png | 400]]
It computes the difference of above and below pixel intensities of the corresponding pixel.
![[Pasted image 20220727231200.png | 400]]

## Vertical
![[Pasted image 20220727231220.png | 400]]
It computes the difference of left and right pixel intensities of the corresponding pixel.
![[Pasted image 20220727231241.png | 400]]

## Diagonal & Edge detection
The pixel (i,j) takes: $$\large \color{cyan} \sqrt{dx^2+dy^2}$$
Then the pixel (i,j) in the output image is set to 1 if $\large \color{cyan} \sqrt{dx^2+dy^2}$ > threshold Else it is set to 0.