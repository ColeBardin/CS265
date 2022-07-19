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
