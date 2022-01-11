#pragma once
#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp> 

class Joueur{
	public:

		Joueur();


	private:
		//position du joueur
		std::size_t x;
		std::size_t y;
		sf::Texture texture_joueur;
		sf::Sprite s_joueur;



};