#include"../../inc/Graph_Algorithms.hh"
#include<iostream>
#include<fstream>

int main(int argc, char** argv)
{
	if(argc != 2)
	{
		std::cerr<<"Wrong number of parameters!\n";
		return 1;
	}
	std::ifstream file(argv[1]);
	unsigned int N, M, S;
	file >> N >> M >> S;

	auto G = GraphM<int>(N);
	for(unsigned int i = 0;i < M;i++)
	{
		unsigned int a, b, c;
		file >> a >> b >> c;
		G.insertEdge(a, b, c);
	}

	auto A = Find_dist_result<int>(N, S);
	auto B = Find_dist_result<int>(N, S);

	Dijkstra(G, S, A);
	BellmanFord(G, S, B);
	for(unsigned  i = 0; i < G.size();i++)
	{
		if(A.dist[i] != B.dist[i])
			return 1;
		std::cout<< A.dist[i] <<" " << B.dist[i] <<"\n";
	}
	return 0;
}
