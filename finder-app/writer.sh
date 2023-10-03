#!/bin/bash

writefile=$1
writestr=$2

if [ -z $writefile ];
then 
	echo "arg writefile not speciifed"
fi
if [ -z $writestr ];
then
	echo "arg writestr not specified"
fi
if [ ! -d "$(dirname "$writefile")" ];
then 
	mkdir -p "$(dirname "$writefile")"
fi
if [ ! -e "$writefile" ];
then 
	touch "$writefile"
fi

echo $writestr > $writefile
