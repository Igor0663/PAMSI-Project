#include"chess_game.hh"
#include<iostream>
#include <SFML/Graphics.hpp>
#define white 0
#define black 1


int main()
{
	sf::RenderWindow window( sf::VideoMode( 512, 512, 32 ), "Szachulce" );
	chess_game game(window);
	int result = game.play();
	if( result == black )
		std::cout <<"Blacks won!";
	else if( result == white )
		std::cout <<"Whites won!";
	return 0;
}
