#ifndef GRAPHL_HH
#define GRAPHL_HH
#include"List.hh"

class GraphL
{
	public:
		GraphL(unsigned int i = 1);
		~GraphL();

		bool areAdjacent(unsigned int v, unsigned int w) const;
		void insertEdge(unsigned int v, unsigned int w, int o);
		List<std::pair<unsigned int,int> >& incidentEdges(unsigned int v) const;
		unsigned int size() const {return this->NoV;}

	private:
		unsigned int NoV; // number of vertices
		List<std::pair<unsigned int,int> >* V; // array of vetices holding edges adjanced th]o them

};


#endif
