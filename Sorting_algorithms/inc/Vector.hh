#ifndef VECTOR_HH
#define VECTOR_HH

#include<initializer_list>

template< typename T >
class Vector
{
	private:
		T* array;
		unsigned int Cap;
		unsigned int NoE;
	public:
		Vector();
		Vector(const Vector<int>& NewVec);
		Vector(const std::initializer_list<T>& list);
		~Vector();
		bool empty() const {return this->NoE == 0;}
		unsigned int size() const {return this->NoE;}
		unsigned int capacity() const {return this->Cap;}
		void clear();
		void push_back(const T& New_Element);
		void pop_back();
		void shrink_to_fit();
		void resize(unsigned int NewSize);
		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;
};

#include"../src/Vector.cpp"

#endif
