#pragma once
#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp> 
#include "Mutants.hpp"
#include "Femmes.hpp"
#include "Hommes.hpp"
#include "MutantsF_minus.hpp"
#include "MutantsF_plus.hpp"

class Mutants_pm:public Mutants{
	public:
		Mutants_pm():Mutants(){setType_r(3);setVie(5);}
		Personnage& reproduction(Personnage& p);
		bool choisir(std::size_t x,std::size_t y);

	private:
		

};