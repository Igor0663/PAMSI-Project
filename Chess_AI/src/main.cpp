#include"chess_game.hh"
#include<iostream>
#define white 0
#define black 1


int main()
{
	chess_game game;
	while(game.get_game_status() == -1)
	{
		game.display();
		game.turn();
		std::cout << "\n\n";
	}
	game.display();
	if(game.get_game_status())
		std::cout << "Blacks won!\n";
	else
		std::cout << "White won!\n";
	return 0;
}
