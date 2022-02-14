When you specify a placeholder for a value in an `fstring`, Python assumes the value should be displayed as a string unless you specify another type. In some cases, the type is required.

# Manipulating Output of strings
Integers `f'{10:d}'`
Chars `f'{65:c} {97:c}'` Output: 'A a'
String `f'{"hello":s} {7}'` Output: 'hello 7' 

## Floating-Point  and decimal values
You can specify the size of a decimal like so with the the `decimal` library
```python
from decimal import Decimal

f'{Decimal("10000000000000000000000000.0"):.3f}'
#'10000000000000000000000000.000'
f'{Decimal("10000000000000000000000000.0"):.3e}'
#'1.000e+25'
```

##  Field Widths and Alignment
![[Pasted image 20220129163755.png | 150]]

## Explicitly Specifying Left and Right Alignment in a Field
![[Pasted image 20220129163833.png | 150]]

## Centering a Value in a Field
![[Pasted image 20220129163935.png | 150]]

## Formatting Positive Numbers with Signs
![[Pasted image 20220129164012.png | 150]]
## Using a Space Where a + Sign Would Appear in a Positive Value
![[Pasted image 20220129164046.png | 250]]

## Grouping Digits
![[Pasted image 20220129164114.png | 150]]

# The Good ol' `format` Method
`fstring` was introduced in python 3.6 so `format` was used before it
You call method format on a format string containing curly brace ({}) placeholders, possibly with format specifiers.

```python
'{:.2f}'.format(17.489) # '17.49'
```

A format string may contain multiple placeholders, in which case the format method’s arguments correspond to the placeholders from left to right.

```python
'{} {}'.format('Amanda', 'Cyan') #'Amanda Cyan'

'{0} {0} {1}'.format('Happy', 'Birthday') #'Happy Happy Birthday'

'{first} {last}'.format(first='Amanda', last='Gray') #'Amanda Gray'
```

# Strings Manipulation
You can concatenate strings using `+`, like string1 + string2, and repeat the string multiple times if you multiple it by some value, `'potato'*5` = potatopotatopotatopotatopotato

`string.strip()` will delete any `\t`, `\n` from the string plus any white space before and after the first and last char in the string
`string.lstrip()` will only do it on the left
`string.rstrip()` will only do it on the right

`Note: you can compare strings with comparision ops, works like you would expect`

`string.count('potato')` counts the num of occurrences of a string in another 

`string.index('potato')` finds the index of `potato` in the string, the index is the position of the first character
`string.rindex('potato')` does the same as above but in reverse

you can check if a string is in another or not using `in` and `not in`

`string.startswith('x')` does what it says
`string.ednswith('x')` says what it does

`string.replace('x', 'y')` replaces every occurrence of x with y

`string.split('x', 69)` you already know, the second argument does the splitting until 69

`'potato'.join(list_name)` concatenates all the strings in the list separated by `potato`

`string_with_\n_or_going_down_line.splitlines()` makes an array of strings at each line break, if you put in `True` as an argument it will include the `\n`

`string.isdigit()` returns true if all of the characters are digits
`string.isalnum` returns true if all of the characters are either letters or strings

**Raw strings**
you can include any thing in the string, like a `\n`, and it wont do its task if you put `r` before the string
```python
potato_string = r'May\nThe..' #May\nThe
```

## String Methods `partition` and `rpartition`
String method `partition` splits a string into a tuple of three strings based on the method’s separator argument. The three strings are
* the part of the original string before the separator,
* the separator itself, and
* the part of the string after the separator.

This might be useful for splitting more complex strings.

```python
'Amanda: 89, 97, 92'.partition(': ')
#('Amanda', ': ', '89, 97, 92')

#rpartition does the same thing but in the opposite way
```

