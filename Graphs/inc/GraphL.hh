#ifndef GRAPHL_HH
#define GRAPHL_HH
#include"Graph_base.hh"

template< typename Et >
class GraphL: public Graph_base<Et>
{
	public:
		GraphL(unsigned int i = 1);
		bool areAdjacent(unsigned int v, unsigned int w) const override;
		void insertEdge(unsigned int v, unsigned int w, Et o) override;
		std::vector< std::pair< unsigned int , Et> > incidentEdges(unsigned int v) const override;

	private:
		std::vector< std::vector<std::pair< unsigned int, Et> > > V; // vertices described with adjanced edges

};

#include"../src/GraphL.cpp"

#endif
