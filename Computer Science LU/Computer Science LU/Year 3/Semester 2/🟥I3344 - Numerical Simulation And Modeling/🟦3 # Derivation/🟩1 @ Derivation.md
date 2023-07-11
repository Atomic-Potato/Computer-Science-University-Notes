# What we doin
The whole point of this chapter is that we are estimating the values of a function, and not the function expression itself. And we gonna do dat using tangents.

To draw a line we either need:
- 2 points
- or a slope function and one point on the line

Now in our case we will have the derivative of the original unknown function which gives us the slope function, and we will have the starting point. 
Then we will iterate using what we have to approximate the values of the original function.

> ==**NOTE:**== i dont think we have the derivative of the original because we can simply integrate back, but my point is we have this derived function somehow and i cant bother explaining, we all here just cuz we wanna pass dis subject kek


# Euler's Method
![[Pasted image 20230623225421.png]]

- $h$ is the step, that is how many points are we gonna estimate before reaching our approximate target. The more steps we have, the more accurate our approximation is.
- $f(t_{k}, x_{x})$ is the function we are given
- $x_{k}$ is the previous estimation result. *(At k=0 it is the starting point.)*

# Quadratic Taylor Method
It's basically the same as [[#Euler's Method]] but we just add the derivative of the given function multiplied by the step squared over 2
![[Pasted image 20230623225951.png]]

> ==**NOTE:**== this is only the quadratic version, we can have more orders, and i guess you can already see the pattern, so adding more orders should not be an issue.

*Example:*
![[Pasted image 20230623230240.png]]
![[Pasted image 20230709151840.png]]
# Euler's Midpoint Method
![[Pasted image 20230623230452.png]]

# Runge - Kutta Method
![[Pasted image 20230623230548.png]]