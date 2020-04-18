#include"../inc/Graph_Algorithms.hh"

Dijkstra_result::Dijkstra_result( const Dijkstra_result& D )
{
	this->n = D.n;
	this->start_vertex = D.start_vertex;
	this->dist = new int[this->n];
	this->prev = new int[this->n];	
	for(unsigned int i = 0; i < this->n; i++)
	{
		this->dist[i] = D.dist[i];
		this->prev[i] = D.prev[i];
	}
}

Dijkstra_result& Dijkstra_result::operator =(const Dijkstra_result& D)
{
	this->n = D.n;
	this->start_vertex = D.start_vertex;
	delete this->dist;
	delete this-> prev;
	this->dist = new int[this->n];
	this->prev = new int[this->n];	
	for(unsigned int i = 0; i < this->n; i++)
	{
		this->dist[i] = D.dist[i];
		this->prev[i] = D.prev[i];
	}
	return *this;
}

Dijkstra_result Dijkstra(GraphL G, unsigned int s)
{
	Dijkstra_result r = Dijkstra_result(G.size(), s);
	Priority_queue< std::pair< int, unsigned int>, std::less<std::pair<int, unsigned int> > > Q;

	for(unsigned int i = 0; i < G.size();i++)
	{
		r.dist[i] = -1;
		r.prev[i] = -1;
	}

	r.dist[s - 1] = 0;
	Q.push( { 0, s} );
	while(!Q.empty())
	{
		std::pair<int, unsigned int> t = Q.pop();
		unsigned int v = t.second;
		int dist = t.first;
		if( dist > r.dist[v - 1])
			continue;
		List<std::pair<unsigned int, int> > L = G.incidentEdges(v);
		for( auto it = L.begin(); it != L.end(); it++)
		{
			unsigned int a = (*it).first;
			int E_len = (*it).second;
		       	if( r.dist[a - 1] == -1 or r.dist[v - 1] + E_len < r.dist[a - 1] )
			{
				r.dist[a - 1] = r.dist[v - 1] + E_len;
				r.prev[a - 1] = v - 1;
				Q.push({r.dist[a - 1], a});
			}	
		}	
	}
	return r;
}



Dijkstra_result Dijkstra(GraphM G, unsigned int s)
{
	Dijkstra_result r = Dijkstra_result(G.size(), s);
	Priority_queue< std::pair< int, unsigned int>, std::less<std::pair<int, unsigned int> > > Q;

	for(unsigned int i = 0; i < G.size();i++)
	{
		r.dist[i] = -1;
		r.prev[i] = -1;
	}

	r.dist[s - 1] = 0;
	Q.push( { 0, s} );
	while(!Q.empty())
	{
		std::pair<int, unsigned int> t = Q.pop();
		unsigned int v = t.second;
		int dist = t.first;
		if( dist > r.dist[v - 1])
			continue;
		List<std::pair<unsigned int, int> > L = G.incidentEdges(v);
		for( auto it = L.begin(); it != L.end(); it++)
		{
			unsigned int a = (*it).first;
			int E_len = (*it).second;
		       	if( r.dist[a - 1] == -1 or r.dist[v - 1] + E_len < r.dist[a - 1] )
			{
				r.dist[a - 1] = r.dist[v - 1] + E_len;
				r.prev[a - 1] = v - 1;
				Q.push({r.dist[a - 1], a});
			}	
		}	
	}
	return r;
}
