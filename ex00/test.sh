#! /bin/bash

while read line
do 
	echo "--------------------------"
	echo "testing $line"
    ./convert "$line"
done < test.txt
