# SUMMARY
![[Pasted image 20220225112436.png | 600]]

# Output
we use the command `echo` to output strings, variables, execute commands on the terminal screen
Examples
```c
% echo "Hello Ray"
//Hello Ray
% echo "Hello $USER"
//Hello medya
% echo "It is now `date`”
//It is now Mon Feb 25 10:24:08 CST 2008
```

# Output redirection `>`
we can change the output to go into a file instead of the terminal using `>`
```c
% ls > file.txt
```
You can also do multiple commands
```c
% (date; du) > file.txt
```

# Input redirection `<`
You can take input from a file for a command using `<`
```c
% wc < file.txt
```

you can can chain `<` and `>`
```c
% ls > temp.txt; wc < temp.txt
```
if you dont wanna do this we can use the middleman : `pipe`
```c
% ls | wc
```

# Appending output `>>`
if we dont wanna erase the original data in a file and just add to it new data we use `>>`
```c
% ls -l >> usage-status
```