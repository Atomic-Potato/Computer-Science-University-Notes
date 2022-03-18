### Passing an Entire List to a Function
```python
def modify_elements(items):
	""""Multiplies all element values in items by 2."""
	for i in range(len(items)):
		items[i] *= 2

numbers = [10, 3, 7, 1, 9]
modify_elements(numbers) #[20, 6, 14, 2, 18]
```
`Passing a tuple will give us a TypeError`

The previous traceback shows the two snippets that led to the TypeError. The first is snippet [7]’s function call. The second is snippet [1]’s function definition. Line  numbers precede each snippet’s code. We’ve demonstrated mostly single-line snippets.
When an exception occurs in such a snippet, it’s always preceded by ----> 1, indicating that line 1 (the snippet’s only line) caused the exception. Multiline snippets like the definition of modify_elements show consecutive line numbers starting at 1.
The notation ----> 4 above indicates that the exception occurred in line 4 of modify_elements. No matter how long the traceback is, the last line of code with ----> caused the exception.
![[Pasted image 20220104122511.png | 600]]
