# A struct
A struct is basically an array of variables with different types
How to declare a srtuct:
```c
//Test
srtuct structName
{
	variableType varName;
	varType varName;
	//...
}structVariables;

// you can have an anonymous struct
struct 
{
	bool bigPP;
}a, b, c;

// if you leave the struct variables empty you can declare new ones like so
struct structName variableName;
```

The look of a struct in memory:
![[The look of a struct in memeory.jpg | 500]]

How to initialize the values of a struct:
![[Ways of initializing a struct.jpg | 400]]

aaaand you already know how the dot operator works

# typedef
typedef basically just gives variable types new names
```c
typedef existingType newTypeName;
```

**How to use typedef with structs**
```c
typedef struct structName
{
	//...
}newStructName;

struct newStructName structVariable;

// or if you write the same name
// you wont have to use the keyword struct to initialize
typedef struct structName
{
	//...
}structName;

structName structVariable;

//And with anonymous structs, which you can give a name like so
typedef struct
{
	//...
}structName;
```
`Note that this means you cant declare variables when declaring the struct with typedef, and that doesnt mean that the structName given instead of the varNames means the structName is a variable`

![[great uses of typedef.jpg | 600]]

# sizeof
`sizeof(varType)` will return an `unsigned int` equal to the size of the variable type in bits in the memory. You can also put a var name.

==Note that the size of a struct is >= the sum of sizeof its fields==


# Struct assignment
You can assign the values of struct variable a to the values of a sturct b simply like so:
```c++
a = b;
```


# The Arrow ==->== operator
Basically instead of de-referencing a pointer using `*pointer`, we can use the `arrow ->` operator instead like in this example
```c
*pointer.varStruct = something
// to
pointer->varStruct = something
```
Pretty useful in nested pointers / structs