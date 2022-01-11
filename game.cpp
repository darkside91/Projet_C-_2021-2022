#include "game.h"

Game::Game(int a){
	this->life=a;
	this->window.create(sf::VideoMode(1600, 1000), "Last Earth");
	this->chargementCartes();

	H.push_back(Hommes());
	F.push_back(Femmes());
	V.push_back(Viande());
	E.push_back(Eau());
	E.push_back(Eau());
	L.push_back(Legumes());
	B.push_back(Bois());
	P.push_back(Pierre());

	
	
}
void Game::show(){

	sf::Texture texture;
	sf::Texture texture2;
	sf::Texture texture3;
	sf::Texture texture4;
	std::size_t i = 1;
	std::string chemin="Carte/fd/";
	std::string ext=".png";
	std::string numero;
	std::string nomComplet;

	sf::Sprite s;
	sf::Sprite button;
	sf::Sprite s2;
	sf::Sprite s3;
	sf::Sprite Regles_du_jeu;

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
           			
           		}
           		//pour les tests
           		std::cout << "mouse x: " << event.mouseButton.x << std::endl;
        		std::cout << "mouse y: " << event.mouseButton.y << std::endl;
           		if(i<8 && flag_escape == false){
           			i++;
           			}
    			if(flag_escape == false){
    				numero=std::to_string(i);
					nomComplet=chemin+numero+ext;
           			texture.loadFromFile(nomComplet);
    				s.setTexture(texture);
   					s.setScale(0.62f,0.55f);

   					texture2.loadFromFile("Assets_visuels/villageois.png");
   					s2.setTexture(texture2);
   					s2.setScale(0.65f,0.65f);
   					s2.setPosition(1400,0);

   					texture3.loadFromFile("Assets_visuels/ressources.png");
   					s3.setTexture(texture3);
   					s3.setScale(0.65f,0.65f);
   					s3.setPosition(1400,500);

    				window.draw(s);
    				window.draw(s2);
    				window.draw(s3);
    				window.draw(j.getSprite());
    				this->window.display();
    				this->window.clear();
    			}
           		
           		
           		break;
           }
           if (event.type == sf::Event::KeyPressed)
			{
				//écran de pause
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

   						texture3.loadFromFile("Assets_visuels/bouton_planete.png");
   						s2.setTexture(texture3);
   						s2.setScale(0.7f,0.7f);
   						s2.setPosition(880,630);
    					window.draw(s);
    					window.draw(button);
    					window.draw(s2);

    					this->window.display();}
    				else{
    					flag_escape = false;
    					texture.loadFromFile(nomComplet);
    					s.setTexture(texture);
   						s.setScale(0.62f,0.55f);

   						texture2.loadFromFile("Assets_visuels/villageois.png");
   						s2.setTexture(texture2);
   						s2.setScale(0.65f,0.65f);
   						s2.setPosition(1400,0);

   						texture3.loadFromFile("Assets_visuels/ressources.png");
   						s3.setTexture(texture3);
   						s3.setScale(0.65f,0.65f);
   						s3.setPosition(1400,500);

    					window.draw(s);
    					window.draw(s2);
    					window.draw(s3);
    					window.draw(j.getSprite());
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
	sf::Texture texture2;
	sf::Texture texture3;
	sf::Texture texture4; //1.png
	sf::Texture texture5; //0.png
	sf::Texture texture6; // 2.Png


	sf::Sprite s2;
	sf::Sprite s3;
	sf::Sprite sH;
	sf::Sprite sF;
	sf::Sprite sMplus;
	sf::Sprite sMminus;
	sf::Sprite sMpm;
	sf::Sprite V1;
	sf::Sprite V2;
	sf::Sprite V3;
	sf::Sprite V4;
	sf::Sprite V5;

    texture.loadFromFile("Carte/fd/1.png");
    sf::Sprite s(texture);
    s.setScale(0.62f,0.55f);
    texture2.loadFromFile("Assets_visuels/villageois.png");
   	s2.setTexture(texture2);
   	s2.setScale(0.65f,0.65f);
    s2.setPosition(1400,0);
    texture3.loadFromFile("Assets_visuels/ressources.png");
   	s3.setTexture(texture3);
   	s3.setScale(0.65f,0.65f);
   	s3.setPosition(1400,500);
   	texture4.loadFromFile("Assets_visuels/1.png");
   	texture5.loadFromFile("Assets_visuels/0.png");
   	texture6.loadFromFile("Assets_visuels/2.png");
   	sH.setTexture(texture4);
   	sH.setPosition(1700,200); //numéro Homme
   	sH.setScale(1.5f,1.5f);
   	sF.setTexture(texture4);
   	sF.setScale(1.5f,1.5f);
   	sF.setPosition(1516,200);
   	sMplus.setTexture(texture5);
   	sMplus.setScale(1.5f,1.5f);
   	sMplus.setPosition(1466,368);
   	sMminus.setTexture(texture5);
   	sMminus.setScale(1.5f,1.5f);
   	sMminus.setPosition(1783,371);
   	sMpm.setTexture(texture5);
   	sMpm.setScale(1.5f,1.5f);
   	sMpm.setPosition(1630,373);

   	V1.setTexture(texture4);
   	V1.setScale(1.5f,1.5f);
   	V1.setPosition(1527,608);

   	V2.setTexture(texture4);
   	V2.setScale(1.5f,1.5f);
   	V2.setPosition(1527,698);

   	V3.setTexture(texture6);
   	V3.setScale(1.5f,1.5f);
   	V3.setPosition(1525,800);

   	V4.setTexture(texture4);
   	V4.setScale(1.5f,1.5f);
   	V4.setPosition(1688,758);

   	V5.setTexture(texture4);
   	V5.setScale(1.5f,1.5f);
   	V5.setPosition(1688,636);

    window.draw(s);
    window.draw(s2);
    window.draw(s3);
    window.draw(j.getSprite());
    window.draw(sH);
    window.draw(sF);
    window.draw(sMpm);
    window.draw(sMminus);
    window.draw(sMplus);
    window.draw(V1);
    window.draw(V2);
    window.draw(V3);
    window.draw(V4);
    window.draw(V5);
    this->window.display();
    this->window.clear();
   
	
}

