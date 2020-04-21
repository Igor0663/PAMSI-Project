template< typename Et >
Dijkstra_result<Et>::Dijkstra_result( const Dijkstra_result<Et>& D )
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
Dijkstra_result<Et>& Dijkstra_result<Et>::operator =(const Dijkstra_result<Et>& D)
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
Dijkstra_result<Et> Dijkstra(Graph_base<Et>& G, unsigned int s, Et INF)
{
	Dijkstra_result<Et> r = Dijkstra_result<Et>(G.size(), s);
	Priority_queue< std::pair< Et, unsigned int>, std::less<std::pair<Et, unsigned int> > > Q;

	for(unsigned int i = 0; i < G.size();i++)
	{
		r.dist[i] = INF;
		r.prev[i] = -1;
	}

	r.dist[s - 1] = Et(0);
	Q.push( { r.dist[s -1], s} );
	while(!Q.empty())
	{
		std::pair<Et, unsigned int> t = Q.pop();
		unsigned int v = t.second;
		Et dist = t.first;
		if( dist > r.dist[v - 1])
			continue;
		List<std::pair<unsigned int, Et> > L = G.incidentEdges(v);
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
	return r;
}
