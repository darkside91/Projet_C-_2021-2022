#pragma once
#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp> 
#include "Ressources.hpp"

class Legumes:public Ressources{
	public:

		
		Legumes(){};

	private:
		sf::Texture texture;
		sf::Sprite s;
		



};