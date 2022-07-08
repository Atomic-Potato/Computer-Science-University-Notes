- `Color filtering:` is a technique used to modify colors of pixels according to a specific threshold.
- `Noise filtering:` is a technique used to enhance the image visibility.

# Color filtering #1
Given an RGB or Gray image, pixels whose colors belong to specific ranges are modified.

*Example: convert pixels with R-value <120 or G-value >180 to blue [0, 0, 255].*
![[Pasted image 20220708194520.png]]
![[Pasted image 20220708194525.png]]
```matlab
in=im;
v=[0,0,255];

for i=1:size(im,1)
	for j=1:size(im,2)
		if im(i,j,1)<120 || im(i,j,2)>180
			in(i,j,:)=v;
		end
	end
end
```