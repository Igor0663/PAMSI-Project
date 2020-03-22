#ifndef HASHMAP_HH
#define HASPMAP_HH

#include"List.hh"

template < typename KeyType , typename ValueType >
class HashMap
{
	private:
		List< std::pair<KeyType,ValueType> >* HashTab;
		unsigned int load_factor; //its value is load_factor/100, but its easier to store it in int form
		unsigned int NoE; //Number of Elements ( <key, value> pairs stored int HashTab )
		unsigned int NoB; // Number of Buckets (size of HashTab)
	public:
		HashMap();
		HashMap(const std::initializer_list<std::pair<KeyType, ValueType> >& list);
		~HashMap();
		void insert ( const KeyType & key , const ValueType & value );
		ValueType & operator[] ( const KeyType & key );
		const ValueType & operator[] ( const KeyType & key ) const;
		void remove ( const KeyType & key );
		unsigned int size() const {return this->NoE;}
		unsigned int number_of_buckets() const {return this->NoB;} 
};

#include"../src/HashMap.cpp"

#endif
