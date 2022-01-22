#pragma once
#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp> 
#include "Ressources.hpp"

//classe fille de Ressources

class Bois:public Ressources{
	public:
		
		Bois(){this->setType(4);}

	private:
		

};