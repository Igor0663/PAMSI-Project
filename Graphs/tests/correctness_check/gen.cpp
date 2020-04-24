#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

int main( int argc, char **argv)
{
	if( argc != 5 )
	{
		std::cerr << "Wrong number of arguments!";
		return 1;
	}
	
	std::ofstream file(argv[4]);

	srand(atoi(argv[1]));
	unsigned int N = atoi(argv[2]);
	unsigned int D = atoi(argv[3]);
	unsigned int M = D * N * (N - 1) / 100;
	unsigned int S = rand()%N + 1;
	file << N << " " << M << " " << S << "\n";
	
	unsigned int* NoE = new unsigned int[N];
	for(unsigned int i = 0; i < N;i++) 
	{
		NoE[i] = (N - 1 ) * D / 200;
		M -= NoE[i];
	}
	
	std::vector<unsigned int> V;
	for(unsigned int i = 0 ; i < N; i++)
		V.push_back(i);
	std::random_shuffle(V.begin(), V.end());

	while(M)
	{
		for(unsigned int i = 0 ; i < N; i++)
		{
			unsigned int k = rand()%( std::min( N -NoE[V[i]], M+1));
			NoE[V[i]] += k;
			M -= k;
		}
	}
	for(unsigned int i = 0; i < N;i++)
	{
		std::random_shuffle(V.begin(), V.end());
		auto it = V.begin();
		while(NoE[i])
		{
			if(*it  == i)
			{
				it++;
				continue;
			}
			file << i + 1 << " " << *it + 1 <<" "<< rand()%1000 + 1 << "\n";
			it++;
			NoE[i]--;
		}
	}
	delete[] NoE;
	return 0;
}
