#include<iostream>
#include"../inc/Sorting_algorithms.hh"
using namespace std;

int main()
{
	int N;
	cin >> N;
	int *tab = new int[N];

	for(int i = 0; i < N;i++)
		cin >> tab[i];
	mergesort(tab, tab + N);
	
	cout << N << "\n"; 
	for(int i = 0; i < N;i++)
		cout <<  tab[i] << " ";
	
	delete[] tab;
	return 0;
}
