#!/bin/bash

echo "count.bash"
echo "Filename Linecount WordCount:"
echo

count=0
# Iterate through each item in current directory
while read item ; do
	# If the item is of type 'file'
	if [ -f "$item" ] ; then
		((count=count+1))
		# Produce wordcount and linecount for the file and store the values into variables f, l and w
		wc "$item" -l -w | while read l w f ; do
			# Print out the filename with its linecount and wordcount
			echo $f $l $w  
		done
	else
		# Continue if file is not of type f
		continue
	fi
done <<<$(ls -1)

if (( $count == 0 )) ; then
	echo "ERROR: No files found in current directory to count" ; exit
fi
