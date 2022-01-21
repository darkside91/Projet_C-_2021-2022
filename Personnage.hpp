#pragma once
#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp> 
#include "Ressources.hpp"
#include "Eau.hpp"

class Personnage{
	public:

		void setVie(std::size_t i){Vie = i;}
		virtual Personnage& reproduction(Personnage& p) = 0;
		void setType_r(std::size_t i){Type_r=i;}
		const std::size_t getType_r(){return Type_r;}
		const std::size_t getType_perso(){return type_perso;}
		void setType_perso(std::size_t i){type_perso = i;}
		const bool getBool(){return femme;}
		void setFemme(bool f){femme=f;}
		


	private:
		std::size_t Vie;
		std::size_t Type_r;
		std::size_t type_perso;
		bool femme;


		
		


};