#!/bin/bash

ls | while read item ; do
	if [ -f "$item" ] ; then
		wc "$item" -l -w | while read l w f ; do
			echo $f $l $w  
		done
	else
		continue
	fi
done
