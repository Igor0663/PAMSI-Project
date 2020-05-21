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
/*		std::cout << "\n\n";
		for( int i = 0; i < kokos.size(); i++)
		{
			for(int j = 0; j < kokos[i].size();j++)
				std::cout<< "[(" << kokos[i][j].from.first << "," << kokos[i][j].from.second <<"),(" << kokos[i][j].to.first << "," << kokos[i][j].to.second <<")] ";
			std::cout << "\n";
		}
*/
	}
	game.display();
	return 0;
}
