#ifndef CHESSBOARD_HH
#define CHESSBOARD_HH
#include<vector>
#include"field.hh"

struct pos_move{
	std::pair<int, int> from;
	std::pair<int, int> to;
	char promotion;
	pos_move(std::pair<int, int> a, std::pair<int, int> b): from(a), to(b), promotion('x') {}
};

template<typename T>
struct matrix
{
		matrix(unsigned int N = 1, unsigned int M = 1): N(N), M(M) {this->A.resize(N*M);}
		T& operator()( unsigned int i, unsigned int j){return this->A[this->N * i + j];}
		const T& operator()(unsigned int i,unsigned int j) const {return this->A[this->N * i + j];}
	private:
		unsigned int N, M;
		std::vector<T> A;
};	


class chessboard
{
		unsigned int size;
		matrix<field> fields;
	public:
		chessboard(unsigned int N = 8);
		void display();
		void add_piece(unsigned int i, unsigned int j, piece* p);
		void undo_move(pos_move mov, int ind, std::vector<piece>& pieces);
		void move_piece(pos_move mov, std::vector<piece>& pieces);
		piece* get_piece(unsigned int i, unsigned int j){return this->fields(i,j).get_piece();  }
};


#endif
