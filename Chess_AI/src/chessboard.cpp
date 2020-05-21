#include"chessboard.hh"
#include<iostream>
#include<cctype>

chessboard::chessboard(unsigned int N)
{
	this->size = N;
	this->fields = matrix<field>(N, N);
	unsigned int l = 0;
	for(unsigned int i = 0; i < N; i++)
		for(unsigned int j = 0; j < N; j++)
		{
			fields(i, j) = field(l);
			l = (l + 1) % 2;
		}
}

void chessboard::display()
{
	for(unsigned int i = 0; i < this->size; i++)
	{
		std::cout << this->size - i << "  ";
		for(unsigned int j = 0; j < this->size; j++)
		{
			piece* p = fields(i, j).get_piece();
			if(p != nullptr)
			{
				char m = p->get_mark();
				if(p->get_color())
				{
					std::cout << char( toupper(m) ) << " ";
				}
				else
					std::cout << m << " ";
			}
			else
				std::cout <<"* ";
		}
		std::cout << "\n";
	}
	std::cout << "\n   A B C D E F G H\n";
	return;
}

void chessboard::add_piece(unsigned int i, unsigned int j, piece* p)
{
	this->fields(i,j).set_piece(p);
	return;
}


void chessboard::move_piece(std::pair<int, int> from, std::pair<int, int> to)
{
	piece* p = this->fields(from.first, from.second).get_piece();
	this->fields(from.first, from.second).set_piece(nullptr);
	this->fields(to.first, to.second).set_piece(p);
	p->made_move();
	return;
}
