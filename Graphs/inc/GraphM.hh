#ifndef GRAPHM_HH
#define GRAPHM_HH
#include"Graph_base.hh"

template<typename Et>
class GraphM: public Graph_base<Et>
{
	public:
		GraphM(unsigned int i = 1);
		~GraphM();

		bool areAdjacent(unsigned int v, unsigned int w) const override;
		void insertEdge(unsigned int v, unsigned int w, Et o) override;
		List<std::pair<unsigned int, Et> > incidentEdges(unsigned int v) const override;

	private:
		bool** AdjMat; // Adjacency matrix
		Et** E_content;// Content of edges

};

#include"../src/GraphM.cpp"

#endif
