# Simple Shell Project

** A SIMPLE COMMAND SHELL INTEPRETOR**

## What's this shell?
The shell is a program that takes commands from the keyboard via the terminal, and gives them to the operating system to execute.\


## Functionalities of the Simple Shell:
- Displays a prompt "0__0$ " and waits for user input.\
- Runs all commands of type "executable program" (ls and /bin/ls).\
- Runs the following build_in commands: **exit**, **env**, **setenv** and **unsetenv**.\
- Handles commands with arguments.\
- Handles the PATH global variable.\
- Handles The EOF (End Of File) condition.\
- Handles the Ctrl + C signal.\

- **AUTHORS** -> List of contributors to this repositors.
## List of allowed functions and system calls for this project
 - access (man 2 access)
 - chdir (man 2 chdir)
 - close (man 2 close)
 - closedir (man 3 closedir)
 - execve (man 2 execve)
 - exit (man 3 exit)
 - _exit (man 2 _exit)
 - fflush (man 3 fflush)
 - fork (man 2 fork)
 - free (man 3 free)
 - getcwd (man 3 getcwd)
 - getline (man 3 getline)
 - isatty (man 3 isatty)
 - kill (man 2 kill)
 - malloc (man 3 malloc)
 - open (man 2 open)
 - opendir (man 3 opendir)
 - perror (man 3 perror)
 - read (man 2 read)
 - readdir (man 3 readdir)
 - signal (man 2 signal)
 - stat (__xstat) (man 2 stat)
 - lstat (__lxstat) (man 2 lstat)
 - fstat (__fxstat) (man 2 fstat)
 - strtok (man 3 strtok)
 - wait (man 2 wait)
 - waitpid (man 2 waitpid)
 - wait3 (man 2 wait3)
 - wait4 (man 2 wait4)
 - write (man 2 write)
****

## USAGE
You can try our shell by following these steps:
> **Step 1:** (you need to have git installed on your machine first)
clone our repository using this command.
````
git clone https://github.com/Ochiengmorris/simple_shell.git

````

> **Step 2:** Change directory to simple_shell:
````
cd simple_shell

````
> **Step 3:** Here is how to compile the c files:
````
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

````
> **Step 4:** Go on and run the shell
````
./hsh

````
**Exiting the shell**
When you want to exit the shell, you can use one of the following methods:
> **1: Type the command "exit"**
````
exit

````
> **2: Press on Ctrl + D**

## Example of Usage
````
ubunto@ubuntu:~/Johnmorris/simple_shell$ gcc -Wall -Wextra -Werror -pedantic *.c -o hsh 
ubunto@ubuntu:~/Johnmorris/simple_shell$ ./hsh
0__0$ echo HI, my name is John.
HI, my name is John
0__0$ /bin/ls
README.md  line.c  shell2.c  main.h
trial.c  hsh
0__0$ ^C
0__0$ exit
ubunto@ubuntu:~/Johnmorris/simple_shell$
````
## Bugs
Not found any as of publishing day.

## AUTHOR
John Oduya : [LinkedIn/Johnoduya] | [GitHub/Ochiengmorris] | [Twitter/Oduyajohn]

[GitHub/John]: <https://github.com/Ochiengmorris>
[Twitter/John]: <https://twitter.com/oduyajohn66>
