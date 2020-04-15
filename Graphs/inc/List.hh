#ifndef LIST_HH 
#define LIST_HH


#include<initializer_list>


template<typename T>
class List
{
	public:
		struct Node
		{
			Node* next;
			Node* prev;
			T value;
			
			Node(): next(nullptr), prev(nullptr) {}
			Node(Node* PrevPtr, Node* NextPtr, const T& StartValue): next(NextPtr), prev(PrevPtr), value(StartValue) {}
		};
		
		class iterator{
				Node* node;
			public:
			Node& get_node(){ return *node; }
			iterator( Node* NewNode = nullptr): node(NewNode){}
			iterator&	operator++();
			iterator	operator++(int);
			T&		operator*() const;
			iterator&	operator=(const iterator& It);
			bool		operator!=(const iterator& It) const;
		};

		class const_iterator{
				Node* node;
			public:
			const Node& get_node()const { return *node; }
			const_iterator( Node* NewNode = nullptr): node(NewNode){}
			const_iterator&	operator++();
			const_iterator	operator++(int);
			const T&	operator*() const;
			const_iterator&	operator=(const const_iterator& It);
			bool		operator!=(const const_iterator& It) const;
		};

		class reverse_iterator{
				Node* node;
			public:
			Node& get_node(){ return *node; }
			reverse_iterator( Node* NewNode = nullptr): node(NewNode){}
			reverse_iterator&	operator++();
			reverse_iterator	operator++(int);
			T&			operator*() const;
			reverse_iterator&	operator=(const reverse_iterator& It);
			bool			operator!=(const reverse_iterator& It) const;
		};

		class const_reverse_iterator{
				Node* node;
			public:
			const Node& get_node()const { return *node; }
			const_reverse_iterator( Node* NewNode = nullptr): node(NewNode){}
			const_reverse_iterator&	operator++();
			const_reverse_iterator	operator++(int);
			const T&	        operator*() const;
			const_reverse_iterator&	operator=(const const_reverse_iterator& It);
			bool		        operator!=(const const_reverse_iterator& It) const;
		};

		List(){head = nullptr; tail=nullptr; NoE=0;}
		List(const std::initializer_list<T>& list);
		List(const List<T>& list);
		~List();
		
		iterator begin(){return List<T>::iterator(this->head);}
		iterator end(){return List<T>::iterator(nullptr);}
		
		const_iterator cbegin() const {return List<T>::const_iterator(this->head);}
		const_iterator cend() const {return List<T>::const_iterator(nullptr);}
		
		reverse_iterator rbegin(){return List<T>::reverse_iterator(this->tail);}
		reverse_iterator rend(){return List<T>::reverse_iterator(nullptr);}
		
		const_reverse_iterator crbegin() const {return List<T>::const_reverse_iterator(this->tail);}
		const_reverse_iterator crend() const {return List<T>::const_reverse_iterator(nullptr);}
		
		void push_back(const T& NewElement);
		void push_front(const T& NewElement);
		void pop_back();
		void pop_front();
		void insert(const T& NewElement, unsigned int index);
		void remove(const T& element);
		void erase(iterator& it );
		void erase(reverse_iterator& it);
		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;
		const T& front() const{ return head->value; }
		const T& back() const { return tail->value; }
		bool empty() const { return this->head == nullptr;}
		unsigned int size() const {return this->NoE;}

	private:
		Node* head;
		Node* tail;
		unsigned int NoE;

};

#include"../src/List.cpp"
#include"../src/List_iterators.cpp"

#endif
