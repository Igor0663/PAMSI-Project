#!/bin/bash

S1='100'
S2='500'
S3='1000'
S4='5000'
S5='10000'

D1='25%'
D2='50%'
D3='75%'
D4='100%'

rm -r ./Times
mkdir ./Times

mkdir ./Times/GraphM
mkdir ./Times/GraphL

mkdir ./Times/GraphL/$S1
mkdir ./Times/GraphL/$S2
mkdir ./Times/GraphL/$S3
mkdir ./Times/GraphL/$S4
mkdir ./Times/GraphL/$S5

mkdir ./Times/GraphM/$S1
mkdir ./Times/GraphM/$S2
mkdir ./Times/GraphM/$S3
mkdir ./Times/GraphM/$S4
mkdir ./Times/GraphM/$S5

for((i=1;i<=100;i++)) do
	./time_checker $i $S1 $D1 0 >> ./Times/GraphM/$S1/$D1.txt
	./time_checker $i $S1 $D1 1 >> ./Times/GraphL/$S1/$D1.txt
	
	./time_checker $i $S2 $D1 0 >> ./Times/GraphM/$S2/$D1.txt
	./time_checker $i $S2 $D1 1 >> ./Times/GraphL/$S2/$D1.txt
	
	./time_checker $i $S3 $D1 0 >> ./Times/GraphM/$S3/$D1.txt
	./time_checker $i $S3 $D1 1 >> ./Times/GraphL/$S3/$D1.txt
	
	./time_checker $i $S4 $D1 0 >> ./Times/GraphM/$S4/$D1.txt
	./time_checker $i $S4 $D1 1 >> ./Times/GraphL/$S4/$D1.txt
	
	./time_checker $i $S5 $D1 0 >> ./Times/GraphM/$S5/$D1.txt
	./time_checker $i $S5 $D1 1 >> ./Times/GraphL/$S5/$D1.txt
	
	echo "25%: $i out of 100 done"
done

echo "25% done!"

for((i=101;i<=200;i++)) do
	./time_checker $i $S1 $D2 0 >> ./Times/GraphM/$S1/$D2.txt
	./time_checker $i $S1 $D2 1 >> ./Times/GraphL/$S1/$D2.txt
	
	./time_checker $i $S2 $D2 0 >> ./Times/GraphM/$S2/$D2.txt
	./time_checker $i $S2 $D2 1 >> ./Times/GraphL/$S2/$D2.txt
	
	./time_checker $i $S3 $D2 0 >> ./Times/GraphM/$S3/$D2.txt
	./time_checker $i $S3 $D2 1 >> ./Times/GraphL/$S3/$D2.txt
	
	./time_checker $i $S4 $D2 0 >> ./Times/GraphM/$S4/$D2.txt
	./time_checker $i $S4 $D2 1 >> ./Times/GraphL/$S4/$D2.txt
	
	./time_checker $i $S5 $D2 0 >> ./Times/GraphM/$S5/$D2.txt
	./time_checker $i $S5 $D2 1 >> ./Times/GraphL/$S5/$D2.txt
	
	echo "50%: $i out of 200 done"
done

echo "50% done!"

for((i=201;i<=300;i++)) do
	./time_checker $i $S1 $D3 0 >> ./Times/GraphM/$S1/$D3.txt
	./time_checker $i $S1 $D3 1 >> ./Times/GraphL/$S1/$D3.txt
	
	./time_checker $i $S2 $D3 0 >> ./Times/GraphM/$S2/$D3.txt
	./time_checker $i $S2 $D3 1 >> ./Times/GraphL/$S2/$D3.txt
	
	./time_checker $i $S3 $D3 0 >> ./Times/GraphM/$S3/$D3.txt
	./time_checker $i $S3 $D3 1 >> ./Times/GraphL/$S3/$D3.txt
	
	./time_checker $i $S4 $D3 0 >> ./Times/GraphM/$S4/$D3.txt
	./time_checker $i $S4 $D3 1 >> ./Times/GraphL/$S4/$D3.txt
	
	./time_checker $i $S5 $D3 0 >> ./Times/GraphM/$S5/$D3.txt
	./time_checker $i $S5 $D3 1 >> ./Times/GraphL/$S5/$D3.txt
	echo "75%: $i out of 300 done"
done

echo "75% done!"

for((i=301;i<=400;i++)) do
	./time_checker $i $S1 $D4 0 >> ./Times/GraphM/$S1/$D4.txt
	./time_checker $i $S1 $D4 1 >> ./Times/GraphL/$S1/$D4.txt
	
	./time_checker $i $S2 $D4 0 >> ./Times/GraphM/$S2/$D4.txt
	./time_checker $i $S2 $D4 1 >> ./Times/GraphL/$S2/$D4.txt
	
	./time_checker $i $S3 $D4 0 >> ./Times/GraphM/$S3/$D4.txt
	./time_checker $i $S3 $D4 1 >> ./Times/GraphL/$S3/$D4.txt
	
	./time_checker $i $S4 $D4 0 >> ./Times/GraphM/$S4/$D4.txt
	./time_checker $i $S4 $D4 1 >> ./Times/GraphL/$S4/$D4.txt
	
	./time_checker $i $S5 $D4 0 >> ./Times/GraphM/$S5/$D4.txt
	./time_checker $i $S5 $D4 1 >> ./Times/GraphL/$S5/$D4.txt
	
	echo "100%: $i out of 400 done"
done

echo "100% done!"

echo "All times measured!"
