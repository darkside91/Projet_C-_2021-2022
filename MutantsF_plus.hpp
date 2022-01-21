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
		MutantsF_plus():Mutants(){};
		Personnage& reproduction(Personnage& p);
		
		


	private:
		
		


};