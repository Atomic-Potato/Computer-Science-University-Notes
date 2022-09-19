```matlab
function [resized] = Resize(imName)
	im = imread(imName);
	resized = zeros(size(im,1)/3, size(im,2)/3);
	
	imi = 2;
	imj = 2;
	
	for i=1:size(resized,1)
		for j=1:size(resized,2)
			AVG = im(imi-1:imi+1, imj-1,imj+2);
			resized(i,j) = mean(mean(AVG));
			imi = imi + 2;
			imj = imj + 2;
		end
	end
end
```