#ifndef GRAPH_BASE_HH 
#define GRAPH_BASE_HH
#include"List.hh"

template<typename Et>
class Graph_base
{
	public:
		Graph_base(unsigned int i =1): NoV(i) {}
		virtual bool areAdjacent(unsigned int v, unsigned int w) const = 0;
		virtual void insertEdge(unsigned int v, unsigned int w, Et o) = 0;
		virtual List<std::pair<unsigned int,Et> > incidentEdges(unsigned int v) const =0;
		unsigned int size() const {return this->NoV;}
	protected:
		unsigned int NoV; //number of vertices
};


#endif
