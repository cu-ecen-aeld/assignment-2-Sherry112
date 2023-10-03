#!/bin/bash

filesdir=$1
searchstr=$2

if [ -z "$filesdir" ]
then 
	echo "filesdir not prvovided"
	exit  1
elif [ -z "$searchstr" ]
then 
	echo "Searchdir not provided"
	exit 1
else
	echo "Starting program"
fi

if [ -d "$filesdir" ];
then 
	echo "Directory $filesdir exists"
else
	echo "Directory $filesdir doesn't exist"
	exit 1
fi
X=$(grep -Rlw $filesdir -e $searchstr | wc -l)
Y=$(grep -Rw $filesdir -e $searchstr | wc -l)
echo "The number of files are $X and the number of matching lines are $Y"
