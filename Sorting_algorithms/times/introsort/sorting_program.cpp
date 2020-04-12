#include<iostream>
#include<chrono>
#include"../../inc/Sorting_algorithms.hh"
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	unsigned int N;
	
	cin >> N;
	
	int* tab = new int[N];
	for(unsigned int i = 0; i < N; i++)
		cin >> tab[i];
	
	auto start = chrono::steady_clock::now();
	introsort(tab, tab + N);
	auto end = chrono::steady_clock::now();
	
	chrono::duration<double> time_in_seconds = end-start;

	cout << time_in_seconds.count() << "\n";
	
	delete[] tab;
	return 0;
}
