# Steps to create a shell program
Specify shell to execute program Script must begin with `#!` (pronounced “shebang”) to identify shell to be executed
examples:
```sh
#! /bin/sh (defaults to bash)
#! /bin/bash 
#! /bin/csh
#! /usr/bin/tcsh
```
`remember to make the program executable using chmod`

Formatting of shell programs
- Indent areas (3 or 4 spaces) of programs to indicate that commands are part of a group
- To break up long lines, place a `\` at the end of one line and continue the command on the next line

You can type in comments using `#`


# EXAMPLE PROGRAM
```csh
#! /bin/csh
echo "Hello $USER"
echo "This machine is `uname -n`"
echo "The calendar for this month is:"
cal
echo "You are running these processes:"
ps
```

# Other commands
- **`find`**
```c
find -name "filename" //to find all the files in the current and the subfiles with the exact name
find -iname "filename" //same as above but doesnt care for lower and upper case
find -not -iname "name" //finds everything except the ones called "name"
find -iname number // to find a file with this id
```

- **`-exec`**
if we want to execute a command using the result of a command before this one
```c
command1 -exec command2 {} \; // {} \; aare syntax
```