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
		
		Hommes():Humains(){setFemme(false);}
		Personnage& reproduction(Personnage& p);
		
		


	private:
		
		


};