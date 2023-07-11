Basically [[🟩2 @ Linear Regression|linear regression]] but with more than 2 variables

![[Pasted image 20230621145810.png|500]]

Prediction of variable y depends on two or more predictors x1, x2, ... , xp
![[Pasted image 20230621150604.png]]


Meaning of coefficients $\beta_{i}$
![[Pasted image 20230621150646.png]]



# Calculating Coefficients
![[Pasted image 20230621150908.png|500]]
![[Pasted image 20230621150953.png|500]]

What youre looking for is the coefficients equation, which is this:
![[Pasted image 20230621151053.png]]

## Example
![[Pasted image 20230709130021.png]]
![[Pasted image 20230709130031.png]]
![[Pasted image 20230709130044.png]]


# Choosing The Predictors
Some predictors affect the prediction value more than others,
some make it more accurate,
and some increase the error

## First Method : *Combination*
![[Pasted image 20230621151209.png]]


## Second Method : *Direct Selection*

In this method we adjust the R^2 depending on how many predictors we have and if they benefit us or nah, this will result in the R^2 becoming like the following:
![[Pasted image 20230621151412.png]]
![[Pasted image 20230621151912.png]]

> `n` : number of samples
> `m` : number of variables
> `p` : number of predictors