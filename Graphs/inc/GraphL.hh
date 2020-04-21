#ifndef GRAPHL_HH
#define GRAPHL_HH
#include"Graph_base.hh"

template< typename Et >
class GraphL: public Graph_base<Et>
{
	public:
		GraphL(unsigned int i = 1);
		~GraphL();

		bool areAdjacent(unsigned int v, unsigned int w) const override;
		void insertEdge(unsigned int v, unsigned int w, Et o) override;
		List<std::pair<unsigned int, Et> > incidentEdges(unsigned int v) const override;

	private:
		List<std::pair<unsigned int,Et> >* V; // array of vetices holding edges adjanced to them

};

#include"../src/GraphL.cpp"

#endif
