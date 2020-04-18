#include"GraphM.hh"
#include"GraphL.hh"


struct Dijkstra_result
{
	Dijkstra_result(unsigned int n = 1, unsigned int S = 1);
	unsigned int start_vertex;
	int* dist;
	int* prev;

}



Dijkstra_result Dijkstra(GraphL G, unsigned int s);
Dijkstra_result Dijkstra(GraphM G, unsigned int s);

