#include "game.h"


Ressources& Game::rand_ressources(){
	int x = rand()%5;
	Viande a;
	Viande& V =a;
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

void Game::cases(std::size_t x1,std::size_t y1,std::size_t x2, std::size_t y2,std::size_t i){
	for(std::size_t j = 0;j<i;j++){
		Cases c1(x1,y1,x2,y2);
		Ressources r = rand_ressources();
		printf("numR %d\n",r.getNum() );

		c1.remplir_case(r);
		Ressources r2 = rand_ressources();
		c1.remplir_case(r2);
		C.push_back(c1);
		x1 += 50;
		x2 += 50;
	}
}

void Game::init_cases(){
	cases(783,516,835,552,10);
	cases(278,552,333,600,19);
	cases(249,513,301,556,8);
	cases(425,615,481,651,17);
	cases(458,658,511,695,12);
	cases(603,704,660,745,9);
	cases(692,750,751,782,7);
	cases(278,467,337,511,18);
	cases(249,418,305,463,19);
	cases(282,372,334,420,18);
	cases(306,329,358,376,17);
	cases(395,285,449,333,15);
	cases(424,240,482,282,11);
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

void Game::recolter(){
	std::size_t r;
	//récolter les ressources de la case, une fois récoltés la case ne contient plus de ressources
	
	for(std::size_t i=0;i<C.size();i++){
		if(j.getX()>=C[i].getX1() && j.getX()<=C[i].getX2() && j.getY()>= C[i].getY1() && j.getY()<= C[i].getY2()){
			//on ne récolte pas si la case a déjà été visitée. 
			for(std::size_t j=0;j<C[i].Size_R();j++){
				r=C[i].getTypeR(j);
				switch(r){
					case 0:
						L.push_back(Legumes());
						printf("legumes : %d\n",L.size() );
						break;
					case 1:
						V.push_back(Viande());
						printf("viande : %d\n",V.size() );
						break;
					case 2:
						E.push_back(Eau());
						printf("eau : %d\n",E.size() );
						break;
					case 3:
						P.push_back(Pierre());
						printf("Pierre : %d\n",P.size() );
						break;
					case 4:
						B.push_back(Bois());
						printf("bois : %d\n",B.size() );
						break;

				}
				printf("OK %d\n",r);
				C[i].erase_r(j);
			}
		
		}
	}


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
	std::size_t tour =0; //compteur de tours
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

	bool flag_escape = false;
	bool flag_debut = true;
	bool flag_end = false;
	bool win = true; //gagner ou perdu

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

           		case sf::Event::MouseButtonPressed :
           			//appuyer sur le bouton planète sur l'écran de pause
           			if(flag_escape == true){
           				if(event.mouseButton.x < 875 && event.mouseButton.x>726 && event.mouseButton.y < 686 && event.mouseButton.y > 521){
           					flag_escape = false;
           				}
           			
           			}
           			//pour les tests
           			std::cout << "mouse x: " << event.mouseButton.x << std::endl;
        			std::cout << "mouse y: " << event.mouseButton.y << std::endl;
           			break;
           }

           if (event.type == sf::Event::KeyPressed){

			//écran de pause
    		if (event.key.code == sf::Keyboard::Escape ){
				if(flag_escape == false){
    				flag_escape = true;
    			}
    		}


    		if (event.key.code == sf::Keyboard::Z){
    			if(i<8){
    				i++;
    			}
    			j.setX(j.getX()-12);
    			j.setY(j.getY()-38);
    			j.newPosition();
    			recolter();
    			tour++;

    		}
    		if (event.key.code == sf::Keyboard::E ){
    			if(i<8){
    				i++;
    			}
    			j.setX(j.getX()+45);
    			j.setY(j.getY()-40);
    			j.newPosition();
    			recolter();
    			tour++;
    		}
    		if (event.key.code == sf::Keyboard::D ){
    			if(i<8){
    				i++;
    			}
    			j.setX(j.getX()+75);
    			j.setY(j.getY()+10);
    			j.newPosition();
    			recolter();
    			tour++;
    		}
    		if (event.key.code == sf::Keyboard::X ){
    			if(i<8){
    				i++;
    			}
    			j.setX(j.getX()+45);
    			j.setY(j.getY()+40);
    			j.newPosition();
    			recolter();
    			tour++;

    		}
    		if (event.key.code == sf::Keyboard::W ){
    			if(i<8){
    				i++;
    			}
    			j.setX(j.getX()-5);
    			j.setY(j.getY()+50);
    			j.newPosition();
    			recolter();
    			tour++;
    		}
    		if (event.key.code == sf::Keyboard::Q ){
    			if(i<8){i++;}
    			j.setX(j.getX()-40);
    			j.setY(j.getY()+0);
    			j.newPosition();
    			recolter();
    			tour++;

    		}

		}


	}
		//plus de personnages à jouer
		if(H.size()==0 && F.size()==0 && PM.size()==0 && F_minus.size()==0 && F_plus.size()==0){
			flag_end = true;
			win = false;
		}
		//fin du jeu
		if(tour > tours){
			flag_end = true;

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
    
    this->window.display();}
    else if (flag_escape == false && flag_end == false){
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

   		numero2= std::to_string(P.size());
   		chemin2 = "Assets_visuels/";
   		nomComplet2 = chemin2 + numero2 + ext;
   		texture13.loadFromFile(nomComplet2);
   		V4.setTexture(texture13);

   		numero2= std::to_string(B.size());
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
	else if (flag_escape == true && flag_end == false){
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
		if(win == true){
			texture.loadFromFile("Assets_visuels/ecran_end_win.png");
			s.setTexture(texture);
			s.setScale(3.f,3.f);
			window.draw(s);
			this->window.display();
			
		}
		else if(win == false){
			texture.loadFromFile("Assets_visuels/ecran_end_loose.png");
			s.setTexture(texture);
			s.setScale(3.f,3.f);
			window.draw(s);
			this->window.display();		

		}

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

