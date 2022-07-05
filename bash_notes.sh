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
	


# Indentify the interpreter
first line should always identify the shell interpreter
example:

#!/bin/bash
or
#!/bin/sh


# Variable types
1.	command-line arguments
	$0		name of script
	$1		first command-line argument
	$2		second command-line argument
	...
	${n} 	n-th command-line argument
	$#		number of arguments
	$* 		all arguments (one string with all arguments)
	$@		all arguments (each argument as its own string)
2.	process-related variables
	$$		the process id (PID)
	$?		exit status of last command (0 is success, nonzero means error)
3.	environment variables
	$USER
	$HOME
	$PATH
	printenv	displays all environment variables
	export var	adds var to environment variables
4.	shell variables
	$DIRSTACK
	$HISTFILE
	$SHELLOPTS
	set			# Displays shell variables
	set -o posix	
5.	user-defined variables
	my_var=value
	# Note: no spaces around equal sign
	$my_var
	accesses contents of variable


# Null device
/dev/null is a device that discards all data written to it
checks exit status of program and ignore output 
diff f1 f2 > /dev/null
ignore both exit status and stdout
diff f1 f2 >& /dev/null



# Control Flow and Structures
# Branching
if
if-else
if-elif-else
case

# Loops:
while
until
for
select


# Conditions and Tests
1.	test, [ ]	Provides string, numeric, and file tests
2.	[[ ]]		Similar to [], but gentler syntax
3.	let, (( ))	Provides numeric tests and arithmetic

# Test command:
general form: test expr

example:
if test $name = "Dimitra"
then
	echo 'Hello Dimitra!'
fi



# [] form (Mostly for strings and files)
generam form: [ expr ]
	# NOTE: spaces around the = sign must match and there MUST be a space padding [] from expr
example:
if [ $name = "Dimitra" ]
then
	echo 'Helo Dimitra';
fi

String Tests:
	operators: < = != > ( < and > must be escaped with \ )
	[ $var = "Dimitra" ] 
	[ $var != "Dimitra" ]
	[ $var \< "Dimitra" ]

Unary tests for strings:
	-z True if string is empty
	-n True if string is NOT empty
	[ -z "$1" ] 
	# checks if first command line argument is empty

File Tests:
-a file		True if file exists
-e file		True if file exists
-f file		True if file is a regular file
-c file		True if file is a character file
-d file		True if file is a directory
! -d file	True if file is NOT a directory

Binary operators for files:
f1 -nt f2		True if f1 is newer that f2
f1 -ot f2		True if f1 is older than f2
f1 -ef f2		True if f1 is a hardlink to f2 (same file)

Numeric tests:
n1 -eq n2	Equal
n1 -lt n2	Less than
n1 -gt n2	Greater than
n1 -ne n2	Not equal
n1 -le n2	Less than or equal to
n1 -ge n2	Greater than or equal to
# NOTE: not using < > = != since these are for STRING tests
ex:
if [ $a -lt $b ] 
then
	echo "$a is less than $b";
fi

Logical Operators:
! expr			NOT
exp1 -a exp2	AND
exp1 -o exp2	OR



# [[ ]] 
Shell metacharacters (< and >) dont need to be escaped
Supports familiar logical operators:
	! && ||
Tests using == and = are equivalent
== and != treat right operand as a pattern (glob / wildcard matching)
	[[ abcde.f == a.*e\..? ]] # Is file on left of form on right
=~ treats the right operand as an extended regular expression (egrep)
	[[ abcde.f =~ a.*e\..? ]]

# NOTE: do not use [[ ]] for arithmetic tests using <, >
# [[ ]] also does string comparison



# (( )) Arithmetic Evaluation
can be used in conditionals
# NOTE: only for INTEGERS
x=5
if (( $x > 7 ))
then
	echo "$x is greater than 7";
fi


# Let command for arithmetic evaluation
general form: let arithmetic-expr
example: # Spaces are NOT important here
	let "X = 1+1"
	let "X = X +1"
	let "X = $X + 1"

# (()) and let arithmetic operatods
Arithmetic: ** * / % + -
Bit-wise: ~ << >> ^ & |
Increment/Decrement: ++ --
Java like ternary operator: ?:
Assignment operators: = += -= &= etc

(()) can be used to contain arithmetic operations:
x=5
echo $(( x+15 )) 

let a=1+1	# Variable creation with simple arithmetic expansion
a=$((1+1))	# Arithmetic expansion, result of expression replaces the expression
a=$(expr 1 + 1)	#


# Control flow:
if tests
then
	cmds;
fi

OR:
if tests; then cmds; fi

# Else if 
if tests
then
	cmds;
elif tests
	cmds;
else
	cmds;
fi

# Case statements
case word in
pattern1) cmds;; # Singular patterns
pattern2 | pattern3) cmds;; # Multiple patterns
'*') cmds;; # Otherwise/default
esac
# uses patterns not regular expressions

case word in {pattern ) cmds;;} esac

Example:
#!/bin/bash
case $1 in
	n ) echo "n" ;;
	x ) echo "x" ;;
	\? | h | H ) echo "Use option n or x"; exit 1;;
	?)	echo "unknown character" ;;
esac

