# `NOT EXACTLY REQUIRED`
# Terms
`process` is a program in execution
process is created every time you run a command
each process has a unique process id
processes are removed from the system when the command finishes its execution

`job` is a unit of work
consists of the commands specified in a single command line
A single job may involve several processes, each consisting of an executable program

`Foreground job:`
a job that has our immediate attention
user has to wait for job to complete

`Background job:`
a job that the user does not wait for
it runs independently of user interaction

# Jobs
to execute command in the background, put `&` after it

command “`jobs`” lists your active jobs, each job has job number, job number with “$” is used to refer to job
send job to background `bg`
move job to foreground `fg`

send signal to job with `kill` command

to stop a job `kill –STOP` resume via “bg” or “fg” command

to terminate a job `kill`, `kill -INT`, `kill -9`

# Scheduling 
`at`
run a job some time in the future
```c
% at timeDate command
```

`batch`
run a job when system load is low

`crontab` file has 6 columns:
`minute hour day month weekday command`
“`*`” means any value

End input list with `cntl-D` = end-of-text

`atq`
lists user’s scheduled jobs
`atrm`
removes specified job from at queue

# Batch
`batch`
schedules job to be performed when system load is
`low`
same program as “at”
```c
% batch command
```