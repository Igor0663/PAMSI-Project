template< typename Et >
Find_dist_result<Et>::Find_dist_result( const Find_dist_result<Et>& D )
{
	this->n = D.n;
	this->start_vertex = D.start_vertex;
	this->dist = new Et[this->n];
	this->prev = new int[this->n];	
	for(unsigned int i = 0; i < this->n; i++)
	{
		this->dist[i] = D.dist[i];
		this->prev[i] = D.prev[i];
	}
}

template<typename Et>
Find_dist_result<Et>& Find_dist_result<Et>::operator =(const Find_dist_result<Et>& D)
{
	this->n = D.n;
	this->start_vertex = D.start_vertex;
	delete [] this->dist;
	delete [] this-> prev;
	this->dist = new Et[this->n];
	this->prev = new int[this->n];	
	for(unsigned int i = 0; i < this->n; i++)
	{
		this->dist[i] = D.dist[i];
		this->prev[i] = D.prev[i];
	}
	return *this;
}

template<typename Et>
void Dijkstra(Graph_base<Et>& G, unsigned int s, Find_dist_result<Et>& r, Et INF, Et ZERO)
{
	std::priority_queue<std::pair< Et, unsigned int>, std::vector<std::pair<Et, unsigned int> >,std::greater<std::pair<Et, unsigned int> > > Q;

	for(unsigned int i = 0; i < G.size();i++)
	{
		r.dist[i] = INF;
		r.prev[i] = -1;
	}

	r.dist[s - 1] = ZERO;
	Q.push( { r.dist[s -1], s} );
	while(!Q.empty())
	{
		std::pair< Et, unsigned int > t = Q.top();
		Q.pop();
		unsigned int v = t.second;
		Et dist = t.first;
		if( dist > r.dist[v - 1])
			continue;
		auto L = G.incidentEdges(v);
		for( auto it = L.begin(); it != L.end(); it++)
		{
			unsigned int a = (*it).first;
			Et E_len = (*it).second;
		       	if( r.dist[a - 1] == INF or r.dist[v - 1] + E_len < r.dist[a - 1] )
			{
				r.dist[a - 1] = r.dist[v - 1] + E_len;
				r.prev[a - 1] = v - 1;
				Q.push({r.dist[a - 1], a});
			}	
		}	
	}
	return;
}

template<typename Et>
void BellmanFord(Graph_base<Et>& G, unsigned int s,Find_dist_result<Et>& r, Et INF, Et ZERO)
{
	for(unsigned int i = 0; i < G.size();i++)
	{
		r.dist[i] = INF;
		r.prev[i] = -1;
	}
	r.dist[s - 1] = ZERO;
	for(unsigned int i = 1; i < G.size();i++)
	{
		for(unsigned int j = 1; j <= G.size(); j++)
		{
			if(r.dist[j - 1] == INF)
				continue;
			auto L = G.incidentEdges(j);
			for(auto it = L.begin(); it != L.end(); it++)
			{
				unsigned int a = (*it).first;
				Et E_len = (*it).second;
				if( r.dist[a -1] == INF or r.dist[a - 1] > r.dist[j - 1] + E_len )
				{
					r.dist[a - 1] = r.dist[j - 1] + E_len;
					r.prev[a - 1] = j - 1;
				}
			}
		}
	}
	return;
}
