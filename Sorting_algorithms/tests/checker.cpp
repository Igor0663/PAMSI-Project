#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	int *tab = new int[N];

	for(int i = 0; i < N;i++)
		cin >> tab[i];
	for(int i = 0; i < N - 1;i++)
		if(tab[i] > tab[i+1])
		{
			delete[] tab;
			return 1;
		}
	delete[] tab;
	return 0;
}
