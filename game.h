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
#include "Pierre.hpp"
#include "Bois.hpp"
#include "Eau.hpp"
#include "Viande.hpp"
#include "Legumes.hpp"

class Game{
	private:

		sf::RenderWindow window;
		
		sf::Sprite cartes[8];
		int tours;
		Joueur j;

		//vecteur de chaque type de personnage
		std::vector<Hommes> H;
		std::vector<Femmes> F;
		std::vector<Mutants_pm> PM;
		std::vector<MutantsF_minus> F_minus;
		std::vector<MutantsF_plus> F_plus;
		std::vector<Eau> E;
		std::vector<Bois> B;
		std::vector<Pierre> P;
		std::vector<Viande> V;
		std::vector<Legumes> L;

		//vecteur de cases
		std::vector<Cases> C;


	public:
		Game(int a);
		void show();
		void cases(std::size_t x1,std::size_t y1,std::size_t x2, std::size_t y2,std::size_t i);
		void init_cases();
		void recolter();
		Ressources& rand_ressources();
};
