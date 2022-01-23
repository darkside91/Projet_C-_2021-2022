#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp> 
#include <SFML/Audio.hpp>
#include "game.h"
#include <string>

using namespace sf;

int main()
{
	//initialiser rand
	srand((unsigned) time(0));

	//Music
	sf::Music music;
	if (!music.openFromFile("Assets_visuels/Cheilinus_Undulatus.wav"))
    return -1; // error
	music.setLoop(true);
	music.setVolume(100);
	music.play();

	//Jeu
	Game g(8);
	g.show();
	
}
