Various types of exceptions can occur when you work with files, including:
* A `FileNotFoundError` occurs if you attempt to open a non-existent file for reading with the `'r'` or `'r+'` modes.
* A `PermissionsError` occurs if you attempt an operation for which you do not have permission. This might occur if you try to open a file that your account is not allowed to access or create a file in a folder where your account does not have permission to write, such as where your computer’s operating system is stored.
* A `ValueError` (with the error message 'I/O operation on closed file.') occurs when you attempt to write to a file that has already been closed.
* Attempting to divide by 0 results in a `ZeroDivisionError`.
* The `int` function raises a `ValueError` if you attempt to convert to an integer a string (like 'hello') that does not represent a number.

# `try` Statements
```python
# dividebyzero.py
"""Simple exception handling example."""
while True:
	# attempt to convert and divide values
	try:
		number1 = int(input('Enter numerator: '))
		number2 = int(input('Enter denominator: '))
		result = number1 / number2
	except ValueError: # tried to convert non-numeric value to int
		print('You must enter two integers\n')
	except ZeroDivisionError: # denominator was 0
		print('Attempted to divide by zero\n')
	else: # executes only if no exceptions occur
		print(f'{number1:.3f} / {number2:.3f} = {result:.3f}')
		break # terminate the loop
```
A `try` statement may have a `finally` clause after any except clauses or the else clause. The `finally` clause is guaranteed to execute.
```python
try:
	print('try suite with no exceptions raised')
except:
	print('this will not execute')
else:
	print('else executes because no exceptions in the try suite')
finally: 
	print('finally always executes')
```

# Explicitly raising and exception 
The simplest form of the raise statement is
`raise ExceptionClassName`
```python
def function1():
	function2()

def function2():
	raise Exception('An exception occurred')

function1()
```

![[Pasted image 20220203191130.png | 600]]

