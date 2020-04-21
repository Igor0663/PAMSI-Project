#ifndef GRAPHL_HH
#define GRAPHL_HH
#include"Graph_base.hh"

class GraphL: public Graph_base
{
	public:
		GraphL(unsigned int i = 1);
		~GraphL();

		bool areAdjacent(unsigned int v, unsigned int w) const override;
		void insertEdge(unsigned int v, unsigned int w, int o) override;
		List<std::pair<unsigned int,int> > incidentEdges(unsigned int v) const override;

	private:
		List<std::pair<unsigned int,int> >* V; // array of vetices holding edges adjanced to them

};


#endif
