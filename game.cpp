#include "game.h"

Game::Game(int a){
	this->life=a;
	this->window.create(sf::VideoMode(1600, 1000), "Survivor Lander");
	this->chargementCartes();
	
	
}
void Game::show(){

	sf::Texture texture;
	sf::Texture texture2;
	std::size_t i = 1;
	std::string chemin="Carte/fd/";
	std::string ext=".png";
	std::string numero;
	std::string nomComplet;
	sf::Sprite s;
	sf::Sprite button;
	bool flag_escape = false;

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
           		if(flag_escape == true){
           			if(event.mouseButton.x < 875 && event.mouseButton.x>726 && event.mouseButton.y < 686 && event.mouseButton.y > 521){
           				flag_escape = false;
           			}
           			//if(event.mouseButton.x)
           			//std::cout << "mouse x: " << event.mouseButton.x << std::endl;
        			//std::cout << "mouse y: " << event.mouseButton.y << std::endl;
           		}
           		if(i<8 && flag_escape == false){
           			i++;
           			numero=std::to_string(i);
					nomComplet=chemin+numero+ext;
           			texture.loadFromFile(nomComplet);
    				s.setTexture(texture);
   					s.setScale(0.62f,0.55f);
    				window.draw(s);
    				this->window.display();
    				this->window.clear();}
           		
           		
           		break;
           }
           if (event.type == sf::Event::KeyPressed)
			{
    		if (event.key.code == sf::Keyboard::Escape)
    			{
    				if(flag_escape == false){
    					flag_escape = true;
        				texture.loadFromFile("Carte/menu.png");
        				s.setTexture(texture);
   						s.setScale(0.70f,0.70f);
   						texture2.loadFromFile("Carte/terre.png");
   						button.setTexture(texture2);
   						button.setScale(0.7f,0.7f);
   						button.setPosition(600,450);
    					window.draw(s);
    					window.draw(button);
    					this->window.display();}
    				else{
    					flag_escape = false;
    					texture.loadFromFile(nomComplet);
    					s.setTexture(texture);
   						s.setScale(0.62f,0.55f);
    					window.draw(s);
    					this->window.display();
    				}
        
    			}
			}


		}

		
		sf::Font font;
		
		
		//text3.setCharacterSize(60); // Taille de police
		//text3.setColor(sf::Color::Red);
		//text3.setPosition(600,120);
		
		
		//window.draw(this->cartes[4]);
		
		//this->window.clear();
		//this->window.display();
	}
}
void Game::chargementCartes(){
	/*sf::Texture load[8];
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
		cartes[i]=s;
		cartes[i].setScale(0.62f,0.55f);
		window.draw(cartes[1]);
		this->window.display();
		this->window.clear();
	}*/
	sf::Texture texture;
    texture.loadFromFile("Carte/fd/1.png");
    sf::Sprite s(texture);
    s.setScale(0.62f,0.55f);
    window.draw(s);
    this->window.display();
    this->window.clear();
   
	
}
