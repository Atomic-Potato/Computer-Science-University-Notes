# Arithmetics
**Multiplication**
```python
7 * 4
```

**Exponentiation**
```python
2 ** 10
```

**True division** (/) 
Divides a numerator by a denominator and yields a floating point number with a decimal point.

**Floor division** (//) 
Divides a numerator by a denominator, yielding the highest integer that’s not greater than the result. Python truncates (discards) the frational part.

**Operator precedence rules**
```
1.Expressions in parentheses evaluate first.

2.Exponentiation operations evaluate next. If an expression contains several exponentiation operations, Python applies them from right to left.

3.Multiplication, division and modulus operations evaluate next. If an expressio contains several multiplication, truedivision, floor division and modulus operations, Python applies them from left to right. Multiplication, division and modulus are “on the same level of precedence.”

4.Addition and subtraction operations evaluate last. If an expression contains sveral addition and subtraction operations, Python applies them from left to right.
Addition and subtraction also have the same level of precedence.
```

# Function print and an Intro to Single-and-Double-Quoted Strings
**Printing**
- Its just `print('string')` 
<label class="ob-comment" title="" style=""> (COMMENT) <input type="checkbox"> <span style=""> Both single quotes and double quotes work </span></label>
- You dont need a plus sign like in `cs` to print multiple thing, you can just use commas like this example `print('Welcome', 'to', 'Python!')`
- Use `\n` to go to a new line
- We can write a print statement on multiple lines by putting a `\` at the end of each line, for example
```python
print('this is a longer string, so we \
split it over two lines')
```

# Triple quoted stings
Triple quoted strings begin and end with three double quotes (""") or three single quotes ('''). The Style Guide for Python Code recommends three double quotes ("""). Use these to create: multiline strings, strings containing single or double quotes and docstrings, which are the recommended way to document the purposes of certain program components.
Example: 
`print("""Display "hi" and 'bye' in quotes""")` 
will display: `Display "hi" and 'bye' in quotes`

If you store a tripple quoted string in a variable with line breaks it will be printed with line breaks, for example:
```python
triple_quoted_string = """This is a triple-quoted
string that spans two lines"""

print(triple_quoted_string)

## will print
## This is a triple-quoted
## string that spans two lines
```

# Input from user
We use the built in function `input()` , example:
```python
name = input("Your name ?: ")
```

To get an integer from input we use the function `int()`
Examples
```python
value = int(input("enter a number"))

## or

value2 = input("enter a number")

value2 = int(value2)
```
Side note: we can use `int(6.9)` to round up numbers, `int(6.9) = 6`

# if statements
```python
if element OPERATOR element:
	function()
```
You can also chain comparisons like so:
```python
x = 2

if 1 <= x <= 3:
	print("big PP")
```

# Dynamic typing 
Python uses dynamic typing—it determines the type of the object a variable refers to while executing your code. We can show this by rebinding the variable x to different objects and checking their types. EX:
```python
x = 1
type(x) #prints int
x = 6.9 
type(x) #prints float
x = "botato"
type(x) #prints str
```

# Intro to Data Science: Basic Descriptive Statistics
- You can determine the min and max between a given set of numbers with the built in function `min(num1, num2, num3, ...)` and `max(num1, num2, num3, ...)`