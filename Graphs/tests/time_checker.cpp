#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include<chrono>
#include"../inc/Graph_Algorithms.hh"

using namespace std::chrono_literals;

unsigned int D;
unsigned int N;

int f()
{
	static unsigned int count = 0;
	static unsigned int i_count = 0;
	static unsigned int j_count = 0;


	if(i_count == j_count)
	{
		j_count = (j_count + 1)%N;
		if(j_count == 0)
			i_count = (i_count + 1)%N;
		return -1;
	}
	j_count = (j_count + 1)%N;
	if(j_count == 0)
		i_count = (i_count + 1)%N;
	
	if(count % 100 < D)
	{
		count = (count + 1) % 100;
		return std::rand()%1000 + 1;
	}
	count = (count + 1) % 100;
	return -1;
}

int main(int argc, char *argv[])
{
	if( argc != 5)
	{
		std::cerr << "Wrong number of arguments";
		return 1;
	}
	std::vector<int> matrix;
	srand(atoi(argv[1]));
	N = atoi(argv[2]);
	D = atoi(argv[3]);
	unsigned int S = rand()%N + 1;
	bool B = atoi(argv[4]);
	matrix.resize(N*N);
	std::generate(matrix.begin(), matrix.end(), f );
	if(B)
	{
		auto G = GraphL<int>(N);
		auto A = Find_dist_result<int>(N, S);
		for(unsigned int i = 0; i < N;i++)
			for(unsigned int j = 0; j < N;j++)
				if(matrix[i*N + j]!= -1)
					G.insertEdge(i + 1, j + 1, matrix[i*N + j]);
		
		std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
		Dijkstra(G, S, A);
		std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
		
		std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
	
		std::cout << std::fixed << time_span.count() << "\n";
	}
	else
	{
		auto G = GraphM<int>(N);
		auto A = Find_dist_result<int>(N, S);
		for(unsigned int i = 0; i < N;i++)
			for(unsigned int j = 0; j < N;j++)
				if(matrix[i*N + j]!= -1)
					G.insertEdge(i + 1, j + 1, matrix[i*N + j]);
		
		std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
		Dijkstra(G, S, A);
		std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
		
		std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
	
		std::cout << std::fixed << time_span.count() << "\n";
	}
	return 0;
}
