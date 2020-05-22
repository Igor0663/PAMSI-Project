#include"chess_game.hh"
#include<iostream>
#define white 0
#define black 1


int main()
{
	chess_game game;
	int i = 100;
	while(i--)
	{
		game.display();
		game.turn();
		std::cout << "\n\n";
	}
	game.display();
	return 0;
}
