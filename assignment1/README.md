# Assignment 1 by Cole Bardin

## Zoo program

### Usage

Usage: `./zoo [-f filename] [directory] mesurement`

Calling `./zoo measurement` will search all directories and subdirectories from the current directory for metric files

If no metric files are found, the program will output an error

### Measurement

The measurement argument will be an animal name from the list: 'aardvark', 'genet', 'bear', 'lemur', and 'dromedary'

NOTE: measurement entries are case-insensitive. `./zoo genet` is the same as `./zoo GeNeT`

Once a metric file is found, it will search for lines that include entries of the given measurement

An example entry looks like: dromedary 10

The program will count the second field of entries for the given measurement from all metric files

Measurement should always be the LAST argument given

### Metric filename

Default metric filename will is `.KS_Dir`

This can be changed by passing an optional argument BEFORE the measurement

Example: `./zoo -f .CB_Dir bear` will count bear entries but only within files with the name `.CB_Dir`

NOTE: -f flag MUST be either 2nd or 3rd argument and the expected filename will always FOLLOW the flag

Note order when specifying metric filename AND starting directory

### Starting directory

By default, the program begins searching from the current directory `.`

This can be changed by passing an argument BEFORE the measurement

Example: `./zoo A genet` will count all genet entries for metric files within the `./A` directory

NOTE: No flag specification for starting directory argument

Input directories are always validated for existance, filetype d and readability

## Errors

The program will error for various reasons:
- No metric files found
- Starting directory does not exist/is not readable
- No arguments/more than 4 arguments passed
- Measurement not in specified list
- Invalid arguments/improper flag position
