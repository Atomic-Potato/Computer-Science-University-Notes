# Metacharacters
![[Pasted image 20220305163844.png | 600]]
	![[Pasted image 20220305164007.png | 600]]
any non-metachar matches itself

# Regular expressions
- An `atom` specifies what text is to be matched and where it is to be found.
- An `operator` combines regular expression atoms.

## Atoms
Atoms can be:
- singles chars
	- self explained
- dot
	- matches any single character except for a new line character (`\n`) (Ex: P.)
- class
	- matches only single character that can be any of the characters defined in a set (Ex: [ABC])
	- Examples
	![[Pasted image 20220305164611.png | 500]]
	- Shorthand classes:
		- [:alnum:] alphabetic chars + nums
		- [:alpha:] alphabetic chars
		- [:upper:]
		- [:lower:]
		- [:digit:]
		- [:space:]
- anchor
	- Anchors tell where the next character in the pattern must be located in the text data.
	![[Pasted image 20220305164849.png | 300]]
- back reference `NOT IMPORTANT HERE BECAUSE WE WILL BE SEEING IT IN AWK`
	- used to retrieve saved text in one of nine buffers
	- can refer to the text in a saved buffer by using a back reference

## Operators
Types of operators:
- Sequence `nothing`
	- In a sequence operator, if a series of atoms are shown in a regular expression, there is no operator between them.
	- Examples:
	![[Pasted image 20220305165246.png]]
- Alteration `|`
	- operator (`|` or `\|` ) is used to define one or more alternatives (Note, it depends on the version of grep)
	- Examples:
		![[Pasted image 20220305165431.png | 600]]
- Repetition `\{m,n\}`
	- The repetition operator specifies that the atom or expression immediately before the repetition may be repeated.
	- Examples:
	![[Pasted image 20220305165558.png | 600]]
	- Short for repetition operators:
	![[Pasted image 20220305165656.png | 600]]
- Group `(...)`
	- In the group operator, when a group of characters is enclosed in parentheses, the next operator applies to the whole group, not only the previous characters.
	- Examples: (Noted: depends on version of grep, use `\(` and `\)` instead
	![[Pasted image 20220305165812.png | 600]]

# The `grep` utility
grep searchers for patterns in files
```
grep [options] [pattern] [filename]
```

**Commonly used grep options:**
 - `-c` Print only a count of matched lines.
 - `-i` Ignore uppercase and lowercase distinctions.
 - `-l` List all files that contain the specified pattern.
 - `-n` Print matched lines and line numbers.
 - `-s` Work silently; display nothing except error messages. Useful for checking the exit status.
 - `-v` Print lines that do not match the pattern.