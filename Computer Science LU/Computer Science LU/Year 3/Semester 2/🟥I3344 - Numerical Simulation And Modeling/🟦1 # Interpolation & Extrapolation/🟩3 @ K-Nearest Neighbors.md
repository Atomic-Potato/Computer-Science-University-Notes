# What is KNN
K-nearest neighbors algorithm is used for interpolation/extrapolation based on the concept of clustering.

When estimating a point we check what are the closest neighbors to it in the dataset we have, and calculate the $\hat{y}$ based on that.

> Example:
> ![[Pasted image 20230620161354.png]]
> ![[Pasted image 20230620161512.png]]

**KNN can be applied for any number of dimensions / unknown variables**

# Algorithm
![[Pasted image 20230620161629.png]]

> **==NOTE:==** When choosing K its best to use $K = \sqrt{ n }$ if its not given, since theres a sweet spot for K 
> ![[Pasted image 20230620161830.png]]