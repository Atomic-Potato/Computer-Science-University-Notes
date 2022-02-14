A dictionary associates keys with values. Each key maps to a specific value.
A dictionary’s keys must be immutable (such as strings, numbers or tuples) and unique (that is, no duplicates). Multiple keys can have the same value.

# Declaration 
You can create a dictionary by enclosing in curly braces, {}, a comma-separated list of key–value pairs, each of the form key: value. You can create an empty dictionary with {}.
```python
country_codes = {'Finland': 'fi', 'South Africa': 'za', 'Nepal': 'np'}
```
<label class="ob-comment" title="" style="">  <input type="checkbox"> <span style=""> Values can also be an array of values </span>Values Note</label>

The `len(dic)` will return the number of pairs.
`dic.clear()` to clear all the elements

# Accessing
```python
for key, value in dictionary.items()
	#code

dictionary[keyName] #gives the value in that key
#you can also alter the value
dic[key] = newVal

#if the key doesnt exist it will just append the new key and value to the end of the dic
dic[newKey] = newVal #if theres no newVal it will just give KeyError
#to avoide the above error you can use .get(key) it will return None if no such key is found
#else it will return the value
dic.get(Key)

#deleting a key-value
del dic[key]
#you can use .pop() which returns the value of the deleted key
dic.pop(key)

#you can use 'in' and 'not in' in dics
```

#  Dictionary Methods `keys` and `values`
Earlier, we used dictionary method `items` to iterate through tuples of a dictionary’s key–value pairs. Similarly, methods `keys` and `values` can be used to iterate through only a dictionary’s keys or values, respectively.
```python
for key in dic.keys():
	#print key
for val in dic.values():
	#print val
```

Dictionary methods `items`, `keys` and `values` each return a view of a dictionary’s data.
When you iterate over a view, it “sees” the dictionary’s current contents—it does not have its own copy of the data.
```python
dic_view = dic.keys()
for key in dic_view:
	#print key: 1 2 3
dic[key] = 4
for key in dic_view:
	#print key: 1 2 3 4
```

you can create lists from dics like so:
`list(dic.keys())`
`list(dic.values())`
`list(dic.items())` # this will be a list of tuples

`sorted(dic.items())` is also possible

# Dictionary Comparisons
The comparison operators `==` and `!=` can be used to determine whether two dictionaries have identical or different contents. 
An equals (`==`) comparison evaluates to True if both dictionaries have the same key–value pairs, regardless of the order in which those key–value pairs were added to each dictionary.

### Python Standard Library Module `collections`
The module `collections` contains the type `Counter`, which receives an iterable and summarizes its elements.

```python
from collections import Counter

text = ('this is sample text with several words '
	'this is more sample text with some different words')
counter = Counter(text.split())
for word, count in sorted(counter.items()):
	print(f'{word:<12}{count}') # look at img 1
print('Number of unique keys:', len(counter.keys())) #Number of unique keys: 10
```
IMG 1
![[Pasted image 20220113144044.png]]

##  Dictionary Method `update`
You may insert and update key–value pairs using dictionary method update.
```python
dic.update({'Key': 69})
```
Method update can convert keyword arguments into key–value pairs to insert.
```python
dic.update(KeyName = 420) 
#doing this again with the same keyname with a diffrent will just update the value
```
Method update also can receive an iterable object containing key–value pairs, such as a list of two-element tuples.

# Dictionary Comprehensions
```python
months = {'January': 1, 'February': 2, 'March': 3}
months2 = {number: name for name, number in months.items()} 
#{1: 'January', 2: 'February', 3: 'March'}

grades = {'Sue': [98, 87, 94], 'Bob': [84, 95, 91]}
grades2 = {k: sum(v) / len(v) for k, v in grades.items()}
#{'Sue': 93.0, 'Bob': 90.0}
```