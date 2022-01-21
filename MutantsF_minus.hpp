#pragma once
#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp> 
#include "Mutants.hpp"
#include "Femmes.hpp"
#include "Hommes.hpp"
#include "MutantsF_plus.hpp"
#include "Mutants_pm.hpp"
class MutantsF_minus:public Mutants{
	public:

		
		MutantsF_minus():Mutants(){};
		Personnage& reproduction(Personnage& p);


	private:
		
		


};