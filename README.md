# CS265 Summer 2022

## Lab 1

My unfinished vimtutor document name `vi_lab` that I got a B on because I was lazy

Contains other documents pertaining to lab1

## Lab 2

All files for lab2

No custom scripts or programs

## Lab 3

This lab contains 3 custom written progams: `count.bash`, `reextend` and `organiseMusic`

### count.bash

Usage: `./count.bash`

Outputs all the files in the current directory to the screen followed by their linecount and word count

Nothing special or tricky. Does not include hidden files

### reextend

Usage: `./reextend oldExt newExt`

Finds all files in the current directory that end with `oldExt` and converts them to have `newExt`

Example: `./reextend A B` replaces `file.A` with `file.B` and `TADA` with `TADB`

### organiseMusic

Usage: `./organiseMusic`

Finds all mp3 music files within the current directory of form `Artist - Song.mp3` and organises them

If needed, a directory will be created `./Artist` and the mp3 file will be moved to `./Artist/Song.mp3`

Feature: If `./Artist/Song.mp3` already exists, the program will generate a unique filename instead of overwriting

## Lab 4

This lab contains two parts: REGEX an AWK

REGEX part includes no scripts, just written answers in the `l4` file

AWK part contains a bash script `anagram` that uses other scripts to find 8 largest anagrams in server dict file

### anagram

Usage: `./anagram`

Checks for necessary programs and files: `sign.c`, `squash.awk` and dict file `/usr/share/dict/words`

Compile `sign.c` with `gcc -o sign sign.c` and checks for valid executable

After all file and requirement validation, order of operations is:
- Signs all words from `/usr/share/dict/words` with `sign`
- Sorts signed words into alphabetical order
- Uses `squash.awk` to compile all adjacent anagrams
- Enumerates the number of anagrams for each word with inline AWK program
- Sorts anagram list by count
- Displays 8 anagrams with most count

### sign.c

Reads list of words from STDIN and outputs the 'signed' representation of each word followed by original word

Signed version of word is the letters in alphabetical order

### squash.awk

Reads list of signed words (from sign.c program sorted alphabetically)

Compiles words with similar signed representations

Outputs compiled list

## Assignment 1

### Zoo program

#### Usage

Usage: `./zoo [-f filename] [directory] mesurement`

Calling `./zoo measurement` will search all directories and subdirectories from the current directory for metric files

If no metric files are found, the program will output an error

#### Measurement

The measurement argument will be an animal name from the list: 'aardvark', 'genet', 'bear', 'lemur', and 'dromedary'

NOTE: measurement entries are case-insensitive. `./zoo genet` is the same as `./zoo GeNeT`

Once a metric file is found, it will search for lines that include entries of the given measurement

An example entry looks like: dromedary 10

The program will count the second field of entries for the given measurement from all metric files

Measurement should always be the LAST argument given

#### Metric filename

Default metric filename will is `.KS_Dir`

This can be changed by passing an optional argument BEFORE the measurement

Example: `./zoo -f .CB_Dir bear` will count bear entries but only within files with the name `.CB_Dir`

NOTE: -f flag MUST be either 2nd or 3rd argument and the expected filename will always FOLLOW the flag

Note order when specifying metric filename AND starting directory

If metric file is found but not readable, program outputs warning message and skips the file

#### Starting directory

By default, the program begins searching from the current directory `.`

This can be changed by passing an argument BEFORE the measurement

Example: `./zoo A genet` will count all genet entries for metric files within the `./A` directory

NOTE: No flag specification for starting directory argument

Input directories are always validated for existance, filetype d and readability

### Errors

The program will error for various reasons:
- No metric files found
- Starting directory does not exist/is not readable
- No arguments/more than 4 arguments passed
- Measurement not in specified list
- Invalid arguments/improper flag position

## Lab 5

Lab 5 covers the differences between C compilers.

I tested GCC vs TCC to determine how uninitialized variables are treated.

This lab also had me write two programs: `bills.c` and `ipay.c`

### bills.c

Usage: `./bills`

Program will prompt user for an integer value that represents a dollar amount

Then the program outputs how many 1, 5, 10, and 20 dollar bills make up that ammount

### ipay.c

UsageL `./ipay`

Program prompts user for a float input to represent a subtotal dollar amount

The program then calculates a 7% tip and 22% tax.

Finally, it outputs the users subtotal, tip, tax, and total

## Lab 6

Lab 6 works with braching evaluation, loops and arrays

I had to predict th evaluation of statements and outout of programs

I also had to write several programs for this lab:

`leap.c`, `readlines.c`, `ult.c`, `urt.c`, and `rev-array.c`

### leap.c

Usage: `./leap`

The program then prompts the user for year number in the form of an integer

Then outputs `YES` if the year is a leap year, and `NO` if not

### readlines.c

Usage: `./readlines`

This program reads doubles separated by newlines from `STDIN` until `EOF`

After the input stops, the program outputs the minumum and maximum values and the mean

### ult.c

Usage: `./ult`

This program prompts the user for an integer input

Then it prints out a isosceles triangle of the given length with `*` chars to the terminal justifed to the right

Example: 
`./ult
4
****
***
**
*`

### urt.c

Usage: `./urt`

This program prompts the user for an integer input

Then it prints out an ososceles triangle of the given length with `*` chars to the terminal justified to the left

Example:
`./urt
4
****
 ***
  **
   *`

### rev-array.c

Usage: `./rev-array`

This program reads up to 100 doubles separated by newline from `STDIN` and loads them into an array

Then it creates a properly sized array that holds all the inputs in the reversed order then prints them to the screen

## Lab 7

Lab 7 works with functions, pointers and strings in C

I had to write a few programs and functions:

`func1.c`, `func2.c`, `pointerFuncs.c`, `stringFuncs.c`, and `circle.c`

### func1.c

This program contains a function called `arrAvg` that takes in an array of doubles and a length

The function calculates the average value of the array and returns it

### func2.c

This program contains a function called `int2string` that takes an integer and a destination string

The number is expected to be no longer than 10 digits

This reads each digit in reverse order and converts them to strings

Then it loads the characters into a string of the number

### pointerFuncs.c

This program contains 3 functions: `binSearch`, `arrStats`, and `arrFind`

`binSearch` performs binary search in an array for a target int

If found, returns index of target, if not, returns length of array

`arrStats` computes the statistics for an array of doubles

It stores the min, max, and mean values into destination pointers passed to it

`arrFind` searches an array of ints for a target integer

If found, returns the address of the target, if not, it returns `NULL`

### stringFuncs.c

This program contains a function called `capitalize` which capitalizes a string passed as a parameter

It edits each character in place in the string, converting lowercase alphabet characters to uppercase

### circle.c

Usage: `./circle name radius`

This program must take in a name and a radius as a double as command line arguments

Then it computes the area of the circle with `M_PI` from `<math.h>`

It outputs a nice message with the name and the area

## Assignment 2

### msg.c program

Usage: `./msg [input-filename]`

Brief: `msg.c` reads codes (sequences of characters separated by newlines) from either `STDIN` or from a given file

Each code begins with a specific specifier character then must follow a precise sequence

This program prints out each code that it reads followed by `OK` if it is valid or `FAIL` if it

It uses functions that have built in Finite State Machines to determine whether or not a message is valid

More information, including the FSMs for each code in `Assignment2.pdf`
