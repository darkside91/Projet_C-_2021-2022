#pragma once
#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp> 
#include "Ressources.hpp"
#include "Eau.hpp"

class Personnage{
	public:

		//virtual void reproduction(Personnage& p)=0;
		void setForce(std::size_t a) { Force=a;}
		


	private:
		std::size_t Force;
		std::size_t R_tour; //ressources dépensées par tour
		std::size_t Eau_tour; //eau dépensée par tour
		std::size_t Vie;
		Ressources R; //ressource à dépenser



		
		


};