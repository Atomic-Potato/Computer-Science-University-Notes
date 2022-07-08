- To store the output of a command and make it not make any output on the terminal you can do like this
```bash
var_name=$(commands) #NO SPACES FOR GOD SAKE
```

- Remember when `piping` a variable remember to echo it so the second command would take it in, because remember most commands will only take input from files and not variables
```bash
var_name=$(commands) #NO SPACES FOR GOD SAKE
echo var_name | wc -w
```