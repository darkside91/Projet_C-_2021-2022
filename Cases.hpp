#pragma once
#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp> 
#include "Viande.hpp"
#include "Eau.hpp"
#include "Bois.hpp"
#include "Pierre.hpp"
#include "Legumes.hpp"

class Cases{
	public:

		


	private:
		//position du joueur
		std::size_t x1;
		std::size_t y1;
		std::size_t x2;
		std::size_t y2;
		std::vector<Ressources> R;



};