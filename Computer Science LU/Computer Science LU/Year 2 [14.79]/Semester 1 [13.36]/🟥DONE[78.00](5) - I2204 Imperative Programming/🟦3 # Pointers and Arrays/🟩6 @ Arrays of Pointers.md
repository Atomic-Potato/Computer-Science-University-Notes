# Multidimensional arrays
In a function parameter list, and because functions can be compiled separately, we must denote all but one dimension of a multiple dimensional array
```c
void function(int t[][SIZE]; int size);
//remember that the first brackets are just a pointer to the start of the array
// the second brackets in an array means its an array of arrays
```
![[what multidimensional arrays actually look like.jpg | 600]]

**how can we fill the above array with one loop**
```c
int t[3][4];
int *p = NULL;
int v;

for(p = *t, v=1; p < *t + size; p++, v++)
	*p = v*2;
```

# Array of Pointer
```c
int *a[3]; // array of 4 pointers
```

If you assign a pointer of a normal array in the array of pointers, the array of pointers will become like a 2D array
![[array of pointers.jpg | 400]]

# Arrays of strings
The problem when declaring an array of strings, we preserve a place in the memory for every string even tho it doesnt need it
```c
char str[120][50];
//declaring an array of 120 strings with 50 chars each
```
To avoid this we can declare an array of pointers containing strings
```c
char *x[] = {"potato", "tater", "tot"};

for(int i=0; i<4; i++)
	puts(x[i]);

printf("%lu\n", sizeof(x)/sizeof(char));
//it will return the size including the '\0' i think
```

# Pointer to Pointer
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