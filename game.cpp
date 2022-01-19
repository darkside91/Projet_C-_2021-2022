#include "game.h"



Ressources& Game::rand_ressources(){
	int x = rand()%5;
	Viande a;
	Viande& V = a;
	Legumes b;
	Legumes& L = b;
	Eau c;
	Eau& E = c;
	Pierre d;
	Pierre& P = d;
	Bois e;
	Bois& R = e;

	switch(x)
	{
		case 0:
			return V;
			break;
		case 1:
		
			return L;
			break;
		case 2:
			
			return E;
			break;
		case 3:
			
			return P;
			break;
		case 4:
			
			return R;
			break;

	}

	

}

void Game::init_cases(){
	std::size_t x1,x2,y1,y2;
	x1 = 783; //x de gauche
	y1 = 516; // y du haut
	x2 = 835; // x de droite
	y2 = 552; // y du bas

	for(std::size_t i = 0;i<10;i++){
		Cases c1(x1,y1,x2,y2);

		c1.remplir_case(rand_ressources());
		c1.remplir_case(rand_ressources());
		C.push_back(c1);
		x1 += 52;
		x2 += 52;
	}
	y1 = y2;
	y2 = 600;
	x1 = 278;
	x2 = 333;

	for(std::size_t i=0;i<19;i++){
		Cases c1(x1,y1,x2,y2);

		c1.remplir_case(rand_ressources());
		c1.remplir_case(rand_ressources());
		C.push_back(c1);
		x1 += 52;
		x2 += 52;

	}
	y1 = 513;
	x1 = 249;
	y2 = 556;
	x2 = 301;
	for(std::size_t i=0;i<8;i++){
		Cases c1(x1,y1,x2,y2);

		c1.remplir_case(rand_ressources());
		c1.remplir_case(rand_ressources());
		C.push_back(c1);
		x1 += 52;
		x2 += 52;

	}
	y1 = 615;
	x1 = 425;
	y2 = 651;
	x2 = 481;
	for(std::size_t i=0;i<17;i++){
		Cases c1(x1,y1,x2,y2);

		c1.remplir_case(rand_ressources());
		c1.remplir_case(rand_ressources());
		C.push_back(c1);
		x1 += 52;
		x2 += 52;
	}
	x1 = 458;
	y1 = 658;
	x2 = 511;
	y2 = 695;
	for(std::size_t i=0;i<12;i++){
		Cases c1(x1,y1,x2,y2);

		c1.remplir_case(rand_ressources());
		c1.remplir_case(rand_ressources());
		C.push_back(c1);
		x1 += 52;
		x2 += 52;
	}
	x1 = 603;
	y1 = 704;
	x2 = 660;
	y2 = 745;
	for(std::size_t i=0;i<9;i++){
		Cases c1(x1,y1,x2,y2);

		c1.remplir_case(rand_ressources());
		c1.remplir_case(rand_ressources());
		C.push_back(c1);
		x1 += 52;
		x2 += 52;
	}
	x1 = 692;
	y1 = 750;
	x2 = 751;
	y2 = 782;
	for(std::size_t i=0;i<7;i++){
		Cases c1(x1,y1,x2,y2);

		c1.remplir_case(rand_ressources());
		c1.remplir_case(rand_ressources());
		C.push_back(c1);
		x1 += 52;
		x2 += 52;
	}
	x1 = 278;
	y1 = 467;
	x2 = 337;
	y2 = 511;
	for(std::size_t i=0;i<18;i++){
		Cases c1(x1,y1,x2,y2);

		c1.remplir_case(rand_ressources());
		c1.remplir_case(rand_ressources());
		C.push_back(c1);
		x1 += 52;
		x2 += 52;
	}
	x1 = 249;
	y1 = 418;
	x2 = 305;
	y2 = 463;
	for(std::size_t i=0;i<19;i++){
		Cases c1(x1,y1,x2,y2);

		c1.remplir_case(rand_ressources());
		c1.remplir_case(rand_ressources());
		C.push_back(c1);
		x1 += 52;
		x2 += 52;
	}
	x1 = 282;
	y1 = 372;
	x2 = 334;
	y2 = 420;
	for(std::size_t i=0;i<18;i++){
		Cases c1(x1,y1,x2,y2);

		c1.remplir_case(rand_ressources());
		c1.remplir_case(rand_ressources());
		C.push_back(c1);
		x1 += 52;
		x2 += 52;
	}
	x1 = 306;
	y1 = 329;
	x2 = 358;
	y2 = 376;
	for(std::size_t i=0;i<17;i++){
		Cases c1(x1,y1,x2,y2);

		c1.remplir_case(rand_ressources());
		c1.remplir_case(rand_ressources());
		C.push_back(c1);
		x1 += 52;
		x2 += 52;
	}
	x1 = 395;
	y1 = 285;
	x2 = 449;
	y2 = 333;
	for(std::size_t i=0;i<15;i++){
		Cases c1(x1,y1,x2,y2);

		c1.remplir_case(rand_ressources());
		c1.remplir_case(rand_ressources());
		C.push_back(c1);
		x1 += 52;
		x2 += 52;
	}
	x1 = 424;
	y1 = 240;
	x2 = 482;
	y2 = 282;
	//ligne de 11 en dessous des rochers du haut
	for(std::size_t i=0;i<11;i++){
		Cases c1(x1,y1,x2,y2);

		c1.remplir_case(rand_ressources());
		c1.remplir_case(rand_ressources());
		C.push_back(c1);
		x1 += 52;
		x2 += 52;
	}

}

