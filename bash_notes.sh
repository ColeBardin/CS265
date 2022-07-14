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
	$* 		all arguments (one string with all arguments, not counting program call)
	$@		all arguments (each argument as its own string, not counting program call)
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

case word in pattern1) cmds;; pattern2) cmds;; esac

Example:
#!/bin/bash
case $1 in
	n ) echo "n" ;;
	x ) echo "x" ;;
	\? | h | H ) echo "Use option n or x"; exit 1;;
	?)	echo "unknown character" ;;

esac


# While loops
while condition
do
		cmds
done

Example:
i=0
while (( $i<=12 )) ; do
	echo $i
	(( i+=1 ))
done

while tests; do cmds; done

A commonly used structure
cat list | while read f ; do # reads output of cat cmd and iterates line into f var
# assume list contains one filename per line
stat "$f" # calls stat on current filename
done
# repeats until output is done


# Until loops
until condition
do
	cmds;
done



# For loops
for variable in list
do
	cmds
done
# var must be user defined, list must be list of strings separated by spaces

Example 1:
for i in a b c ; do
	echo $i
done
outputs:
a
b
c

Example 2:
for id in $(cat userlist) ; do
# assumes no spaces in userIDs
	echo "Mailing $id..."
	mail -s "good subject" "$id"@someschool.edu < msg
done

Java/C for loops:
for (( i=0; i<3; ++i )) ; do
	echo $i
done



# Select loops
select name in last
do
	cmds;
done

select name in list; do cmds; done

# takes items specified in list, creates menu, prompts for respone, selection is stored in var name

select response in "This" "That" "Quit"
do
	echo "You chose $respone"
	# LOGIC TO EXIT SELECT LOOP (NECESSARY IN SOME FORM)
	if "$response" = "Quit"
	then
		exit
	fi
done
#output:
1) This
2) That
2) Quit
#? 2
You chose That
#?  

#NOTE: You need built in logic to escape out of the select loop


# Loop termination:
break jumps to the statement after the nearest done statement (exits loop immediately)
continue jumps to the statement before the nearest done statement (skips rest of current loop)

for i in {1..42} ; do # i will be range of values
	(( i%2 == 0 )) && continue
	(( i%9 == 0 )) && contiunue
	echo $i
done
prints out only odd numbers til a number is divisible by 9


# User input
- read command
- printf command
# using command line arguments

# Reading user input - read command
read varname 
	# note no dollarsign
reads from stdin

Read into variable:
read -p promt variable
ex:
read -p "Enter number: " var
echo $var

multiple variables read into once
read var1 var2 var3
reads each word into a new var, if more vars are supplied than words, all words will be also stored in last var


# printf command
printf format [arguments ...]
printf "hi %s\n" "Hello"
similar to printf from C


# Set command
set newarg1 newarg2
	$1		$2
get replaced respectively
allows to programatically change what is stored for command line arguments



# Back quotes ` `
eclosed command invocation in `` stores output of command into var inside of ``
dateVar = `date`
echo $dateVar

BETTER WAY TO DO IT THO
dateVar = $(date)
echo $dateVar



# Functions in bash
	# Function Delcaration
function function_name {body}
OR
function_name() {body}

functions are executed withinin same env as rest of script, so same env vars
recursion is allowed in bash

keyword: return
	val or no val

example:
usage() {
	echo "demo: usage: demo arg"
}

