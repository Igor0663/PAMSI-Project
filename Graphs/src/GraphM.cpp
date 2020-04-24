template<typename Et>
GraphM<Et>::GraphM(unsigned int m)
{
	this->NoV = m;
	this->AdjMat = matrix<char>(m, m);
	this->E_content = matrix<Et>(m, m);
}

template<typename Et>
bool GraphM<Et>::areAdjacent(unsigned int v, unsigned int w) const
{
	return this->AdjMat(v - 1, w - 1);
}


template<typename Et>
void GraphM<Et>::insertEdge(unsigned int v, unsigned int w, Et o)
{
	this->AdjMat(v - 1, w - 1) = true;
	this->E_content(v - 1, w - 1) = o;
	return;
}

template<typename Et>
std::vector<std::pair<unsigned int, Et> > GraphM<Et>::incidentEdges(unsigned int v) const
{
	std::vector<std::pair<unsigned int, Et> > N;
	for(unsigned int i = 1; i <= this->NoV;i++)
		if( this->areAdjacent( v, i) )
			N.push_back({i, this->E_content( v - 1, i - 1)});
	return N;
}
