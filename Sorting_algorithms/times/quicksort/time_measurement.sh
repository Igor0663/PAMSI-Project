#!/bin/bash

mkdir 10k
mkdir 50k
mkdir 100k
mkdir 500k
mkdir 1m

for((i=1;i<=100;i++)) do
	./sorting_program < ../../tests/tables/10k/losowe/tab$i.txt >> ./10k/losowe.txt
	./sorting_program < ../../tests/tables/10k/25%/tab$i.txt >> ./10k/25%.txt
	./sorting_program < ../../tests/tables/10k/50%/tab$i.txt >> ./10k/50%.txt
	./sorting_program < ../../tests/tables/10k/75%/tab$i.txt >> ./10k/75%.txt
	./sorting_program < ../../tests/tables/10k/95%/tab$i.txt >> ./10k/95%.txt
	./sorting_program < ../../tests/tables/10k/99%/tab$i.txt >> ./10k/99%.txt
	./sorting_program < ../../tests/tables/10k/99.7%/tab$i.txt >> ./10k/99.7%.txt
	./sorting_program < ../../tests/tables/10k/odwrotnie/tab$i.txt >> ./10k/odwrotnie.txt
	echo "OK $i"
done
echo "10k done"

for((i=101;i<=200;i++)) do
	./sorting_program < ../../tests/tables/50k/losowe/tab$i.txt >> ./50k/losowe.txt
	./sorting_program < ../../tests/tables/50k/25%/tab$i.txt >> ./50k/25%.txt
	./sorting_program < ../../tests/tables/50k/50%/tab$i.txt >> ./50k/50%.txt
	./sorting_program < ../../tests/tables/50k/75%/tab$i.txt >> ./50k/75%.txt
	./sorting_program < ../../tests/tables/50k/95%/tab$i.txt >> ./50k/95%.txt
	./sorting_program < ../../tests/tables/50k/99%/tab$i.txt >> ./50k/99%.txt
	./sorting_program < ../../tests/tables/50k/99.7%/tab$i.txt >> ./50k/99.7%.txt
	./sorting_program < ../../tests/tables/50k/odwrotnie/tab$i.txt >> ./50k/odwrotnie.txt
	echo "OK $i"
done
echo "50k done"

for((i=201;i<=300;i++)) do
	./sorting_program < ../../tests/tables/100k/losowe/tab$i.txt >> ./100k/losowe.txt
	./sorting_program < ../../tests/tables/100k/25%/tab$i.txt >> ./100k/25%.txt
	./sorting_program < ../../tests/tables/100k/50%/tab$i.txt >> ./100k/50%.txt
	./sorting_program < ../../tests/tables/100k/75%/tab$i.txt >> ./100k/75%.txt
	./sorting_program < ../../tests/tables/100k/95%/tab$i.txt >> ./100k/95%.txt
	./sorting_program < ../../tests/tables/100k/99%/tab$i.txt >> ./100k/99%.txt
	./sorting_program < ../../tests/tables/100k/99.7%/tab$i.txt >> ./100k/99.7%.txt
	./sorting_program < ../../tests/tables/100k/odwrotnie/tab$i.txt >> ./100k/odwrotnie.txt
	echo "OK $i"
done
echo "100k done"

for((i=301;i<=400;i++)) do
	./sorting_program < ../../tests/tables/500k/losowe/tab$i.txt >> ./500k/losowe.txt
	./sorting_program < ../../tests/tables/500k/25%/tab$i.txt >> ./500k/25%.txt
	./sorting_program < ../../tests/tables/500k/50%/tab$i.txt >> ./500k/50%.txt
	./sorting_program < ../../tests/tables/500k/75%/tab$i.txt >> ./500k/75%.txt
	./sorting_program < ../../tests/tables/500k/95%/tab$i.txt >> ./500k/95%.txt
	./sorting_program < ../../tests/tables/500k/99%/tab$i.txt >> ./500k/99%.txt
	./sorting_program < ../../tests/tables/500k/99.7%/tab$i.txt >> ./500k/99.7%.txt
	./sorting_program < ../../tests/tables/500k/odwrotnie/tab$i.txt >> ./500k/odwrotnie.txt
	echo "OK $i"
done
echo "500k done"

for((i=401;i<=500;i++)) do
	./sorting_program < ../../tests/tables/1m/losowe/tab$i.txt >> ./1m/losowe.txt
	./sorting_program < ../../tests/tables/1m/25%/tab$i.txt >> ./1m/25%.txt
	./sorting_program < ../../tests/tables/1m/50%/tab$i.txt >> ./1m/50%.txt
	./sorting_program < ../../tests/tables/1m/75%/tab$i.txt >> ./1m/75%.txt
	./sorting_program < ../../tests/tables/1m/95%/tab$i.txt >> ./1m/95%.txt
	./sorting_program < ../../tests/tables/1m/99%/tab$i.txt >> ./1m/99%.txt
	./sorting_program < ../../tests/tables/1m/99.7%/tab$i.txt >> ./1m/99.7%.txt
	./sorting_program < ../../tests/tables/1m/odwrotnie/tab$i.txt >> ./1m/odwrotnie.txt
	echo "OK $i"
done
echo "1m done"
