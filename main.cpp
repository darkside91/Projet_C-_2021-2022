#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp> 
#include <SFML/Audio.hpp>

using namespace sf;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

 // Limit the framerate to 60 frames per second (this step is optional)
/// window.setFramerateLimit(60);
///
/// // The main loop - ends as soon as the window is closed

	 /*sf::SoundBuffer buffer;
	 buffer.loadFromFile("rad.wav");

	 sf::Sound sound;
	 sound.setBuffer(buffer);
	 sound.play();
	 sound.setLoop(true);
	*/
	int mode=2;
	int ok=0;
	//Bouton
	sf::RectangleShape bouton(sf::Vector2f(80, 60));
	bouton.setPosition(700,20);
	
	//Bouton2
	sf::RectangleShape bouton2(sf::Vector2f(170, 80));
	bouton2.setPosition(600,100);

	//Bouton3
	sf::RectangleShape bouton3(sf::Vector2f(170, 80));
	bouton3.setPosition(300,200);
	bouton3.setFillColor(sf::Color::White);
	
	//Batiment
	sf::RectangleShape bouton4(sf::Vector2f(170, 80));
	bouton4.setPosition(300,200);
	bouton4.setFillColor(sf::Color::Red);
	int posX=0;
	int poxY=0;
	int click=0;
	
	//Vaisseau
	sf::Texture image;
	image.loadFromFile("df.png");
	sf::Sprite sprite(image);
	sprite.setScale(0.15f,0.15f);
	sprite.setOrigin(335,186);
	
	//Fond
	sf::Texture image2;
	image2.loadFromFile("back.jpg");
	sf::Sprite sprite2(image2);
	sprite2.setScale(1.4f,1.0f);
	
	//Fond-menu
	sf::Texture image5;
	image5.loadFromFile("ds.jpg");
	sf::Sprite sprite5(image5);
	sprite5.setScale(0.45f,0.6f);
	
	//Station Spatiale
	sf::Texture image3;
	image3.loadFromFile("gf.png");
	sf::Sprite sprite3(image3);
	sprite3.setScale(0.2f,0.2f);
	sprite3.setPosition(350,400);
	
	//Station intérieur
	sf::Texture image4;
	image4.loadFromFile("Sp.jpg");
	sf::Sprite sprite4(image4);
	sprite4.setScale(0.5f,0.5f);
	
	sf::Vector2f localPosition2 = sprite.getOrigin();
	std::cout <<localPosition2.x <<std::endl;

	int carb=500;
	sf::Font font;
	font.loadFromFile("arial.ttf");
	sf::Text text("Carburant restant :"+ std::to_string(carb),font);
	//text.setString("Salut les zéros !"); // Texte
	//text.setFont(font); // Fonte
	text.setCharacterSize(20); // Taille de police
	text.setColor(sf::Color::White);
	
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
	
	
	//Texte bouton 3
	sf::Text text4("Jouer",font);
	text4.setCharacterSize(30); // Taille de police
	text4.setColor(sf::Color::Red);
	text4.setPosition(350,220);
	
	sf::CircleShape circle(10);
	sf::Vector2i localPosition = sf::Mouse::getPosition(window);
	int x=100;
	int y=100;
	int MouseX=0;
	int MouseY=0;





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
    		break;
    	case sf::Event::MouseButtonPressed:
    		
    		if(mode==1){
    			if(MouseX>600 && MouseY>100 && MouseX<770 && MouseY<180){
    				carb=500;
				}
			}
			if(mode==2){
				
				if(click==0 && MouseX>posX && MouseY>posY && MouseX<(posX+170) && MouseY<(posY+80)){
					click=1;
					
				}else if(click==1 && MouseX>posX && MouseY>posY && MouseX<(posX+170) && MouseY<(posY+80)){
					click=0;
				}
    			if(MouseX>300 && MouseY>200 && MouseX<470 && MouseY<280){
    				carb=500;
    				mode=0;
				}
			}
    		if(ok==1){
    			//std::cout <<MouseX<< std::endl;
    			//std::cout <<MouseY<< std::endl;
    			if(MouseX>700 && MouseY>20 && MouseX<780 && MouseY<80){
    				if(mode==0){
    					mode=1;
					}else{
						mode=0;
					}
				}    			
			}
    		break;
    	
   		case sf::Event::KeyPressed:
   			//std:: cout << "He" << std::endl;
   			if(mode==0){
			   
   			switch(event.key.code){
   				
   				case sf::Keyboard::Z :
   					y=y-10;
   					sprite.setRotation(180);
   					carb-=1;
   					//window.close();
   					//std:: cout << "Hi";
   					break;
   				case sf::Keyboard::S :
   					y=y+10;
   					sprite.setRotation(0);
   					//window.close();
   					//std:: cout << "Hi";
   					carb-=1;
   					break;
   				case sf::Keyboard::Q :
   					x=x-10;
   					sprite.setRotation(90);
   					carb-=1;
   					//window.close();
   					//std:: cout << "Hi";
   					break;
   				case sf::Keyboard::D :
   					x=x+10;
   					sprite.setRotation(-90);
   					//window.close();
   					//std:: cout << "Hi";
   					carb-=1;
   					break;
   				case sf::Keyboard::Space :
   					mode=2;
   					break;
			   }
		}
		}
	}

   // Clear the whole window before rendering a new frame
   window.clear();
   	text.setString("Carburant restant :"+ std::to_string(carb));
///    // Draw some graphical entities

	if(mode==0){
	
	sprite.setPosition(x,y);
	circle.setPosition(MouseX,MouseY);
 	window.draw(circle);
 	window.draw(sprite2);
 	window.draw(sprite);
 	window.draw(sprite3);
 	window.draw(text);
 	
 	if(x>350 && y>400 && x<450 && y<500){
 		window.draw(bouton);
 		text2.setString("Station");
 		window.draw(text2);
 		ok=1;
	 }
	 else{
	 	ok=0;
	 }
	 
 }else if(mode==1){
	window.draw(sprite4);
 	window.draw(bouton);
 	window.draw(bouton2);
 	text2.setString("Vaisseau");
 	window.draw(text2);
 	window.draw(text3);
 }else if(mode==2){
 	window.draw(sprite5);
 	window.draw(bouton3);
 	window.draw(text4);
 	if(click==1){
 		bouton4.setPosition(MouseX,MouseY);	
 		posX=MouseX;
 		posY=MouseY;
	 }
 	window.draw(bouton4);
 }

 	
 	
   // End the current frame and display its contents on screen
   window.display();
 }
 return 0;
}
