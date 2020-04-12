#include<iostream>
#include<algorithm>

using namespace std;



int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	if(argc != 4) // program_name, random_number_generator_seed, size of table, structure_of_output
	{
		cerr << "Invalid number of parameters\n";
		return 1;
	}
	srand(atoi(argv[1]));
	
	unsigned int N = atoi(argv[2]);
	cout << N << "\n";
	
	int* tab = new int[N];
	
	int out_s = atoi(argv[3]);
		
	for(unsigned int i = 0; i < N; i++)
		tab[i] = rand()%200001 - 100000;

	if(0 <= out_s && out_s <= 1000)
		sort(tab, tab + max(N*out_s/1000, 1u) );
	if(out_s == -1)
		sort(tab, tab + N, std::greater<int>() );

	for(unsigned int i = 0; i < N; i++)
		cout << tab[i] << " ";

	
	delete[] tab;
	return 0;
}
