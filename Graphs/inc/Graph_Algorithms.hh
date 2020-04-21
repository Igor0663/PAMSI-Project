#include"GraphM.hh"
#include"GraphL.hh"
#include"Priority_queue.hh"

struct Dijkstra_result
{
	Dijkstra_result(unsigned int n = 1, unsigned int S = 1){this->n = n; this->start_vertex = S; dist = new int[n]; prev = new int[n];}
	Dijkstra_result(const Dijkstra_result& D);
	Dijkstra_result& operator =(const Dijkstra_result& D);
	~Dijkstra_result(){delete dist; delete prev;}
	unsigned int start_vertex;
	unsigned int n;
	int* dist;
	int* prev;

};


Dijkstra_result Dijkstra(Graph_base& G, unsigned int s);

