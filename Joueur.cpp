#include "Joueur.hpp"

Joueur::Joueur(){
		x=725;
		y=525;
		texture_joueur.loadFromFile("Assets_visuels/joueur.png");
		s_joueur.setTexture(texture_joueur);
		s_joueur.setPosition(x,y);
	
}