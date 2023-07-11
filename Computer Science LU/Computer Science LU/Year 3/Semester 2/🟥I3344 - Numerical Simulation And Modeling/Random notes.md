#Experience ig
![[Pasted image 20230623142752.png]]
In this exercise, the first equation gets us the number of tables and the other ones the number of people, and that is completely fine, as long as they contain the variables we want, and i dont think it has to be all of them.

- Add a reminder of how to derivate and integrate

# Other
## Reading input in java
```java
// Create a Scanner object to read input 
Scanner scanner = new Scanner(System.in); 
// Read a line of input 
String name = scanner.nextLine(); 
int leInt = scanner.nextInt(); 
int leDouble = scanner.nextDouble(); 
// Close the Scanner object 
scanner.close();
```

## Determinant
*We're using the 4x4 matrix*
1. pick the row with the most zeros, which will reduce the amount of work to do
2. now each entry in that row will be the coefficient, and then multiplied by the leftover matrix
	1. this leftover matrix is filled with entries that do not exist on the row and the column of the coefficient
![[Pasted image 20230709173949.png]]
3. Repeat step 2 for all the entries in the matrix
4. repeat step 2 and 3 for all the leftover matrices
5. Calculate the determinant of the 2 by 2 matrices by multiplying the elements on the left diagonal - the multiple of the elements on the right diagonal
   ![[Pasted image 20230709174410.png|200]]
   ![[Pasted image 20230709174431.png|300]]


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