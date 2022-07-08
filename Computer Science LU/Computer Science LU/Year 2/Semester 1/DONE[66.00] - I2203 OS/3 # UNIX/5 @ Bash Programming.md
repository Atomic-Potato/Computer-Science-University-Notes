# User input
```sh
read varname [more vars]
```
or
```sh
read –p "prompt" varname [more vars]
```
the string will be prompted before asking for input

you can output the vars with `echo $var`

The following should not be variable names
![[Pasted image 20220301202555.png | 600]]

# If statement
```py
if command then
	statements
elif command then
	statements
else
	statements
fi
```
statements are executed only if command succeeds, i.e. has return status “0”

**The simple if statement:**
```c
if [ condition ]; then
	statements
fi
```

# Relational Operators
![[Pasted image 20220301202921.png | 600]]

## Compound logical expressions
![[Pasted image 20220301203013.png | 600]]

# File Testing
`-d file` True if ‘file’ is a directory
`-f file` True if ‘file’ is an ord. file
`-r file` True if ‘file’ is readable
`-w file` True if ‘file’ is writable
`-x file` True if ‘file’ is executable
`-s file` True if length of ‘file’ is nonzero

# Case statement
```c
case word in
	pattern1) command-list1
	;;
	pattern2) command-list2
	;;
	patternN) command-listN
	;;
esac
```

pattern may also be `*, ?, [...], [:class:]`
multiple patterns can be listed via `|`

# While loop
```c
while [ expression ]
do
	command-list
done
```

# Until loop
To execute commands in “command-list” as long as “expression” evaluates to false
```c
until [ expression ]
do
	command-list
done
```

# For loop
To execute commands as many times as the number of words in the “argument-list”
```BASH
for variable in argument-list
do
	#commands
done
```

**OR**

```bash 
for (( i=x; i<y; i++ )) 
do #IT IS NECESSARY TO HAVE IT ON A NEW LINE !!
	#commands
done
```