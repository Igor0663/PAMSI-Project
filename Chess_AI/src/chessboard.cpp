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


void chessboard::move_piece(pos_move mov, std::vector<piece>& pieces)
{
	auto from = mov.from;
	auto to = mov.to;
	if(from != to)
	{
		piece* p = this->fields(from.first, from.second).get_piece();
		this->fields(from.first, from.second).set_piece(nullptr);
		this->fields(to.first, to.second).set_piece(p);
		p->made_move();
	}
	else
	{
		piece p;
		bool color = this->fields(from.first, from.second).get_piece()->get_color();
		switch(mov.promotion)
		{
			case 'q': p = queen(color); break;
			case 'n': p = knight(color); break;
			case 'b': p = bishop(color); break;
			case 'r': p = rook(color); break;
			default: std::cerr <<"promotion to undefined piece\n"; break;
		}
		pieces.push_back(p);
		this->fields(to.first, to.second).set_piece(&pieces.back());
	}

	return;
}
void chessboard::undo_move(pos_move mov, int ind, std::vector<piece>& pieces)
{
	auto from = mov.from;
	auto to = mov.to;
	if(from != to)
	{
		piece* p = this->fields(to.first, to.second).get_piece();
		this->fields(to.first, to.second).set_piece(nullptr);
		this->fields(from.first, from.second).set_piece(p);
		p->undo_move();
		if(ind != -1)
			this->fields(to.first, to.second).set_piece(&pieces[ind]);
	}
	else
	{
		pieces.pop_back();
		this->fields(from.first, from.second).set_piece(&pieces[ind]);
	}
	return;
}
