#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp> 
#include <SFML/Audio.hpp>
#include "Joueur.hpp"

class Game{
	private:
		sf::RenderWindow window;
		sf::Sprite cartes[8];
		int life;
		Joueur j;

	public:
		Game(int a);
		void show();
		void chargementCartes();
};
