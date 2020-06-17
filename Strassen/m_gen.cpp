#include<iostream>
using namespace std;

int main(int argc, char* argv[])
{
	if(argc != 5)
	{
		std::cerr << "Not enough arguments, expected 4, given " << argc -1;
		return 1;
	}
	int seed = atoi(argv[1]);
	int rows = atoi(argv[2]);
	int cols = atoi(argv[3]);
	int maxint = atoi(argv[4]);
	srand(seed);
	std::cout << rows << " " << cols <<"\n";
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			bool sign = rand()%2;
			int Int = rand()%(maxint + 1);
			if(sign)
				cout<<Int << " ";
			else
				cout<<-Int << " "; 
		}
		cout <<"\n";
	}

	return 0;
}
