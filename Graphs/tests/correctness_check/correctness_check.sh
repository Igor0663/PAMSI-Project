#!/bin/bash

for((i=0;i<=10000;i++)) do
	./gen $i 20 50 ./out
	./checker ./out
	if [ $? -eq 1 ] 
	then
		echo "Zle! $i"
		cp ./out ./bad_test
		break
	fi
	echo "OK! $i"
done

rm ./out
