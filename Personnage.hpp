#pragma once
#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp> 
#include "Ressources.hpp"
#include "Eau.hpp"

//Classe abstraite 

class Personnage{
	public:

		void setVie(std::size_t i){Vie = i;}
		const std::size_t getVie(){return Vie;}

		virtual Personnage& reproduction(Personnage& p) = 0;
		virtual bool choisir(std::size_t x,std::size_t y) =0;

		void setType_r(std::size_t i){Type_r=i;}
		const std::size_t getType_r(){return Type_r;}
		const std::size_t getType_perso(){return type_perso;}
		void setType_perso(std::size_t i){type_perso = i;}
		std::string str(std::size_t t);
		const bool getBool(){return femme;}
		void setFemme(bool f){femme=f;}
		const bool getVivant(){return vivant;}
		void setVivant(bool f){vivant=f;}

		void Perdre_vie();
		


	private:
		std::size_t Vie;
		std::size_t Type_r;// exact type 1 parmi 5 
		std::size_t type_perso; // humains ou mutants
		bool femme; 
		bool vivant;


};


