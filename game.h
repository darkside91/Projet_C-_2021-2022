#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp> 
#include <SFML/Audio.hpp>

class Game{
	private:
		sf::RenderWindow window;
		sf::Sprite cartes[8];
		int life;
	public:
		Game(int a);
		void show();
		void chargementCartes();
};
