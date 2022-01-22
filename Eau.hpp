#pragma once
#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp> 
#include "Ressources.hpp"

//Classe fille de Ressources

class Eau:public Ressources{
	public:

		Eau(){this->setType(2);}

	private:

};