#include"game.h"

Game::Game(int a){
	this->life=a;
	this->window.create(sf::VideoMode(1600, 1000), "Survivor Lander");
	this->chargementCartes();
	
	
}
void Game::show(){
	while (this->window.isOpen())
 	{
    // Event processing
    	sf::Event event;
    
   		while (this->window.pollEvent(event))
   		{
   			switch (event.type){
		   
       		// Request for closing the window
       		case sf::Event::Closed :
           		this->window.close();
           		break;
           	case sf::Event::MouseButtonPressed:
           		break;
           }
		}
		sf::Font font;
		font.loadFromFile("arial.ttf");
		
		sf::Text text3("Reload Ship",font);
		
		text3.setCharacterSize(60); // Taille de police
		text3.setColor(sf::Color::Red);
		text3.setPosition(600,120);
		
		
		window.draw(this->cartes[1]);
		this->window.clear();
		this->window.display();
	}
}
void Game::chargementCartes(){
	sf::Texture load[8];
	std::string chemin="Carte/fd/";
	std::string ext=".png";
	std::string numero;
	std::string nomComplet;
	for(int i=0;i<8;i++){
		numero=std::to_string(i+1);
		nomComplet=chemin+numero+ext;
		load[i].loadFromFile(nomComplet);
		std::cout<<nomComplet<<std::endl;
		sf::Sprite s(load[i]);
		this->cartes[i]=s;
		this->cartes[i].setScale(0.62f,0.55f);
		window.draw(this->cartes[1]);
		this->window.display();
		this->window.clear();
	}
}

