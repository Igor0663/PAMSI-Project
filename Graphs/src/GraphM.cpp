#include"../inc/GraphM.hh"

GraphM::GraphM(unsigned int m)
{
	this->NoV = m;
	this->AdjMat = new bool*[m];
       	for(unsigned int i = 0; i < m; i++)
		this->AdjMat[i] = new bool[m];
	
	for(unsigned int i = 0; i < m; i++)
		for(unsigned int j = 0; j < m; j++)
			this->AdjMat[i][j] = false;
	
	this->E_content = new int*[m];
       	for(unsigned int i = 0; i < m ; i++)
		this->E_content[i] = new int[m];
}

GraphM::~GraphM()
{
	 for(unsigned int i = 0; i < this->size(); i++)
		delete [] this->AdjMat[i];
	 delete [] this->AdjMat;

	 for(unsigned int i = 0; i < this->size(); i++)
		delete [] this->E_content[i];
	 delete [] this->E_content;
}

bool GraphM::areAdjacent(unsigned int v, unsigned int w) const
{
	return this->AdjMat[v - 1][w - 1];
}


void GraphM::insertEdge(unsigned int v, unsigned int w, int o)
{
	this->AdjMat[v - 1][w - 1] = true;
	this->E_content[v - 1][w - 1] = o;
	return;
}

List<std::pair<unsigned int,int> > GraphM::incidentEdges(unsigned int v) const
{
	List<std::pair<unsigned int, int> > L;
	for(unsigned int i = 1;i <= this->size(); i++)
		if(this->AdjMat[v-1][i-1]) L.push_back({i,this->E_content[v - 1][i - 1]});
	return L;
}