while [ $# -eq 0 ]
	do usage ; exit # exit call exits program not just loop
done
echo "Continue with program.."

Local variables in functions:
use keyword: local
function hello {
	local USER='Elmer Fudd'
	FOO='Hunting Wabbit'
	echo "Hello, $USER, you are $FOO"
}
shell:
$ FOO='Baking cookies'
$ echo $USER
cab572
$ hello
Hello, Elmer Fudd, you are Baking cookies


# Range of values, Brace expansion
{x..y} creates list of integer values between x and y, inclusively!
also works with letters 
{a..b} 


# Bash arrays
holds numbers and strings
myArray=(1 2 "three" 4 "five")

Array indexing with curly braces:
${myArray[0]} # first element
${myArray[@]} # all elemens

Using indices of index:
for i in ${!myArray[@]}; do
	cmds
done

Array Syntax:
arr=() 				Create an empty array
arr=(1 2 3) 		Initialize array
${arr[2]} 			Retrieve third element
${arr[@]} 			Retrieve all elements
${!arr[@]} 			Retrieve array indices
${#arr[@]} 			Calculate array size
arr[0]=3 			Overwrite 1st element
arr+=(4) 			Append value(s)
str=$(ls) 			Save ls output as a string
arr=( $(ls) ) 		Save ls output as an array of files
${arr[@]:s:n}		Retrieve n elements starting at index s

Add new value at end of array:
a[${#a[@]}]=val;
	gets number of elements, eg 9
	puts new val in position 9, since zero indexed

Display last element:
echo ${a[${#a[@]}-1]}
	gets number of elements, eg 9
	echos element at index 9-1=8 AKA last ement

COMMENT ALL YOUR ARRAY CODE BECAUSE THE SYNTAX IS NASTY




# Regular Expressions
sequence of special characters that describe a pattern
describes a search pattern, ie eaach RE matches a set of strings
look like wildcards but are slightly different

Used to validate input data to fit into a given pattern

shells use wildcards but tools use regular expressions 

regular expressions:
	grep
	egrep			-extended grep
	fgrep			-"fixed" string grep
	vi, sed, emacs
	other tools

letters and numbers are literal, they match themselves

the regular expression: foobar
matches ONLY the string: foobar

Special character:
.		Matches exactly one character 
			fooba. matches foobar, foobat, foobay etc
			f..bar matches foobar feabar 

[..]	Matches any listed character
			foob[aeiou]r matches only: foobar, foober, foobir, foobor, foobur
			# MATCHES items in order of ascii values

*		Zero or more of the LAST character # NOTE DIFFERENCE FROM wildcard * which is zero or more of any char
			fo* matches f, fo, foo, fooo, 
			[0-9][0-9]* matches 0, 1, 10, 00, 000042

-		Special character inside bracket to represent range # Only works when NOT FIRST CHAR
			[0-9] does NOT match for '-'
			[-09] DOES match for '-'

^		Negation of argumens within brackets # Only works as FIRST CHAR
			[^abc] will match for strings WITHOUT a b or c
			[ab^c] will match for a b ^ or c
			

# POSIX Bracketed Expressions
must be placed in brackets as well, double bracketed
`[[:lower:]]`

[:alnum:] [:alpha:] [:ascii:] [:blank:]
[:cntrl:] [:digit:] [:graph:] [:lower:]
[:print:] [:punct:] [:space:] [:upper:]
[:word:] [:xdigit:]


# ^$ beginning and end of line

^foobar matches any lines that start with foobar

foobar$ matches any lines that end with foobar



# grep fgrep egrep Commands

grep [options] regex [file ...]
	grep hello *.txt # NOTE: * is WILDCARD because it is shell wildcard expansion NOT REGEX
	# Search term is a REGEX however
worthy options to mention:
-i case insensitive search
-v inver search, only shot NOT matching lines
-l outputs filenames with matching lines
-c outputs only number of lines that match

interesting uses of grep
grep -v '^#'	removes all comment lines beginning with '#'

grep -v '^[ ]*$' 	removes all lines which are empty or contain only spaces


# FGREP - fixed string grep (faster than regular grep if string literal is known)
fgrep 'hello.*goodbye'


# EGREP - extended grep (extended regular expressions)
grep only does basic regex
fgrep allows use of metachars for more elaborate patterns

?		matches last item 0 or 1 times
+		matches last item 1 or more times
{n}		matches the last item exactly n times
{n,}	matches last item n or MORE times
{,n}	matches last item at MOST n times
{n,m}	matches last item at LEAST n times but NO MORE than m times
|		logical or
()		used for grouping and to force expressions
\m		back reference; matches string previously matched by mth paranthesized subexpression (m is single digit)
\<\>	beginning and end of word anchors
\c		turn off special meaning of char c
.		any character

examples:
[1-9][1-9]? matches 1 to 99

colou?r matches color and colour

0|[1-9][1-9]? matches all numbers 0 to 99 # since | is shell metachar, enclose REGEX in quotes to secure it

(a|b)c\.(log|txt) matches anything starting with a or b, followed by c and ends with .log or .txt
(a|b) is \1, (log|txt) is \2

\<[Yy]ou\> matches You or you only

"^\(*[[:digit:]]{3}\)*( |-)*[[:digit:]]{3}( |-)*[[:digit:]]{4}$" matches phone numbers

# Precedence rules
Repetition takes precedent over concatenation
whole expressions can be enclosed in paranthesis to force it



# Stream Editor (sed)
sed 's/word1/word2/g' input.file > output.file
replaces every instance of word1 with word2 in input.file and puts output into output.file




# AWK Programming Language for Text Processing
good for:
	- simple mechanical data manipulations
	- calculations
	- change format
	- validity checks
	- printing reports
	- add numbers
	- find items with properties

mawk version is on 

Reads input file one line at a time called 'records'
splits line by words called 'fields'

pattern { action } 

for example: emp.data contains
beth	4.00	0
dan		3.75	0
kathy	4.00	10
mark	5.00	20
marky	5.50	22
susie	4.25	18

awk '$3 > 0 { print $1, $2 * $3 }' emp.data
$1 is name
$2 is payrate
$3 is hours
pattern: any third field greater than 0
action: print name and amount earned (pay rate times hours)

awk '$3 == 0 { print $1 }' emp.data

No need for action or pattern
$3 = 0 # Default is to just print record (line)
{ print $1 } # Performs action on each line


# Begin and End
BEGIN { begin-action }
pattern1 { action1 }
pattern2 { action2 }
...
END { end-action }

Begin-actions will be done BEFORE searching file
End-actions will be done AFTER searching the file


awk [optioms] -f scriptfile var=value file(s)

# Useful options:
-F fs		sets the field operator to be a given input (default is whitespace)
-v var		allows value to be assigned to variable for script

# Build Variables in AWK
fields are split into $m where m is index
$0		entire line
FS		field separator
OFS		deliniant fields when you output
NF		number of fields in current records
NR		number of records
FNR		number of current record, line#
RS		record separator
ORS		output record separator
FILENAME	current filename being read
# Note no dollar signs for these values
$NF is last field


# Patterns
Using REGEX in patterns:
$1 ~ /re/
$1 !~ /re/


# C-like Scripting Language
only two types: floats and strings
variables are dynamically typed, no declarations
statements are separated by newline or ;
arrays are associative (can have strings as indices)
# comment lines

{
for( i=1; i<=NF; ++i )
{
print i, $i # enumerate, print each fule in the record
}
}

# Numbers:
% retuns float remainders
9.5 % 2.0 = 1.5
10.0 % 2.0 = 0.0

can be cast to int with int()
^ for exponentiation
funcs for bitshifts: lshift, rshift xor and or compl


# String concatenation
awk 'BEGIN { print "hello" "world" }'
	helloworld
awk 'BEGIN { print -12 " " -24 }'
	-12-24 
awk 'BEGIN { print -12 " " (-24) }'
	-12 -24

# String library functions
length, tolower, toupper
index
substr
sub, gsub, gensub # can use REGEX for these substitutions!
split, patsplit
sprintf
strtonum


# Arrays
keys can be number of strings
vectors can be spares
indices can be negative
BEGIN {
	a[5] = "spiros"
	a[12] = 13
	a[13] = "Ski"
	a[-77] = "I'm here too"
}

delete a[3]

# Multidimensional
a[i,j] = i*j

# Execute system commands:
system(cmd)

# User defined functions:
function func_name([param_list]) {
	body
}

function delarray(a, i) # space in front of i makes it local to func
{
	for (i in a)
		delete a[i]
}







# The `SED` editor
Stream EDitor

similar to sed as in pattern-action oriented
differences:
	sed processes lines
	awk processes lines AND fields

AWK for calculations and manipulations
SED for purely text editing

usage: sed command input

sed 's/this/that/' input.txt > output.txt
-i option to edit file in place
sed -i 's/this/that' input.txt

# Commands:
s	substitute
d	delete
p	print
c	change
a	append


s/old/new only replaces first instance per line
s/old/new/g for global and replace ALL occurances

# Delimeter
default /
to specify new delimeter:
s:/user/bin/local:/common/bin:g

# Matched string:
when the matching string is unknown
sed 's/[a-z]*/(&)/'
REGEX patterns can be used for sed
& is matched string

# Syntax of SED commands:
[address [,address ]][!]command [arguments]

sed '3 s/A/a/' on line number
sed '1,100 s/A/a/' on range of lines
sed '/^#/ s/A/a/' on all lines with pattern


# Can be used to replace grep
sed -n '/PATTERN/ p' file
is same as
grep PATTERN file
