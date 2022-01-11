#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp> 
#include <SFML/Audio.hpp>
#include <vector>
#include "Joueur.hpp"
#include "Hommes.hpp"
#include "Femmes.hpp"
#include "MutantsF_plus.hpp"
#include "MutantsF_minus.hpp"
#include "Mutants_pm.hpp"
#include "Cases.hpp"

class Game{
	private:
		sf::RenderWindow window;
		sf::Sprite cartes[8];
		int life;
		Joueur j;
		//vecteur de chaque type de personnage
		std::vector<Hommes> H;
		std::vector<Femmes> F;
		std::vector<Mutants_pm> PM;
		std::vector<MutantsF_minus> F_minus;
		std::vector<MutantsF_plus> F_plus;
		//vecteur de cases
		std::vector<Cases> C;


	public:
		Game(int a);
		void show();
		void chargementCartes();
};
