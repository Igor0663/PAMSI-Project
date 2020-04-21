#include"../inc/GraphL.hh"

GraphL::GraphL(unsigned int m)
{
	this->NoV = m;
	this->V = new List<std::pair<unsigned int, int> > [this->NoV];
}

GraphL::~GraphL()
{
	for(unsigned int j = 0; j < this->NoV;j++)
		this->V[j].~List();
	delete [] this->V;
}

bool GraphL::areAdjacent(unsigned int v, unsigned int w) const
{
	for(auto it = V[v-1].cbegin(); it != V[v - 1].cend();it++)
		if( (*it).first == w ) return true;
	return false;
}


void GraphL::insertEdge(unsigned int v, unsigned int w, int o)
{
	this->V[v -1].push_back({w,o});
}

List<std::pair<unsigned int,int> > GraphL::incidentEdges(unsigned int v) const
{
	return this->V[v-1];
}
