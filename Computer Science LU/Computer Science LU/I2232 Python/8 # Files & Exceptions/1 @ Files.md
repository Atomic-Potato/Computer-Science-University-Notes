When a Python program begins execution, it creates three standard file objects:
- `sys.stdin`—the standard input file object.
* `sys.stdout`—the standard output file object.
* `sys.stderr`—the standard error file object.

# Text-file processing
## The `with` statement and the built-in function `open`
* acquires a resource (in this case, the file object for accounts.txt) and assigns its corresponding object to a variable (accounts in this example)
* allows the application to use the resource via that variable
* calls the resource object’s close method to release the resource when program control reaches the end of the with statement’s suite.

The builtin `open` function opens the file accounts.txt and associates it with a file object. The mode argument specifies the `fileopen` mode, indicating whether to open a file for reading from the file, for writing to the file or both. 
The mode `'w'` opens the file for writing, creating the file if it does not exist. If you do not specify a path to the file, Python creates it in the current folder. Be careful—opening a file for writing deletes all the existing data in the file. By convention, the .txt file extension indicates a plain text file.

```python
with open('accounts.txt', mode='w') as accounts:
	accounts.write('100 Jones 24.98\n')
	accounts.write('500 Rich 224.62\n')

# macOS/Linux Users: View file contents
!cat accounts.txt

# Windows Users: View file contents
!more accounts.txt
```

## Reading Data from a text file
```python
with open('accounts.txt', mode='r') as accounts:
	print(f'{"Account":<10}{"Name":<10}{"Balance":>10}')
	for record in accounts:
		account, name, balance = record.split()
		print(f'{account:<10}{name:<10}{balance:>10}')
```

`readlines:` the file object’s `readlines` method also can be used to read an entire text file. The method returns each line as a string in a list of strings.

While reading through a file, the system maintains a `fileposition` pointer representing the location of the next character to read. 
Sometimes it’s necessary to process a file sequentially from the beginning several times during a program’s execution. 
Each time, you must reposition the `fileposition` pointer to the beginning of the file, which you can do either by closing and reopening the file, or by calling the file object’s seek method, as in `file_object.seek(0)`

## Updating text files
We cannot simply overwrite elements in a file

```python
accounts = open('accounts.txt', 'r')
temp_file = open('temp_file.txt', 'w')

with accounts, temp_file:
	for record in accounts:
	account, name, balance = record.split()
	if account != '300':
		temp_file.write(record)
	else:
		new_record = ' '.join([account, 'Williams', balance])
		temp_file.write(new_record + '\n')
```

**`os` module file processing functions**
```python
import os

os.remove('accounts.txt')
os.rename('temp_file.txt', 'accounts.txt')
```

#  Serialization with JSON (JavaScript Object Notation)
JSON objects are similar to Python dictionaries. Each JSON object contains a comma separated list of property names and values, in curly braces:
```python
{"account": 100, "name": "Jones", "balance": 24.98}
```
JSON also supports arrays which, like Python lists, are comma separated values in square brackets. 
For example, the following is an acceptable JSON array of numbers:
```python
[100, 200, 300]
```
Values in JSON objects and arrays can be:
* strings in double quotes (like "Jones"),
*  numbers (like 100 or 24.98),
* JSON Boolean values (represented as true or false in JSON),
* null (to represent no value, like None in Python),
* arrays (like [100, 200, 300]), and
* other JSON objects.

## Python Standard Library Module `json`
The json module enables you to convert objects to JSON (JavaScript Object Notation) text format. This is known as **serializing** the data.
```python
accounts_dict = {'accounts': [
	{'account': 100, 'name': 'Jones', 'balance': 24.98},
	{'account': 200, 'name': 'Doe', 'balance': 345.67}]}
```

## Serializing an Object to JSON
The json module’s `dump` function serializes the dictionary `accounts_dict` into the file.
```python
import json

with open('accounts.json', 'w') as accounts:
	json.dump(accounts_dict, accounts)
```

## Deserializing the JSON Text
The json module’s `load` function reads the entire JSON contents of its file object argument and converts the JSON into a Python object. This is known as **deserializing** the data.
```python
with open('accounts.json', 'r') as accounts:
	accounts_json = json.load(accounts)
```

## Displaying the JSON Text
The json module’s `dumps` function (dumps is short for “dump string”) returns a Python string representation of an object in JSON format. Using `dumps` with `load`, you can read the JSON from the file and display it in a nicely indented format—sometimes called “pretty printing” the JSON. When the dumps function call includes the indent keyword argument, the string contains newline characters and indentation for pretty printing—you also can use indent with the dump function when writing to a file.
```python
with open('accounts.json', 'r') as accounts:
	print(json.dumps(json.load(accounts), indent=4))
```
![[Pasted image 20220203184317.png | 250]]

# Additional notes
The following list summarizes the various `fileopen`  modes for text files, including the modes for reading and writing we’ve introduced. The writing and appending modes  create the file if it does not exist. The reading modes raise a FileNotFoundError if the file does not exist. Each textfile mode has a corresponding binaryfile mode specified with `b`, as in `'rb'` or `'wb+'.`
* `'r'` Open a text file for reading. This is the default if you do not specify the fileopen mode when you call open.
* `'w'` Open a text file for writing. Existing file contents are deleted.
* `'a'` Open a text file for appending at the end, creating the file if it does not exist. New data is written at the end of the file.
* `'r+'` Open a text file reading and writing.
* `'w+'` Open a text file reading and writing. Existing file contents are deleted.
* `'a+'` Open a text file reading and appending at the end. New data is written at the end of the file. If the file does not exist, it is created.
## Other file object methods
* For a text file, the `read` method returns a string containing the number of characters specified by the method’s integer argument. For a binary file, the method returns the specified number of bytes. If no argument is specified, the method returns the entire contents of the file.
* The `readline` method returns one line of text as a string, including the newline character if there is one. This method returns an empty string when it encounters the end of the file.
* The `writelines` method receives a list of strings and writes its contents to a file.
