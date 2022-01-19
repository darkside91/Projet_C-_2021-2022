#pragma once
#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp> 

class Joueur{
	public:

		Joueur();
		sf::Sprite getSprite() const { return s_joueur;}
		const std::size_t getX(){return x;}
		const std::size_t getY(){return y;}
		void setX(std::size_t x_new){x = x_new;}
		void setY(std::size_t y_new){y = y_new;}
		void newPosition(){s_joueur.setPosition(x,y);}


	private:
		//position du joueur
		std::size_t x;
		std::size_t y;
		sf::Texture texture_joueur;
		sf::Sprite s_joueur;



};