#!/bin/bash

ls | while read item ; do
	wc "$item" -l -w | while read l w f ; do
		echo $f $l $w  
	done
done
