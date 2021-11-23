## Direct & Indirect Recursion
- Direct if it calls itself directly
- Indirect if it calls another function which would call the first calling function again

# The rule of Recursion
We will use direct recursion here.
In recursion you need a terminating case and a formula that converges to the terminating case.
Take the recursive factorial function for example:
```c++
int Factorial(int number){
	//Terminating case
	if (n == 0)
		return 1;
	//Else
	//The formula that converges to the terminating case
	retunr Factorial(number - 1) * number;
}
```

# Winding and Unwinding
- Winding is the process of each function calling the next function
- Unwinding is each function returning to the function that called it
![[Winding and Unwinding.JPG]]

# Tail Recursion
We differentiate between those 2 because in tail-recursive functions when the compiler reaches the `terminating case` it unwinds directly to the original function instead of going back to each function when unwinding.
<label class="ob-comment" title="" style="">  <input type="checkbox"> <span style=""> As far as i know this happens only in the C compiler </span>NOTE</label>
![[Tail recursion and non tail recursion.JPG]]

If we want to make a non tail-recursive function into a tail one then we use `helper functions`, here's an example:
```c++
#include <stdio.h>

int FactorialHelper(int n, int p)
{
	if(n == 0)
		return 1;
	return FactorialHelper(n - 1, p * n);
}

int Factorial(int n){
	return FactorialHelper(n, 1);
}

int main(){
	Factorial(x);
}
```