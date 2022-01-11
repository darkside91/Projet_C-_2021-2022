#pragma once
#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp> 
#include "Ressources.hpp"

class Bois:public Ressources{
	public:

		
		Bois(){};

	private:
		sf::Texture texture;
		sf::Sprite s;
		



};