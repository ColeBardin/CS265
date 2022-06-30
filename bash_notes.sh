# Bash Scripting Notes:
# June 30th, 2022

can be interactive or non interactive

Login shells (.bash_profile)

Interactive Non-Login shells (.bashrc)

/etc/profile 		-system-wide
/etc/bash.bashrc	-system-wide
~/.bash_profile		-user
~/.bashrc			-user


Shell is NOT general purpose programming language
It is intended to accomplish tasks with respect to unix commands

Process for getting commands:
1	Expands aliases recursively
2	Checks to see if command is a shell builtin (cd)
3	If not, assumes it is a disk utility (ls)

type program tells you where a following command is found
type ls -> alias for 'ls -color-auto'
type echo -> disk /bin/echo
type cd	-> builtin

built ins are: cd, type, pushd, set, pwd
shell provides builtins for common disk utilities: alias, echo, printf

use full path to invoke the disk utility ( /bin/echo )

help builtin_cmd

Disks run programs in subshells
if a command isnt a builtin, shell will search for it on your $PATH


# Special Characters to the Shell
wildcards: *?[]
I/O Redirection: <>|
Others: &;$#!()


# Wildcards
-	filename expansion and name globbing
-	* matches 0 or more characters
-	? macthes exactly 1 character
-	[list] matches any single character from list
wildcards are NOT regular expressions

ls [a-cf].jpeg (lists all JPEGs that begin with a,b,c or f)
ls [!a-cf].jpeg (lists all JPEGs that do NOT begin with a,b,c or f)


# Variables
declare with = operator
$ VAR=something
$ other_var="I have whitespace"

call with $ operator
$ echo $other_var
$ echo "My name is $USR"

# Common Parameters:
$PATH
$PS1
$USER
$HOME
$PWD
$SHELL

# Special Variables
$$ 			PID of current shell
$? 			Returns val of last command
TERM		Terminal type (what the shell thinks the interface is)
HOSTNAME	Machine hostname
EDITOR		Some programs may look here when editign a file
SHELLOPTS	Status of various bash options

\ escape char

# Quoting
" " Weak Quoting (double quotes)
	inhibit all but \ ' ' $ !

' ' Strong quoting
	ignores all special characters

$ echo "\$USER is $USER"
$USER is cab572

$ echo '\$USER is $USER'
\$USER is $USER


# Bash Command Executing
1	Sequence ;
	run commands in sequence of each other $ cmd1 ; cmd2 ; cmd3
	$ echo a ; javac test.java
2	Grouped {}
	runs commands in context of the shell (; MUST FOLLOW LAST COMMAND)
	$ { echo a ; echo b ; echo c; } > out.log
	$ cat out.log
	a
	b
	c
	different from:
	$ echo a ; echo b ; echo c > out.log
	a
	b
	$ cat out.log
	c
3	Subshell ()
	Runs in a different subshell
	$ y=30 ; ( y=20 ; echo $y ) ; echo $y
	20
	30
4	Conditional Commands && ||
	$ cmd1 && cmd2 (runs cmd2 IF cmd1 succeeds, does not if cmd1 fails)
	$ cmd1 || cmd2 (runs cmd2 IF cmd1 fails, does not if cmd1 succeeds)
	
	
