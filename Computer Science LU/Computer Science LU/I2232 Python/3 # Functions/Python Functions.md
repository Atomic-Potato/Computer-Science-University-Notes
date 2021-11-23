# Defining functions
```python
def function_name(parameter1, parameter2):
	"""Optional docstring.""" #its just used to briefly explain the use of the function
	# Your code
	return value # aslo optional
```
By convention a function name starts lowercase and words are separated with an underscore `_`.

`IMPORTANT`
Executing a `return` statement without an expression terminates the function and implicitly returns the value `None` to the caller. The Python documentation states that `None` represents the absence of a value. `None` evaluates to False in conditions.
When there’s no `return` statement in a function, it implicitly returns the value `None` after executing the last statement in the function’s block.

How to access a `docstring` ?
```python
#Via IPython's help mechanism

def function():
	""""Docstring."""
	return

function?
# output:
# Docstring.

function??
#output:
# def function():
#	""""Docstring."""
#	return 
```

# Random Number Generation
Python random generation function is with the `random` module.
```python
import random

for number in range(10):
	print(random.randrange(1,7), end="")
#output
#random 10 digit number only inluding 1 to 6
```
The `randrange()` function generates an integer from the first argument value up to, but not including, the second argument value.
Cool fact: each number in randrange() has an equal chance to be chosen.

**Seeding a random number generator.**
Shortened explanation:
We can see the `randrange()` function so it would always give the same output every time we run the program. But running it again will give a different result.
```python
random.seed(32) #32 is an example
print(randrange(1, 7))
#output
#always same output if you run the program again and again, i think it will be 1 here

print(randrange(1, 7))
#output:
#different from the above

random.seed(32)
print(randrange(1, 7))
#output:
#same output as the first one
```

Full explanation
```
Function randrange actually generates pseudorandom numbers, based on an internal calculation that begins with a numeric value known as a seed. Repeatedly calling randrange produces a sequence of numbers that appear to be random, because each time you start a new interactive session or execute a script that uses the random module’s functions, Python internally uses a different seed value. When you’re debugging logic errors in programs that use randomly generated data, it can be helpful to use the same sequence of random numbers until you’ve eliminated the logic errors, before testing the program with other values. To do this, you can use the random module’s seed function to seed the randomnumber generator yourself—this forces randrange to begin calculating its pseudorandom number sequence from the seed you specify.

According to the documentation, Python bases the seed value on the system clock or an operatingsystemdependent randomness source. For applications requiring secure random numbers, such as cryptography, the documentation recommends using the secrets module, rather than the random module.
```

**Tuples**
Tuples are like lists but they cant be modified. They are pretty useful if you want to return multiple values within a function.
```python
# Decleration
my_tuple = (first_value, second_value) # Parenthesis are not necessary

# Assigning values of the tuple
var1, var2 = my_tuple

# You can also use a tuple directly
print(my_tuple)
```

# `math` Module FUNctions 
```python
import math # MAFFFFFFFF !!!

math.fabs? #idk this is just representing us to the '.' i think thats it
```

# Default Parameters
You can have default values for a function in case the function got called with no arguments.
```python
def rectangle_area(length = 2, width = 3)
	"""I have a big pp"""
	return width * length
	
print(rectangle_area())
# Output:
# 6
```

# Arguments Order
You can pass arguments in any order if you use the parameters keywords when calling the function
```python
# Using above's example
print(rectangle_area(width = 3, length = 2))
# Output:
# 6
```

# Arbitrary Arguments functions
An example of these functions is the `print()` function where you can give it as many arguments as you want as you want.
```python
def arbitrary_args(*args)
	return sum(args)
	
# We pass in a pointer of a list as a parameter for the function, and thats basically it
```
If you want to pass in a list or a tuple, or any kind of iterable, as an argument you have to unpack it first by using `*` like so:
```python
list = [1, 2, 3, 4]
arbitrary_args(*list)
```

# Methods: Functions that belong to Objects
A method is simply a function that you call on an object using the form: `object_name.method_name(arguments)`
Example:
```python
s = "Hello"
s.lower() #Output: 'hello'
s.upper() #Output: 'HELLO'
s #Output: 'Hello'
```

# Scope
Each identifier has a scope that determines where you can use it in your program. For that portion of the program, the identifier is said to be “in scope.”

**Local Scope**
A local variable’s identifier has local scope. It’s “in scope” only from its definition to the end of the function’s block. It “goes out of scope” when the function returns to its caller. So, a local variable can be used only inside the function that defines it.

**Global Scope**
Identifiers defined outside any function (or class) have global scope—these may include functions, variables and classes. Variables with global scope are known as global variables. Identifiers with global scope can be used in a `.py` file or interactive session anywhere after they’re defined.

### Modifying a global variable within a function
```python
x = 69

def function()
	x = 42.0
	print(x) #Output: 42.0
	
print(x) #Output: 69
```
To modify a global variable in a function’s block, you must use a `global statement` to declare that the variable is defined in the global scope:
```python
def modify_global():
	global x; #The semi colon is intentional
	x = 'hello'

print(x) #Output: 'hello'
```

# Blocks VS Suites
<label class="ob-comment" title="" style="">  <input type="checkbox"> <span style=""> A group of individual statements, which make a single code block are called suites in Python. </span> What are Suites?</label>
When you create a variable in a block, it’s local to that block. However, when you create a variable in a control statement’s suite, the variable’s scope depends on where the control statement is defined:
- If the control statement is in the global scope, then any variables defined in the control statement have global scope.
- If the control statement is in a function’s block, then any variables defined in the control statement have local scope.

### `Shadowing functions`
`If you define a variable name with an already existing functio name, then this function will be shadowed and can't be callaed and will throw a "Type Error" when called.`

# `import`: A deeper look
We can import an identifier with `from module_name import identifier` so we dont have to access it with the `.` again.
You can do multiple at once like this example
```python
from math import ceil, floor
```
**Avoid Wildcard imports**
You can import all identifiers defined in a module with a wildcard import of the form `from modulename import *`. This makes all of the module’s identifiers available for use in your code. But this is not recommended. Example why:
```python
e = "hello"
from math import *
print(e)

# Output:
# 2.7182 ....
```

**Abbreviating modules**
Using the keyword `as`:
```python
import statsistics as stats
list = [1, 2, 3, 4]
stats.mean(list)
```

#  Passing Arguments to Functions: A Deeper Look
Though we can’t see an object’s address, we can use the built-in `id function` to obtain a unique int value which identifies only that object while it remains in memory.
You also can prove that the argument and the parameter refer to the same object with Python’s `is` operator, which returns `True` if its two operands have the same identity.
```python
x = 1

def function(number)
	print(number is x)
	return n + 1

function(x)
# Output:
# True
```

**Immutable objects as arguments**
When a function receives as an argument a reference to an immutable (unmodifiable) object—such as an int, float, string or tuple—even though you have direct access to the original object in the caller, you cannot modify the original immutable object’s value.
**Mutable Objects as Arguments**
When a reference to a mutable object like a list is passed to a function, the function can modify the original object in the caller.