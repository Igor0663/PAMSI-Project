#!/bin/bash

for((i=0;i<=10000;i++)) do
	./gen i 10000 0 > Test.txt 
	./sorting_program < Test.txt > out.txt
	./checker < out.txt
	if [ $? -eq 1 ]
	then
		echo "Zle $i!"
		break
	fi
	echo "OK $i"
done 

rm Test.txt out.txt
