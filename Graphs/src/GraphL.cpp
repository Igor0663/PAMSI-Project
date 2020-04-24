template< typename Et>
GraphL<Et>::GraphL(unsigned int m)
{
	this->NoV = m;
	this-> V.resize(m);
}

template< typename Et>
bool GraphL<Et>::areAdjacent(unsigned int v, unsigned int w) const
{
	for(auto it = V[v-1].cbegin(); it != V[v - 1].cend();it++)
		if( it->first == w ) return true;
	return false;
}

template<typename Et>
void GraphL<Et>::insertEdge(unsigned int v, unsigned int w, Et o)
{
	this->V[v -1].push_back({w,o});
}

template< typename Et>
std::vector< std::pair<unsigned int, Et> > GraphL<Et>::incidentEdges(unsigned int v) const
{
	return this->V[v-1];
}
