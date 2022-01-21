#pragma once
#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp> 
#include "Humains.hpp"
#include "Femmes.hpp"
#include "Mutants_pm.hpp"
#include "MutantsF_minus.hpp"
#include "MutantsF_plus.hpp"

class Femmes:public Humains{
	public:
		Femmes():Humains(){setFemme(true);}
		Personnage& reproduction(Personnage& p);
		
		


	private:
		
		


};