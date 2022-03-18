# The difference between while and for loops
1. The `while` statement repeats an action (or a group of actions) as long as a
condition remains True.
2. The `for` statement repeats an action (or a group of actions) for every item in a
sequence of items.

# If statements
you can assign values to a variable using if else statements like this
```python
grade = 69
result = ('Passed' if grade >= 60 else 'Failed')
```

# For statements
```python
for character in 'Programming':
	print(character)
#Prints
#P 
#r 
#o 
...
```
Theres an `end` argument for the print statement that determines what the `print()` function ends with. Note that by default `print()` ends with `\n`
Ex:
```python
for character in 'Programming':
	print(character, end='  ')
#Prints
#P r o g r a m m i n g
```
Another argument for `print()` is the seperate `sep` argument, it just seperates every argument with what you give the `sep` argument
Ex:
```python
print(10, 20, 30, sep=', ')
#Prints
#10, 20, 30
```

# Iterables, Lists and Iterators
- Lists
The sequence to the right of the for statement’s in keyword must be an iterable—that is, an object from which the for statement can take one item at a time until no more items remain. Python has other iterable sequence types besides strings. One of the most common is a list, which is a commaseparated collection of items enclosed in square brackets ([ and ]).
Ex:
```python
total = 0
for number in [2, -3, 0, 17, 9]:
	total = total + number
# total = 25
```

The `range()` function, best to explain it with an example:
```python
for counter in range(10):
	print(counter, end=' ')
# prints
# 0 1 2 3 4 5 6 7 8 9
```

# Formated strings
```python
print(f'Class average is {average}')
#Prints
#Class average is 81.7
```
We used the following simple fstring (short for formatted string) to format this script’s result by inserting the value of average into a string. The letter f before the string’s opening quote indicates it’s an fstring. You specify where to insert values by using placeholders delimited by curly braces ({ and }).
In an `fstring`, you can optionally follow a replacement text expression with a colon (:) and a format specifier that describes how to format the replacement text. The format specifier .2f formats the average as a floating point number (f) with two digits to the right of the decimal point (.2).
```python
print(f'Class average is {average:.2f}')
```

# More about range()
The 2 arguments version `range(x, y)` produces a sequence of consecutive integers from its first argument’s value up to, but not including, the second argument’s value.

The 3 argument version produces a sequence of integers from its first argument’s value up to, but not including, the second argument’s value, incrementing by the third argument’s value, which is known as the **step**.
```python
for number in range(0, 10, 2):
	print(number, end=' ')
#prints
# 0 2 4 6 8
```
If the third argument is negative, the sequence progresses from the first argument’s value down to, but not including the second argument’s value, decrementing by the third argument’s value.
```python
for number in range(0, 10, -2):
	print(number, end=' ')
#prints
#10 8 6 2
```

# Type decimal for decimal precision
Importing the decimal module %%Library i think%%
```python
from decimal import Decimal

example = Decimal('1000.00')

# You can use the 'example' variable just like any other float or double
```

# break and continue statements
- break: same as c and cs
- continue: Executing a `continue` statement in a `while` or `for` loop skips the remainder of the loop’s suite. In a `while`, the condition is then tested to determine whether the loop should continue executing. In a `for`, the loop processes the next item in the sequence (if any). <label class="ob-comment" title="" style=""> Conclusion <input type="checkbox"> <span style=""> It basically restarts the loop </span></label>

# and, or, not
`and` instead of `&&`
`or` instead of `||`
`not` isntead of `!` but you can still used `!=`

# Mean, Mode, Median
Note: `sum()` to sum the values in a list, `len()` to get the length of a list

The Python Standard Library’s `statistics` module provides functions for calculating the mean, median and mode.
<label class="ob-comment" title="" style=""> What are the Mean/Median/Mode? <input type="checkbox"> <span style=""> Mode: The most repeated value
Mean: Average
Median: The middle number in a sorted, ascending or descending, list of numbers</span></label>
```python
import statistics

grades = [85, 93, 45, 89, 85]

statistics.mean(grades) #79.4
statistics.median(grades) #85
statistics.mode(grades) # 85
sorted(grades) #[45, 85, 85, 89, 93]
```
Note that the `mode` function causes a `StatisticsError` for lists like [85, 93, 45, 89, 85, 93] in which there are two or more “most frequent” values. Such a set of values is said to be imodal.
