#include<initializer_list>
#define PRIME 31

unsigned int Hash(const std::string& str, unsigned int M)
{
	unsigned int res = 0;
	for(unsigned int i = 0; i < str.size() ; i++)
		res = (res * PRIME + (unsigned int)(str[i] + 1))%M;
	return res;
}

template < typename KeyType , typename ValueType >
HashMap<KeyType, ValueType>::HashMap()
{
	this->NoE = 0;
	this->NoB = 16;
	this->load_factor = 75;
	this->HashTab = new List< std::pair<KeyType, ValueType> > [NoB];
}

template < typename KeyType , typename ValueType >
HashMap<KeyType, ValueType>::HashMap(const std::initializer_list<std::pair<KeyType, ValueType> >& list)
{
	this->NoE = 0;
	this->NoB = 16;
	this->load_factor = 75;
	this->HashTab = new List< std::pair<KeyType, ValueType> > [NoB];
	for(auto it = list.begin(); it!= list.end();it++)
		this->insert((*it).first, (*it).second);
}

template < typename KeyType , typename ValueType >
HashMap<KeyType, ValueType>::~HashMap()
{
	for(unsigned int i = 0; i < this->NoB; i++)
		(*(this->HashTab + i)).~List();
	delete [] HashTab;
}


template < typename KeyType , typename ValueType >
void HashMap<KeyType, ValueType>::insert ( const KeyType & key , const ValueType & value )
{
	unsigned int HashKey = Hash(key, this->NoB);
	List< std::pair< KeyType, ValueType > >& list = *(this->HashTab + HashKey);
	
	for(auto it = list.begin(); it != list.end();it++)
		if((*it).first == key)
		{
			(*it).second = value;
			return;
		}

	list.push_front({key, value});
	this->NoE++;

	if( this->NoE > this->NoB * this->load_factor / 100)
	{
		List< std::pair<KeyType,ValueType> >* OldHashTab = this->HashTab;
		this->NoB *= 2;
		this->NoE  = 0;
		this->HashTab = new List< std::pair<KeyType, ValueType> > [NoB];
		for(unsigned int i = 0; i < NoB/2; i++)
		{
			while(!(*(OldHashTab + i)).empty())
			{
				this->insert( (*(OldHashTab+i))[0].first, (*(OldHashTab+i))[0].second );
				(*(OldHashTab + i)).pop_front();
			}
			(*(OldHashTab + i)).~List();
		}
		delete [] OldHashTab;
	}
	return;
}

template < typename KeyType , typename ValueType >
ValueType& HashMap<KeyType, ValueType>::operator[] ( const KeyType & key )
{
	unsigned int HashKey = Hash(key, this->NoB);
	List< std::pair< KeyType, ValueType > >& list = *(this->HashTab + HashKey);
	for(auto it = list.begin(); it != list.end(); it++)
		if((*it).first == key)
			return (*it).second;
	std::cerr << "HashMap range error: No element assigned to given key";
	exit(2);
}

template < typename KeyType , typename ValueType >
const ValueType& HashMap<KeyType, ValueType>::operator[] ( const KeyType & key ) const
{
	unsigned int HashKey = Hash(key, this->NoB);
	List< std::pair< KeyType, ValueType > >& list = *(this->HashTab + HashKey);
	for(auto it = list.cbegin(); it != list.cend(); it++)
		if((*it).first == key)
			return (*it).second;
	std::cerr << "HashMap range error: No element assigned to given key";
	exit(2);
}

template < typename KeyType , typename ValueType >
void HashMap<KeyType, ValueType>::remove ( const KeyType & key )
{
	unsigned int HashKey = Hash(key, this->NoB);
	List< std::pair< KeyType, ValueType > >& list = *(this->HashTab + HashKey);
	
	for(unsigned int i = 0;i < list.size(); i++)
		if(list[i].first == key)
		{
			list.remove_by_index(i);
			return;
		}

	return;
}


