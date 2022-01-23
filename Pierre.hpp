#pragma once
#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp> 
#include "Ressources.hpp"

//Classe fille de Ressources
class Pierre:public Ressources{
	public:
		
		Pierre(){this->setType(3);}
	

	private:

};