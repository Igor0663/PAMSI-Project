#ifndef GRAPH_ALGORITHMS_HH
#define GRAPH_ALGORITHMS_HH

#include"GraphM.hh"
#include"GraphL.hh"
#include"Priority_queue.hh"

template<typename Et>
struct Dijkstra_result
{
	Dijkstra_result(unsigned int n = 1, unsigned int S = 1){this->n = n; this->start_vertex = S; dist = new Et[n]; prev = new int[n];}
	Dijkstra_result(const Dijkstra_result& D);
	Dijkstra_result& operator =(const Dijkstra_result& D);
	~Dijkstra_result(){delete[] dist; delete[] prev;}
	unsigned int start_vertex;
	unsigned int n;
	Et* dist;
	int* prev;

};

template<typename Et>
Dijkstra_result<Et> Dijkstra(Graph_base<Et>& G, unsigned int s, Et INF = (Et)(-1) );

#include"../src/Graph_Algorithms.cpp"

#endif
