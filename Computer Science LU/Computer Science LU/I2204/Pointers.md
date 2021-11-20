# Intro to pointers
<label class="ob-comment" title="" style=""> Note <input type="checkbox"> <span style=""> When we say memory we are reffering to RAM </span></label> 
The computer memory is split into slots of 1 byte and each with its own unique address.
ex: 
![[RAM.jpg]]
When we create a variable it is stored in these slots with an adress, for example an int has the size of 4 bytes and so the computer gives it slots from address 204 to 208 and the address of the int is 204, now pointers are used to manipulate these addresses.



## How to create a pointer
A pointer is just like any variable, it can be created by declearing its type with the same type of the varibale which we want the address of and by putting a `*` behind it and can be assigined a value by doing `pointer = &variable` which will now store the address of the variable.
Heres an example ![[Example of pointers.jpg]]
<label class="ob-comment" title="" style=""> (NOTE) <input type="checkbox"> <span style=""> Note that we can also edit the value of the variable through the pointer by doint *pointer = newValue </span></label>




## Pointer Arithmetics
We can increment a pointer variable but for example if we increment the address of an int which is 204 by 1 it will be 208 because an int is 4 bytes, you can check the size of a variabe by using `sizeof(variable_type)`



## Pointer to pointer
To store the address of another pointer we do as in the following example:
```c
int x = 1;
int* p = &x;
int** q = &p;
int*** r = &q;
```
As you can see if we need to store the address of a pointer of a pointer we add another star, note that you cant store a one star pointer address in a 3 star pointer address.
Another Example:
![[Pointer to pointer example.jpg]]



## Using Pointer in functions as arguments
Example:
```c
//Take this code:

void Increment(int x)
	x++;

void main()
	int a = 10;
	Increment(a);
	print(a);
```
The result of this app will be 10, because the `x` and `a` have different addresses, and so to avoid this problem we can use pointers by doing so:
```c
void Increment(int* p)
	*p++;
```
This is mostly usefull when you want to edit multiple variables instead of just one inside a function.



## Pointers & Arrays
The addresses of each element in the array are consecutive like so:
![[Computer Science LU/I2204/Pictures/The addresses of arrays.jpg]]
So now if we assign a pointer to the address of an element, excepet the final element, then we can increment that pointer and actually know whats the value of `*p` of that pointer.
More things on how we can access the address and values of an array:
```c
int* p = %A[i]; int* b = A + i; //Getting the address, putting only A will give the address of the first element

print(A[i]); print(*(A+i)) //The value of the elemet i
```
<label class="ob-comment" title="" style=""> NOTE <input type="checkbox"> <span style=""> Note that we cant increment the first address of the array by doing `A++`. </span></label>

Arrays as function arguments:
When passing the a function an array as an argument then the function will create a pointer to the first element of the array instead of copying the entire array again.
![[Computer Science LU/I2204/Pictures/Arrays as function arguments.jpg]]
<label class="ob-comment" title="" style=""> NOTE <input type="checkbox"> <span style=""> Note that the function sizeof() wont count the amount of elements in an array but it will take the size of each element and add them up all together, but you can simply count the actual size of elements by dividing by the number of bytes of the type of the array </span></label>


Character arrays:
Arrays and pointers are different types but they can be used in a similar manner
```c
//We can declar a string array and use a pointer to edit the array of chars
char C[7] = "POTATO";
char* Cpointer;

Cpointer = C;

Cpointer[1] = 'B'; //Cpointer[i] is the same as *(Cpointer + i)

printString(C); //this function doesnt exist
//This will now print PBTATO

//We can also declare a string like this
char* C = "BOTATO";
//But this will make it a constant so we can read the elements
//but not modify them during runtime
```


##### Other Notes
-TypeCasting
We can change the type of the pointer by doing `(desired_var*)pointer_name`, for examle:
```c
int a = 10;
int* p = &a;

char* p0 = (char*)p;
```