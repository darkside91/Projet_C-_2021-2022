#pragma once
#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp> 
#include "Humains.hpp"
#include "Femmes.hpp"
#include "Mutants_pm.hpp"
#include "MutantsF_minus.hpp"
#include "MutantsF_plus.hpp"

class Hommes:public Humains{
	public:
		
		Hommes():Humains(){setFemme(false);setType_r(1);}
		Personnage& reproduction(Personnage& p);
		bool choisir(std::size_t x,std::size_t y);
		
		


	private:
		
		


};