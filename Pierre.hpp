#pragma once
#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp> 
#include "Ressources.hpp"

class Pierre:public Ressources{
	public:

		
		Pierre(){};

	private:
		sf::Texture texture;
		sf::Sprite s;
		



};