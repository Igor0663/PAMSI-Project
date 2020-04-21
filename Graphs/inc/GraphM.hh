#ifndef GRAPHM_HH
#define GRAPHM_HH
#include"Graph_base.hh"

class GraphM: public Graph_base
{
	public:
		GraphM(unsigned int i = 1);
		~GraphM();

		bool areAdjacent(unsigned int v, unsigned int w) const override;
		void insertEdge(unsigned int v, unsigned int w, int o) override;
		List<std::pair<unsigned int,int> > incidentEdges(unsigned int v) const override;

	private:
		bool** AdjMat; // Adjacency matrix
		int** E_content;// Content of edges

};


#endif
