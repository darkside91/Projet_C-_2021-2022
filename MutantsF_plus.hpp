#pragma once
#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp> 
#include "Mutants.hpp"
#include "Femmes.hpp"
#include "Hommes.hpp"
#include "MutantsF_minus.hpp"
#include "Mutants_pm.hpp"


class MutantsF_plus:public Mutants{
	public:
		MutantsF_plus():Mutants(){setType_r(4);setVie(4);}
		Personnage& reproduction(Personnage& p);
		bool choisir(std::size_t x,std::size_t y);
		
		


	private:
		
		


};