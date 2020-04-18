#ifndef GRAPHM_HH
#define GRAPHM_HH
#include"List.hh"

class GraphM
{
	public:
		GraphM(unsigned int i = 1);
		~GraphM();

		bool areAdjacent(unsigned int v, unsigned int w) const;
		void insertEdge(unsigned int v, unsigned int w, int o);
		List<std::pair<unsigned int,int> > incidentEdges(unsigned int v) const;
		unsigned int size() const {return this->NoV;}

	private:
		unsigned int NoV; // number of vertices
		bool** AdjMat; // Adjacency matrix
		int** E_content;// Content of edges

};


#endif
