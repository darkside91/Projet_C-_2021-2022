#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp> 
#include <SFML/Audio.hpp>
#include "game.h"
#include <string>

using namespace sf;

int main()
{
	//Music
	sf::Music music;
	if (!music.openFromFile("Assets_visuels/Cheilinus_Undulatus.wav"))
    return -1; // error
	music.setLoop(true);
	music.setVolume(100);
	music.play();

	//"Carte/fd/1.png"
	Game g(10);
	g.show();
	//sf::RenderWindow window;
	//window.create(sf::VideoMode(1600, 1000), "Survivor Lander");

	
/*
    sf::RenderWindow window(sf::VideoMode(1600, 1000), "Survivor Lander");

 // Limit the framerate to 60 frames per second (this step is optional)
/// window.setFramerateLimit(60);
///1600, 1000
/// // The main loop - ends as soon as the window is closed

	 sf::SoundBuffer buffer;
	 buffer.loadFromFile("intro1.wav");

	 sf::Sound sound;
	 sound.setBuffer(buffer);
	 sound.play();
	 sound.setLoop(true);
	
	int mode=2;
	int ok=0;
	int menu=0;
	//Bouton
	sf::RectangleShape bouton(sf::Vector2f(600, 1000));
	bouton.setPosition(1000,0);
	
	sf::RectangleShape bouton2(sf::Vector2f(1600, 1000));
	bouton2.setFillColor(sf::Color::White);
	
	//LES MAPS
	
	int compteur=1;
	
	sf::Texture carte1;
	carte1.loadFromFile("Carte/fd/1.png");
	sf::Sprite sprite11(carte1);
	sprite11.setScale(0.62f,0.55f);
	
	sf::Texture carte2;
	carte2.loadFromFile("Carte/fd/2.png");
	sf::Sprite sprite12(carte2);
	sprite12.setScale(0.62f,0.55f);
	
	sf::Texture carte3;
	carte3.loadFromFile("Carte/fd/3.png");
	sf::Sprite sprite13(carte3);
	sprite13.setScale(0.62f,0.55f);
	
	sf::Texture carte4;
	carte4.loadFromFile("Carte/fd/4.png");
	sf::Sprite sprite14(carte4);
	sprite14.setScale(0.62f,0.55f);
	
	sf::Texture carte5;
	carte5.loadFromFile("Carte/fd/5.png");
	sf::Sprite sprite15(carte5);
	sprite15.setScale(0.62f,0.55f);
	
	sf::Texture carte6;
	carte6.loadFromFile("Carte/fd/6.png");
	sf::Sprite sprite16(carte6);
	sprite16.setScale(0.62f,0.55f);
	
	sf::Texture carte7;
	carte7.loadFromFile("Carte/fd/7.png");
	sf::Sprite sprite17(carte7);
	sprite17.setScale(0.62f,0.55f);
	
	sf::Texture carte8;
	carte8.loadFromFile("Carte/fd/8.png");
	sf::Sprite sprite18(carte8);
	sprite18.setScale(0.62f,0.55f);
	
	
	sf::Texture pres;
	pres.loadFromFile("Carte/menu.png");
	sf::Sprite sprite19(pres);
	sprite19.setScale(1.0f,1.0f);
	sprite19.setPosition(50,-150);
	
	sf::Texture pres2;
	pres2.loadFromFile("Carte/terre.png");
	sf::Sprite sprite20(pres2);
	sprite20.setScale(0.8f,0.8f);
	sprite20.setPosition(550,400);

	int carb=500;
	sf::Font font;
	font.loadFromFile("arial.ttf");
	//text.setString("Salut les zéros !"); // Texte
	//text.setFont(font); // Fonte

	
	//Texte bouton
	sf::Text text2("Station",font);
	text2.setCharacterSize(20); // Taille de police
	text2.setColor(sf::Color::Black);
	text2.setPosition(700,40);
	
	//Texte bouton2
	sf::Text text3("Reload Ship",font);
	text3.setCharacterSize(30); // Taille de police
	text3.setColor(sf::Color::Red);
	text3.setPosition(600,120);
	
	
	sf::CircleShape circle(10);
	sf::Vector2i localPosition = sf::Mouse::getPosition(window);
	int x=100;
	int y=100;
	int MouseX=0;
	int MouseY=0;

//55 de différence en x
	sf::Vector2i coord[100];
				//213 pour ligne 1
	int difX=58;
	int difY=45;
	int valX[]={840,456,424,335,304,277,304,277,304};
	int valY=213;
	for(int i=0;i<100;i++){
		if(i<4){
			coord[i]=sf::Vector2i(valX[0], 215);
			valX[0]+=difX;
		}
		if(i>3 && i<19){
			coord[i]=sf::Vector2i(valX[1], 215+difY);			
			valX[1]+=difX;
		}
		if(i>18 && i<30){
			coord[i]=sf::Vector2i(valX[2], 215+2*difY);			
			valX[2]+=difX;
		}
		if(i>29 && i<38){
			coord[i]=sf::Vector2i(valX[3], 215+3*difY);			
			valX[3]+=difX;
		}
		if(i>37 && i<48){
			coord[i]=sf::Vector2i(valX[4], 215+4*difY);			
			valX[4]+=difX;
		}
		if(i>47 && i<57){
			coord[i]=sf::Vector2i(valX[5], 215+5*difY);			
			valX[5]+=difX;
		}
		if(i>56 && i<67){
			coord[i]=sf::Vector2i(valX[6], 215+6*difY);			
			valX[6]+=difX;
		}
		if(i>66 && i<78){
			coord[i]=sf::Vector2i(valX[7], 215+7*difY);			
			valX[7]+=difX;
		}
		if(i>77 && i<87){
			coord[i]=sf::Vector2i(valX[8], 215+8*difY);			
			valX[8]+=difX;
		}
		

	}	




 while (window.isOpen())
 {
    // Event processing
    sf::Event event;
    
   while (window.pollEvent(event))
   {
   		switch (event.type){
		   
       // Request for closing the window
       case sf::Event::Closed :
           window.close();
           break;
           
       case sf::Event::MouseMoved : // Mouvement de la souris
      		localPosition = sf::Mouse::getPosition(window);
      		MouseX=localPosition.x;
      		MouseY=localPosition.y;
      		
      		std::cout << "x: " << MouseX << std::endl;
      		std::cout << "y: " << MouseY << std::endl << std::endl;
    		break;
    	case sf::Event::MouseButtonPressed:
    		
    		if(mode==2){
    			if(MouseX>677 && MouseY>480 && MouseX<885 && MouseY<665){
    				mode=3;
				}
			}else if(mode==3){
				
				

				//750, 535 // longueur 34 en x //hauteur de 22 en y
				for(int i=0;i<100;i++){
					if(MouseX>coord[i].x-20 && MouseY>coord[i].y-12	 && MouseX<coord[i].x+20 && MouseY<coord[i].y+12){
    					std::cout <<i<< std::endl;
    					//menu=1;
    					//compteur+=1;
					}		
				}
				if(MouseX>750-17 && MouseY>535-11 && MouseX<750+17 && MouseY<535+11){
    				std::cout <<"Salut"<< std::endl;
    				//menu=1;
    				compteur+=1;
				}
			}
		
    		break;
    	
   		case sf::Event::KeyPressed:
   			//std:: cout << "He" << std::endl;
   			if(mode==0 || mode==3){
			   
   			switch(event.key.code){
   				
   				
   				case sf::Keyboard::A :
   					if(menu==0){
   						menu=1;
					   }else{
					   	menu=0;
					   }
   					break;
   				case sf::Keyboard::Space :
   					compteur+=1;
   					if(compteur==9){
   						compteur=1;
					   }
					   
   					break;
			   }
		}
		}
	}

   // Clear the whole window before rendering a new frame
   window.clear();
///    // Draw some graphical entities

	if(mode==0){
	
	 
 }else if(mode==2){
	 window.draw(bouton2);
	 window.draw(sprite19);
	 window.draw(sprite20);
 }else if(mode==3){
 	switch(compteur){
 		case 1:
 			window.draw(sprite11);
 			break;
 		case 2:
 			window.draw(sprite12);
 			break;
 		case 3:
 			window.draw(sprite13);
 			break;
 		case 4:
 			window.draw(sprite14);
 			break;
 		case 5:
 			window.draw(sprite15);
 			break;
 		case 6:
 			window.draw(sprite16);
 			break;
 		case 7:
 			window.draw(sprite17);
 			break;
 		case 8:
 			window.draw(sprite18);
 			break;
	 }

	 if(menu==1){
	 	window.draw(bouton);
	 }
 }

 	
 	
   // End the current frame and display its contents on screen
   window.display();
 }
 return 0;
 */
}