Game::Game(int a){
	this->tours=a;
	this->window.create(sf::VideoMode(1600, 1000), "Last Earth");

	init_cases();

	//Villageois et ressources de base

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
	sf::Texture texture5; //0.png
	sf::Texture texture6; // 2.Png
	sf::Texture texture7;
	sf::Texture texture8;//3
	sf::Texture texture9; //4
	sf::Texture texture10; //5
	sf::Texture texture11; //6
	sf::Texture texture12; //7
	sf::Texture texture13; //8
	sf::Texture texture14; //9


	std::size_t i = 1;
	std::string chemin="Carte/fd/";
	std::string ext=".png";
	std::string numero;
	std::string nomComplet;
	std::string numero2;
	std::string chemin2;
	std::string nomComplet2;

	sf::Sprite s;
	sf::Sprite button;
	sf::Sprite s2;
	sf::Sprite s3;
	sf::Sprite Regles_du_jeu;
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
	sf::Sprite press_escape;


    texture.loadFromFile("Carte/fd/1.png");
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
   	texture5.loadFromFile("Assets_visuels/1.png");
   	texture4.loadFromFile("Assets_visuels/0.png");
   	texture6.loadFromFile("Assets_visuels/2.png");
   	texture8.loadFromFile("Assets_visuels/3.png");
   	texture9.loadFromFile("Assets_visuels/4.png");
   	texture10.loadFromFile("Assets_visuels/5.png");
   	texture11.loadFromFile("Assets_visuels/6.png");
   	texture12.loadFromFile("Assets_visuels/7.png");
   	texture13.loadFromFile("Assets_visuels/8.png");
   	texture14.loadFromFile("Assets_visuels/9.png");


   	sH.setTexture(texture5);
   	sH.setPosition(1700,200); //numéro Homme
   	sH.setScale(1.5f,1.5f);
   	sF.setTexture(texture5);
   	sF.setScale(1.5f,1.5f);
   	sF.setPosition(1516,200);
   	sMplus.setTexture(texture4);
   	sMplus.setScale(1.5f,1.5f);
   	sMplus.setPosition(1466,368);
   	sMminus.setTexture(texture4);
   	sMminus.setScale(1.5f,1.5f);
   	sMminus.setPosition(1783,371);
   	sMpm.setTexture(texture4);
   	sMpm.setScale(1.5f,1.5f);
   	sMpm.setPosition(1630,373);

   	V1.setTexture(texture5);
   	V1.setScale(1.5f,1.5f);
   	V1.setPosition(1527,608);

   	V2.setTexture(texture5);
   	V2.setScale(1.5f,1.5f);
   	V2.setPosition(1527,698);

   	V3.setTexture(texture6);
   	V3.setScale(1.5f,1.5f);
   	V3.setPosition(1525,800);

   	V4.setTexture(texture5);
   	V4.setScale(1.5f,1.5f);
   	V4.setPosition(1688,758);

   	V5.setTexture(texture5);
   	V5.setScale(1.5f,1.5f);
   	V5.setPosition(1688,636);

   	texture7.loadFromFile("Assets_visuels/press_escape.png");
   	press_escape.setTexture(texture7);
   	press_escape.setPosition(500,100);

	bool flag_escape = false;
	bool flag_debut = true;
	bool flag_end = false;

	while (this->window.isOpen())
 	{
    // Event processing
    	sf::Event event;

    
   		while (this->window.pollEvent(event))
   		{
   			switch (event.type){
		  
       			case sf::Event::Closed :
           			this->window.close();
           			break;

           		case sf::Event::MouseButtonPressed:
           			//appuyer sur le bouton planète sur l'écran de pause
           			if(flag_escape == true){
           				if(event.mouseButton.x < 875 && event.mouseButton.x>726 && event.mouseButton.y < 686 && event.mouseButton.y > 521){
           					flag_escape = false;
           				}
           			
           			
           			}
           			//pour les tests
           			std::cout << "mouse x: " << event.mouseButton.x << std::endl;
        			std::cout << "mouse y: " << event.mouseButton.y << std::endl;
           			
    			/*if(flag_escape == false ){
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
    			}*/
           		
           		
           		break;
           }
           if (event.type == sf::Event::KeyPressed)
			{

				//écran de pause
    		if (event.key.code == sf::Keyboard::Escape )
    			{

    				if(flag_escape == false){
    					flag_escape = true;
    					

        				/*texture.loadFromFile("Carte/menu.png");
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

    					this->window.display();*/}
    				/*else{
    					flag_escape = false;
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
    				}*/
        
    			}

    			if (event.key.code == sf::Keyboard::Z){
    				if(i<8){
    					i++;
    				}
    				j.setX(j.getX()-12);
    				j.setY(j.getY()-38);
    				j.newPosition();
    				

    			}
    			if (event.key.code == sf::Keyboard::E ){
    				if(i<8){
    					i++;
    				}
    				j.setX(j.getX()+45);
    				j.setY(j.getY()-40);
    				j.newPosition();


    			}
    			if (event.key.code == sf::Keyboard::D ){
    				if(i<8){
    					i++;
    				}
    				j.setX(j.getX()+75);
    				j.setY(j.getY()+10);
    				j.newPosition();
    			}
    			if (event.key.code == sf::Keyboard::X ){
    				if(i<8){
    					i++;
    				}
    				j.setX(j.getX()+45);
    				j.setY(j.getY()+40);
    				j.newPosition();

    			}
    			if (event.key.code == sf::Keyboard::W ){
    				if(i<8){
    					i++;
    				}
    				j.setX(j.getX()-5);
    				j.setY(j.getY()+50);
    				j.newPosition();
    			}
    			if (event.key.code == sf::Keyboard::Q ){
    				if(i<8){
    					i++;
    				}
    				j.setX(j.getX()-40);
    				j.setY(j.getY()+0);
    				j.newPosition();

    			}

			}


		}

	if(flag_debut == true){
	flag_debut = false;
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
    window.draw(press_escape);
    this->window.display();}
    else if (flag_escape == false){
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

   		numero2= std::to_string(H.size());
   		chemin2 = "Assets_visuels/";
   		nomComplet2 = chemin2 + numero2 + ext;
   		texture5.loadFromFile(nomComplet2);

   		sH.setTexture(texture5);

   		numero2= std::to_string(F.size());
   		chemin2 = "Assets_visuels/";
   		nomComplet2 = chemin2 + numero2 + ext;
   		texture6.loadFromFile(nomComplet2);
   		sF.setTexture(texture6);


   		numero2= std::to_string(PM.size());
   		chemin2 = "Assets_visuels/";
   		nomComplet2 = chemin2 + numero2 + ext;
   		texture7.loadFromFile(nomComplet2);
   		sMpm.setTexture(texture7);

   		numero2= std::to_string(F_minus.size());
   		chemin2 = "Assets_visuels/";
   		nomComplet2 = chemin2 + numero2 + ext;
   		texture8.loadFromFile(nomComplet2);
   		sMminus.setTexture(texture8);

   		numero2= std::to_string(F_plus.size());
   		chemin2 = "Assets_visuels/";
   		nomComplet2 = chemin2 + numero2 + ext;
   		texture9.loadFromFile(nomComplet2);
   		sMplus.setTexture(texture9);

   		numero2= std::to_string(V.size());
   		chemin2 = "Assets_visuels/";
   		nomComplet2 = chemin2 + numero2 + ext;
   		texture10.loadFromFile(nomComplet2);
   		V1.setTexture(texture10);
   		
   		numero2= std::to_string(L.size());
   		chemin2 = "Assets_visuels/";
   		nomComplet2 = chemin2 + numero2 + ext;
   		texture11.loadFromFile(nomComplet2);
   		V2.setTexture(texture11);

   		numero2= std::to_string(E.size());
   		chemin2 = "Assets_visuels/";
   		nomComplet2 = chemin2 + numero2 + ext;
   		texture12.loadFromFile(nomComplet2);
   		V3.setTexture(texture12);

   		numero2= std::to_string(B.size());
   		chemin2 = "Assets_visuels/";
   		nomComplet2 = chemin2 + numero2 + ext;
   		texture13.loadFromFile(nomComplet2);
   		V4.setTexture(texture13);

   		numero2= std::to_string(P.size());
   		chemin2 = "Assets_visuels/";
   		nomComplet2 = chemin2 + numero2 + ext;
   		texture14.loadFromFile(nomComplet2);
   		V5.setTexture(texture14);

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

	}
	else if (flag_escape == true){
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

    	this->window.display();
		
	}
	else if(flag_end == true){



	}
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
	sf::Texture texture7; 


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
	sf::Sprite press_escape;

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
    window.draw(press_escape);
    this->window.display();
    //this->window.clear();
   
	
}

