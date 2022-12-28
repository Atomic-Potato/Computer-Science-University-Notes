- `waitpid()`
	```c
	waitpid(int pid, int* status, int options).
	```
	Waits for the process with the ID `pid`
	One of the options would be `WNOHANG` which means the parent **should not** wait
- `WIFEXITED()`
	```c
	int WIFEXITED(int status)
	```
	returns a non zero value if the child terminated normally with `exit()`
- `WIFSIGNALED()`
	```c
	int WIFSIGNALED(int status)
	```
	returns a non zero value if the child terminated because it received a signal that was not handled
- `WEXITSTATUS()`
	```c
	int WEXITSTATUS(int status)
	```
	returns the value of exit + shifts the returned value 8 bits to the right ( >> 8)
- `WTERMSIG()`
	```c
	int WTERMSIG(int status)
	```
	informs us of the signal that killed the child
- `sleep()`
	```c
	int sleep(int seconds)
	```
	stops the process for `seconds` seconds

--- 

# Orphan, Zombie, Normal
- `Orphan`: If the parent dies before its child. The `init` (parent of all processes in Linux) adopts this child & the `ppid` of this child becomes 1
- `Zombie`: If the child dies and the parent doesn’t execute the wait statement

To know the state of process with a `pid` we use the command `ps-a pid`
Returns `O` for Orphan, `Z` for Zombie and `0` for Normal

# Forking with files
When you fork and a file is opened, both processes get their own copy of the reference variable to that file. However whats stored in the file and the position of the caret (the blinking line that signifies where to start reading and writing) are shared between each process

## Executing files
- `argc` stores the number of parameters given
- `argv` the array containing the parameters
