#include "Joueur.hpp"

Joueur::Joueur(){
		x=749;
		y=535;
		texture_joueur.loadFromFile("Assets_visuels/joueur.png");
		s_joueur.setTexture(texture_joueur);
		s_joueur.setPosition(x,y);
	
}