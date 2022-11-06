- You can consider in the questions that `and = intersect` and `or = union` 
- Uniform = discrete, else continuous
# Independent & Mutually Exclusive
The difference between mutually exclusive and independent events is: **a mutually exclusive event can simply be defined as a situation when two events cannot occur at same time whereas independent event occurs when one event remains unaffected by the occurrence of the other event**.

So when events are `independent` and they `intersect` we can split them apart in probability because their product will always be less or equal to 1 (P(AB)=P(A)P(B))
And if they `are mutually exclusive` and we want the `union` we of these events we can split them apart in probability because their `sum` will always be less or equal to 1 ( P(A u B) = P(A) + P(B) )
# Some graphs
![[Pasted image 20220323214152.png | 600]]

# Potato series
$$\huge \sum^n_{k=x}k = C^2_n = \frac{n*(n-1)}{2}$$

## **Geometric series**
![[geometric series reminder.jpg | 300]]

## **Macloren series**
![[Pasted image 20220320170932.png | 300]]

## Riemann Series
This series `converges for p>1` and `diverges for p<=1` 
$$\Huge \sum^{\infty}_{k=1} \frac{1}{k^p}$$
## **Telescoping series**
![[Pasted image 20220320172801.png ]]

## **Partial fraction decomposition**
https://youtu.be/QKkdYW77xNI

- Factor the denominator $\huge ax^2+bx+c$
	- find `u and v` such that $\huge u*v=c$ and $\huge u+v=b$
	- then it will get factored into $\huge (\sqrt{a}x+u)(\sqrt{a}x+v)$ 
- Then you get the equation $\huge \frac{num}{(\sqrt{a}x+u)(\sqrt{a}x+v)} = \frac{A}{(\sqrt{a}x+u)} + \frac{B}{(\sqrt{a}x+v)}$ 
- then you multiply both sides with the factored denominator and you give a value to `x` such that it will cancel A or B then you find A or B and then do the same for the other one.

## **Chasles relation**
![[Pasted image 20220320224359.png | 600]]
`If the integral goes below the domain of x then the integral just becomes 0 and if it goes over the domain then it becomes 1`

tabular method `(it seems to be i forgot to write it down)`
![[Pasted image 20220425185051.png]]
## Chain rule
$\huge f(g(x))' = f'(g(x))g'(x)$

## Derivative rules
![[derivative rules.JPG.jpg]]

## Integration rules
![[integral rules.JPG.jpg]]

## General reminders
- $\huge u^x = e^xln(u)$ 
- $\huge \int e^{-ax} = -\frac{1}{a}e^{-ax}$  
- $\huge \frac{d}{dx}e^{u(x)} = u(x)'e^{u(x)}$
- $\huge\color{} \int \frac{1}{u(x)} \, dx = \ln(u(x))$
- Remember the strategy of adding and reducing one (or something similar) to split a hard integral into two parts

---
![[Pasted image 20221029103409.png]]

- If you have Var(g(x)), dont split g(x) using the variance but with the mean
- I think its fine to have a negative value in the variance and covariance
- $\Large \color{} (a-b)^3 = a^3 - 3a^2b+3ab^2-b^3$