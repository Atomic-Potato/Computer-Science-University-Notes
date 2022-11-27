Regular expressions are used to recognize patterns in strings

# Declaration and usage
```python
import re #imports regular expressions

pattern = '02215'

'Match' if re.fullmatch(pattern, '02215') else 'No match' #Match

'Match' if re.fullmatch(pattern, '51220') else 'No match' #No match
```

## Metacharacters, Character Classes and Quantifiers
The `\` metacharacter begins each of the predefined character classes, each matching a specific set of characters.

```python
'Valid' if re.fullmatch(r'\d{5}', '02215') else 'Invalid'
```
`\d` is a character class representing a digit. The quantifier `{5}` repeats `\d`five times, as if we had written `\d\d\d\d\d`
You can match at least n occurrences of a subexpression with the `{n,}` quantifier.
You can match between n and m (inclusive) occurrences of a subexpression with the `{n,m}` quantifier.

Heres some other classes:
* `\d `Any digit (0–9).
* `\D` Any character that is not a digit.
* `\s` Any whitespace character (such as spaces, tabs and newlines).
* `\S` Any character that is not a whitespace character.
* `\w` Any word character (also called an alphanumeric character)—that is, any uppercase or lowercase letter, any digit or an underscore
* `\W` Any character that is not a word character.

### Custom character classes
Square brackets, `[]`, define a custom character class that matches a single character. For example, `[aeiou]` matches a lowercase vowel, `[AZ]` matches an uppercase letter, `[az]` matches a lowercase letter and `[azAZ]` matches any lowercase or uppercase letter.

The `*` quantifier matches zero or more occurrences of the subexpression to its right
You can do the same `+` but this one wants at least one character to the right
Example:
```python
'Valid' if re.fullmatch('[A-Z][a-z]*', 'Wally') else 'Invalid'
```

Metacharacters in a custom character class are treated as literal characters—that is, the characters themselves. So `[*+$]` matches a single `*, + or $` character.

The `?` quantifier matches zero or one occurrences of a subexpression.
Example
```python
'Match' if re.fullmatch('labell?ed', 'labelled') else 'No match' #Match
```

The `^` metacharacter at the beginning of a regular expression (and not inside square brackets) is an anchor indicating that the expression matches only the `beginning` of a string.
Similarly, the `$` metacharacter at the end of a regular expression is an anchor indicating that the expression matches only the `end` of a string.
Example
```python
result = re.search('^Python', 'Python is fun')
result = re.search('Python$', 'Python is fun')
```

You can use parentheses metacharacters—( and )—to capture substrings in a match.
You can access each captured substring by passing an integer to the `group` method. The captured substrings are numbered from 1 (unlike list indices, which start at 0).

##  Other Search Functions; Accessing Matches
Function `search` looks in a string for the first occurrence of a substring that matches a regular expression and returns a match object (of type `SRE_Match`) that contains the matching substring. The match object’s `group` method returns that substring.
Example:
```python
result = re.search('Python', 'Python is fun')
result.group() if result else 'not found' #Python

result3 = re.search('Sam', 'SAM WHITE', flags=re.IGNORECASE) #im not sure how this works
result3.group() if result3 else 'not found' #SAM
```

`re.findall(substring, string)` finds every matching substring in a string and returns a list of the matching substrings.
Function `finditer` works like `findall`, but returns a lazy `iterable` of match objects. It returns one match at a time, whereas `findall` returns all the matches at once.
Example
```python
contact = 'Wally White, Home: 555-555-1234, Work: 555-555-4321'
re.findall(r'\d{3}-\d{3}-\d{4}', contact) #['555-555-1234', '555-555-4321']

for phone in re.finditer(r'\d{3}-\d{3}-\d{4}', contact):
	print(phone.group())
```


# String Manipulation
`re.sub(pattern, new_pattern, string)` replaces all the patterns in the string with the new pattern, you can include the 4th argument `count=x` to specify how many times to do substitution
