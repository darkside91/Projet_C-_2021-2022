#pragma once
#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp> 

//Classe Ressources -> Classe mère de Eau, Viande, Legume, Bois et Pierre

class Ressources{
	public:
		
		const std::size_t getType(){return type;}
		void setType(std::size_t i){type = i;}
		std::string str();

	private:
		
		std::size_t type;
	

};