#ifndef PRIORITY_QUEUE_HH
#define PRIORITY_QUEUE_HH

#include"Vector.hh"
#include<functional>
#include<iostream>

template<typename T,class Comparator = std::greater<T> >
class Priority_queue
{
	private:
		Vector<T>* heap;
		Comparator cmp;
	public:
		Priority_queue(){heap = new Vector<T>(); this->cmp = Comparator(); }
		Priority_queue(const Priority_queue& Pqueue);
		~Priority_queue();
		const T& top() const;
		bool empty() const {return this->heap->empty();}
		unsigned int size() const{return this->heap->size();}
		void push(const T& NewElement);
		T pop();
};

#include"../src/Priority_queue.cpp"

#endif
