#!/bin/bash

mkdir tables
mkdir ./tables/10k
mkdir ./tables/10k/25%
mkdir ./tables/10k/50%
mkdir ./tables/10k/75%
mkdir ./tables/10k/95%
mkdir ./tables/10k/99%
mkdir ./tables/10k/99.7%
mkdir ./tables/10k/odwrotnie
mkdir ./tables/10k/losowe

for((i=1;i<=100;i++)) do
	./gen $i 10000 0   > ./tables/10k/losowe/tab$i.txt
	./gen $i 10000 250 > ./tables/10k/25%/tab$i.txt
	./gen $i 10000 500 > ./tables/10k/50%/tab$i.txt
	./gen $i 10000 750 > ./tables/10k/75%/tab$i.txt
	./gen $i 10000 950 > ./tables/10k/95%/tab$i.txt
	./gen $i 10000 990 > ./tables/10k/99%/tab$i.txt
	./gen $i 10000 997 > ./tables/10k/99.7%/tab$i.txt
	./gen $i 10000 -1  > ./tables/10k/odwrotnie/tab$i.txt
done	
echo "10k done"

mkdir ./tables/50k
mkdir ./tables/50k/25%
mkdir ./tables/50k/50%
mkdir ./tables/50k/75%
mkdir ./tables/50k/95%
mkdir ./tables/50k/99%
mkdir ./tables/50k/99.7%
mkdir ./tables/50k/odwrotnie
mkdir ./tables/50k/losowe

for((i=101;i<=200;i++)) do
	./gen $i 50000 0   > ./tables/50k/losowe/tab$i.txt
	./gen $i 50000 250 > ./tables/50k/25%/tab$i.txt
	./gen $i 50000 500 > ./tables/50k/50%/tab$i.txt
	./gen $i 50000 750 > ./tables/50k/75%/tab$i.txt
	./gen $i 50000 950 > ./tables/50k/95%/tab$i.txt
	./gen $i 50000 990 > ./tables/50k/99%/tab$i.txt
	./gen $i 50000 997 > ./tables/50k/99.7%/tab$i.txt
	./gen $i 50000 -1  > ./tables/50k/odwrotnie/tab$i.txt
done	
echo "50k done"

mkdir ./tables/100k
mkdir ./tables/100k/25%
mkdir ./tables/100k/50%
mkdir ./tables/100k/75%
mkdir ./tables/100k/95%
mkdir ./tables/100k/99%
mkdir ./tables/100k/99.7%
mkdir ./tables/100k/odwrotnie
mkdir ./tables/100k/losowe

for((i=201;i<=300;i++)) do
	./gen $i 100000 0   > ./tables/100k/losowe/tab$i.txt
	./gen $i 100000 250 > ./tables/100k/25%/tab$i.txt
	./gen $i 100000 500 > ./tables/100k/50%/tab$i.txt
	./gen $i 100000 750 > ./tables/100k/75%/tab$i.txt
	./gen $i 100000 950 > ./tables/100k/95%/tab$i.txt
	./gen $i 100000 990 > ./tables/100k/99%/tab$i.txt
	./gen $i 100000 997 > ./tables/100k/99.7%/tab$i.txt
	./gen $i 100000 -1  > ./tables/100k/odwrotnie/tab$i.txt
done	
echo "100k done"

mkdir ./tables/500k
mkdir ./tables/500k/25%
mkdir ./tables/500k/50%
mkdir ./tables/500k/75%
mkdir ./tables/500k/95%
mkdir ./tables/500k/99%
mkdir ./tables/500k/99.7%
mkdir ./tables/500k/odwrotnie
mkdir ./tables/500k/losowe

for((i=301;i<=400;i++)) do
	./gen $i 500000 0   > ./tables/500k/losowe/tab$i.txt
	./gen $i 500000 250 > ./tables/500k/25%/tab$i.txt
	./gen $i 500000 500 > ./tables/500k/50%/tab$i.txt
	./gen $i 500000 750 > ./tables/500k/75%/tab$i.txt
	./gen $i 500000 950 > ./tables/500k/95%/tab$i.txt
	./gen $i 500000 990 > ./tables/500k/99%/tab$i.txt
	./gen $i 500000 997 > ./tables/500k/99.7%/tab$i.txt
	./gen $i 500000 -1  > ./tables/500k/odwrotnie/tab$i.txt
done	
echo "500k done"

mkdir ./tables/1m
mkdir ./tables/1m/25%
mkdir ./tables/1m/50%
mkdir ./tables/1m/75%
mkdir ./tables/1m/95%
mkdir ./tables/1m/99%
mkdir ./tables/1m/99.7%
mkdir ./tables/1m/odwrotnie
mkdir ./tables/1m/losowe

for((i=401;i<=500;i++)) do
	./gen $i 1000000 0   > ./tables/1m/losowe/tab$i.txt
	./gen $i 1000000 250 > ./tables/1m/25%/tab$i.txt
	./gen $i 1000000 500 > ./tables/1m/50%/tab$i.txt
	./gen $i 1000000 750 > ./tables/1m/75%/tab$i.txt
	./gen $i 1000000 950 > ./tables/1m/95%/tab$i.txt
	./gen $i 1000000 990 > ./tables/1m/99%/tab$i.txt
	./gen $i 1000000 997 > ./tables/1m/99.7%/tab$i.txt
	./gen $i 1000000 -1  > ./tables/1m/odwrotnie/tab$i.txt
done
echo "1m done"
