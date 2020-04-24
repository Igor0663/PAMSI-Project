#ifndef GRAPH_ALGORITHMS_HH
#define GRAPH_ALGORITHMS_HH

#include"GraphM.hh"
#include"GraphL.hh"
#include<queue>

template<typename Et>
struct Find_dist_result
{
	Find_dist_result(unsigned int n = 1, unsigned int S = 1){this->n = n; this->start_vertex = S; dist = new Et[n]; prev = new int[n];}
	Find_dist_result(const Find_dist_result& D);
	Find_dist_result& operator =(const Find_dist_result& D);
	~Find_dist_result(){delete[] dist; delete[] prev;}
	unsigned int start_vertex;
	unsigned int n;
	Et* dist;
	int* prev;

};

template<typename Et>
void Dijkstra(Graph_base<Et>& G, unsigned int s, Find_dist_result<Et>& r, Et INF = (Et)(-1), Et ZERO = (Et)(0) );

template<typename Et>
void BellmanFord(Graph_base<Et>& G, unsigned int s,Find_dist_result<Et>& r, Et INF = (Et)(-1), Et ZERO = (Et)(0) );

#include"../src/Graph_Algorithms.cpp"

#endif
