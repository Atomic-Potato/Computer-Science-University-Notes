**Suggested Resources:**
- If you still having trouble > https://youtu.be/9TlHvipP5yA
- Why do we use log > https://youtu.be/M4ubFru2O80
--- 
# How to compare Algorithms
![[Pasted image 20220513232712.png | 700]]

# Asymptotic Analysis
For a given algorithm, we can represent the `worst case` in the form of an expression `f(n)`

- Let a given algorithm be represented in the form of a function $f(n)$
- The upper bound of $f(n)$ is represented by $f(n)=O(g(n))$
	It means that, at larger values of `n`, the upper bound of $f(n)$ is $g(n)$
	- *Example:* if $f(n)=n^4+100n^2+10n+50$ is the given algorithm, then $n^4$ is $g(n)$
	  ![[Pasted image 20220513235422.png]]
- There are no unique $g(n)$

Formally, $\large O(g(n)) = \{f(n): exists \space c >0, \space exists \space n_0\}$ such that $\large 0 \le f(n) \le cg(n), \space ForAll n \ge n_0$
In general, we discard lower values of n.

## Guidelines for asymptotic analysis
The rules in determining the running time of an algorithm:
- each **`STATEMENT`** has a running time of 1
- The running time of a **`LOOP`** is, at most, the running time of the statements inside the loop (`including the tests`) multiplied by the number of iterations
  *Example*
	```c
	for(i=1; i<=n; i++) //executes n times
		m = m+2; //constant c
	//total time = cn = O(n)
	```
- For **`NESTED LOOPS`** analyze form inside out. Total running time is the product of the sized of all loops.
	*Example*
	```c
	for(int i=1; i<=1; i++) //inner loop executed n times
		for(int j=1; j<=n; j++)
			k++; //constant c
	//total time = c*n*n = O(n^2)
	```
- For **`CONSECUTIVE STATEMENTS`** (like 2 for loops after eachother) you simply add the time complexities of each statement	
- For **`IF-ELSE STATEMENTS`** you take the `worst-case` scenario running time: **the test + either the else part (`whichever is larger`)**
  *Example*
	```c
	if(x==0)
		return false;
	else
		for(int i=1; i<n; i++)
			if(x==i)
				return false;
	//total time = c0+c1+(c2+c3)n = O(n)
	```
- For **`LOGARITHMIC COMPLEXITIES`** an algorithm is `O(log n)` if it takes a constant time to cut the problem size by a fraction (usually $\frac{1}{2}$)
	*Example*
	```c
	for(int i=1; i<=n; i=i*2);
	//The value of i is doubling every time.
	//Assume that the loop executes k times. 
	//Thus take the kth step, 2^i = n.
		//Why we chose 2^i as k:
		//if number the itterations (starting from 0) then: 2^(itteration) = i
		//and since we will reach i > n at some point, then it means 2^(itteration where i > n)
		//So i guess he didnt mean here the 'i' but the itteration
	//Taking logarithm on both sides, gives:
	//log(2^i) = log n
	//ilog 2 = log n
	//i = log n (because the default log is of base 2 in CS, but i just found out that if we multiply by 3 we use log_3, it makes sense)
	//total time = O(log n)
	```
- Similarly, the same discussion holds for decreasing sequences as well
	*Example*
	```c
	for(i=n; i<=1; i=i/2);
	```
	*Another example: binary search*

# Calculation notes
![[Pasted image 20220513232851.png | 700]]

![[Pasted image 20220514001529.png | 250]]

### Commonly used logarithms and summations
![[Pasted image 20220514004221.png | 500]]
![[Pasted image 20220514004236.png | 500]]

# Strategies
- Add a second reversed loop, and add their sum then devide by 2 to remove that extra loop