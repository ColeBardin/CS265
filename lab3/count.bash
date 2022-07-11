#!/bin/bash

# Iterate through each item in current directory
ls | while read item ; do
	# If the item is of type 'file'
	if [ -f "$item" ] ; then
		# Produce wordcount and linecount for the file and store the values into variables f, l and w
		wc "$item" -l -w | while read l w f ; do
			# Print out the filename with its linecount and wordcount
			echo $f $l $w  
		done
	else
		# Continue if file is not of type f
		continue
	fi
done
