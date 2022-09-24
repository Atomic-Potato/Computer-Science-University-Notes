# Declaration
```java
String lePotato = "La Tomato";               // 1
String thePotao = new String("La Tomato");   // 2
String laPotato = "La Tomato";               // 3
```
String is not a basic type, its actually a  `class`. And when you create a string like in `1` then you create a pointer that points to a class containing a string.

And actually `1` and `3` are just two pointers pointing to the same object. So if we want to create a distinct object with the same content as a pervious object of the same class, we use the `new` keyword.
___
# Comparison 
```java
if(string1 == string2);          // 1
if(string1.equals(string2));     // 2
if(string1.compareTo(string2));  // 3
```

We're not actually comparing the strings in `1`, we're just comparing the pointers to see if they point to the same address.

In `2` the function returns `True` or `False` if they are equal.
In `3` the function returns:
	- **0** if they are equal
	- **>0** if string1 comes first
	- **<0** if string2 comes first
The function returns the difference, in the ASCII table, between the first 2 characters that are unequal.
___
# Useful Functions
- string.**length()**;
- string.**charAt(index)**;
- string.**concat(s)**;
- string.**startsWith(s)**;
- string.**endsWith(s)**;
- string.**substring(beginIndex, endIndex)**; *Returns the string between the begin index and end index(not included)*
___
- string.**toLower();**
- string.**toUpper();**
- string.**replace(char1, char2);** *replaces every occurrence* 
- string.**relpaceFirst(str1, str2);** *str1 can be a REGEX pattern*
- string.**replaceAll(str1, str2);**
- string.**split();**
- string.**trim();** *removes spaces*
___
- string.**indexOf(char, startFromIndex);**
- string.**lastIndexOf(char);** *last occurrence of this index*
- `String`.**valueOf(variable);** *converts variable into a string*
- string.**format("5.2f",  number);** *it will apply this format to the returned string instead of using `System.out.printf()`*

---
# REGEX
```java
"potato".matches("pattern"); //returns true or false
```