#ifndef GRAPH_ALGORITHMS_HH
#define GRAPH_ALGORITHMS_HH

#include"GraphM.hh"
#include"GraphL.hh"
#include"Priority_queue.hh"

template<typename Et>
struct Find_dist_result
{
	Find_dist_result(unsigned int n = 1, unsigned int S = 1){this->n = n; this->start_vertex = S;neg_cycle = false; dist = new Et[n]; prev = new int[n];}
	Find_dist_result(const Find_dist_result& D);
	Find_dist_result& operator =(const Find_dist_result& D);
	~Find_dist_result(){delete[] dist; delete[] prev;}
	unsigned int start_vertex;
	unsigned int n;
	bool neg_cycle;
	Et* dist;
	int* prev;

};

template<typename Et>
Find_dist_result<Et> Dijkstra(Graph_base<Et>& G, unsigned int s, Et INF = (Et)(-1), Et ZERO = (Et)(0) );

template<typename Et>
Find_dist_result<Et> BellmanFord(Graph_base<Et>& G, unsigned int S, Et INF = (Et)(-1), Et ZERO = (Et)(0) );

#include"../src/Graph_Algorithms.cpp"

#endif
