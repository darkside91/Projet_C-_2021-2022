#pragma once
#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp> 
#include "Ressources.hpp"

class Viande:public Ressources{
	public:

		Viande(){};


	private:
		sf::Texture texture;
		sf::Sprite s;
		



};