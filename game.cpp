#include "game.h"

//fonction qui randomise la ressource de la case à l'initialisation
Ressources& Game::rand_ressources(){
	std::size_t x = rand()%5;
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

//fonction d'initialisation des cases
void Game::cases(std::size_t x1,std::size_t y1,std::size_t x2, std::size_t y2,std::size_t i){
	for(std::size_t j = 0;j<i;j++){
		Cases c1(x1,y1,x2,y2);
		Ressources r = rand_ressources();
		c1.remplir_case(r);
		Ressources r2 = rand_ressources();
		c1.remplir_case(r2);
		C.push_back(c1);
		x1 += 50;
		x2 += 50;
	}
}

//Seconde fonction d'initialisation des cases pour créer une map 
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

//Constructeur
Game::Game(std::size_t t){
	this->tours=t;
	this->window.create(sf::VideoMode(1600, 1000), "Last Earth");

	init_cases();

	//Villageois et ressources de base
	H.push_back(Hommes());
	F.push_back(Femmes());
	V.push_back(Viande());
	E.push_back(Eau());
	E.push_back(Eau());
	L.push_back(Legumes());
	L.push_back(Legumes());
	B.push_back(Bois());
	P.push_back(Pierre());
	
}

void Game::recolter(){
	std::size_t r;
	//récolter les ressources de la case, une fois récoltée, la case ne contient plus de ressources
	//refaire pour obtenir 2 ressources

	for(std::size_t i=0;i<C.size();i++){

		if(j.getX()>=C[i].getX1() && j.getX()<=C[i].getX2() && j.getY()>= C[i].getY1() && j.getY()<= C[i].getY2()){
			//on ne récolte pas si la case a déjà été visitée.

			//on affiche ce que contient la case 
			std::cout << C[i]<< std::endl;

			//selon ce qu'on contient la case on ajoute à la bonne liste la ressource
			for(std::size_t j=0;j<C[i].Size_R();j++){
				r=C[i].getTypeR(j);
				switch(r){
					case 0:
						L.push_back(Legumes());
						printf("Legumes : %d\n",L.size() );
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
						printf("Bois : %d\n",B.size() );
						break;

				}
				
				C[i].erase_r(j);
			}
		
		}
	}

}

//fonction de fin de reproduction
bool Game::repro_fin(){
    sleep(2);
    //on compte les morts après la repro
    mourir();
    return false;
}

bool Game::recolte_direction(int a,int b){
    	j.setX(j.getX()+a);
    	j.setY(j.getY()+b);
    	j.newPosition();
    	recolter();
    	recolter();
    	return true;
}
//fonction qui récupère les coordonnées du click du joueur et en déduit le type du personnage
std::size_t Game::choix_reproduction(std::size_t x,std::size_t y){
	std::size_t p1 =0;

           	if(H.size()>0){
           		if(H[0].choisir(x,y)){
           			p1 = 1;
           		}
           	}

           	if(F.size()>0){
           		if(F[0].choisir(x,y)){
           			p1 = 2;
           		}
           	}

           	if(PM.size()>0){
           		if(PM[0].choisir(x,y)){
           			p1 = 3;
           		}
           	}

           	if(F_plus.size()>0){
           		if(F_plus[0].choisir(x,y)){
           			p1 = 4;
           		}
           	}

           	if(F_minus.size()>0){
           		if(F_minus[0].choisir(x,y)){
           			p1 = 5;
           		}
           	}

           	return p1;
}



void Game::show(){

	sf::Texture texture;
	sf::Texture texture2;
	sf::Texture texture3;
	sf::Texture texture4; //0
	sf::Texture texture5; //1.png
	sf::Texture texture6; // 2.Png
	sf::Texture texture7;
	sf::Texture texture8;//3
	sf::Texture texture9; //4
	sf::Texture texture10; //5
	sf::Texture texture11; //6
	sf::Texture texture12; //7
	sf::Texture texture13; //8
	sf::Texture texture14; //9
	sf::Texture texture_feed; //bouton bleu 
	sf::Texture yes; //bouton oui
	sf::Texture no; //bouton non
	sf::Texture regles; //regles du jeu

	std::size_t i = 1;
	std::size_t tour =0; //compteur de tours
	//permet de récupérer le bon sprite quand on update les listes et les vecteurs
	std::string chemin="Carte/fd/";
	std::string ext=".png";
	std::string numero;
	std::string nomComplet;
	std::string numero2;
	std::string chemin2;
	std::string nomComplet2;

	//Sprites
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
	sf::Sprite feed_button;
	sf::Sprite yes_button;
	sf::Sprite no_button;

	//Initialisation Sprites & Textures
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

   	//booléen pour découper le tour en plusieurs parties
	bool flag_escape = false;
	bool flag_debut = true;
	bool flag_end = false;
	bool win = true; //gagner ou perdu
	bool flag_feed = false;
	bool flag_reproduction = false;
	bool repro = false;
	
	//permet d'utiliser correctement la fonction reproduction
	std::size_t p1 = 0;
	std::size_t p2 = 0;

	while (this->window.isOpen())
 	{
    // Event processing
    	sf::Event event;

   		while (this->window.pollEvent(event))
   		{
   			switch (event.type){
		  		
		  		//permet de fermer la fenêtre
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
           			//appuyer sur le bouton bleu pour consommer les ressources
           			if(flag_feed == true){
           				if(event.mouseButton.x <938 && event.mouseButton.x >752 && event.mouseButton.y <412 && event.mouseButton.y >245){
           					consomme();
           					flag_feed = false;
           					flag_reproduction = true;
           				}
           			}
           			//appuyer sur le petit bouton bleu pour oui et le petit bouton rouge pour non
           			if(flag_reproduction == true && repro == false){
           				//bouton oui
           				if(event.mouseButton.x <736 && event.mouseButton.x >647 && event.mouseButton.y <622 && event.mouseButton.y >530){
           					
           					if(P.size()>0 || B.size()>0){

           						//on appuie sur deux personnages différents
           						//on vérifie si on a au moins 2 personnages
           						if(repro_ok()){
           							repro = true;
           						}
           						else{
           							std::cout << "Reproduction fail : pas assez de villageois"<<std::endl;
           							flag_reproduction = repro_fin();
           						}
           					}
           					else{
           						std::cout << "Reproduction fail : pas assez de bois ou de pierre"<<std::endl;
           						flag_reproduction = repro_fin();
           					}
           				}
           				//Bouton non
           				if(event.mouseButton.x <1092 && event.mouseButton.x >997 && event.mouseButton.y <627 && event.mouseButton.y >524){
           					flag_reproduction = repro_fin();
           				}
           			}
           			if(repro == true){
           				// On choisit nos deux personnages
           				if(p1 == 0){

           				p1 = choix_reproduction(event.mouseButton.x,event.mouseButton.y);
           			}
           			else{
           				p2 = choix_reproduction(event.mouseButton.x,event.mouseButton.y);
           			}
           			if(p1>0 && p2>0){
           				std::size_t type = return_perso(p1).reproduction(return_perso(p2)).getType_r();
           				//ajout du nouvel individu
           				push_list(type);
           				//consommation ressource reproduction pour augmenter la difficulté
           				/*if(B.size()>0){
           					B.pop_back();
           				}
           				else if(P.size()>0){
           					P.pop_back();
           				}*/

           				//remise à la normale des flags	
           				flag_reproduction = repro_fin();
           				repro = false;
           				p1 = 0;
           				p2 = 0;


           			}

           		}
           		//pour les tests
           		//std::cout << "mouse x: " << event.mouseButton.x << std::endl;
        		//std::cout << "mouse y: " << event.mouseButton.y << std::endl;
           		break;
           }

           if (event.type == sf::Event::KeyPressed && flag_feed == false && flag_reproduction == false && repro == false){

			//écran de pause
    		if (event.key.code == sf::Keyboard::Escape ){
				if(flag_escape == false){
    				flag_escape = true;
    			}
    		}
    		//récolte et mouvement

    		if (event.key.code == sf::Keyboard::Z){
    			
    			flag_feed = recolte_direction(-12,-38);
    			if(i<8){i++;}
    			tour++;

    		}
    		if (event.key.code == sf::Keyboard::E ){

    			flag_feed = recolte_direction(+45,-40);
    			if(i<8){i++;}
    			tour++;
    		}
    		if (event.key.code == sf::Keyboard::D ){

    			flag_feed = recolte_direction(75,10);
    			if(i<8){i++;}
    			tour++;
    		}
    		if (event.key.code == sf::Keyboard::X ){
    			flag_feed = recolte_direction(45,40);
    			if(i<8){i++;}
    			tour++;

    		}
    		if (event.key.code == sf::Keyboard::W ){
    			flag_feed = recolte_direction(-5,50);
    			if(i<8){i++;}
    			tour++;
    		}
    		if (event.key.code == sf::Keyboard::Q ){

    			flag_feed = recolte_direction(-40,0);
    			if(i<8){i++;}
    			tour++;

    		}

		}

	}
	//plus de personnages à jouer -> on perd
	if(H.size()==0 && F.size()==0 && PM.size()==0 && F_minus.size()==0 && F_plus.size()==0){
		flag_end = true;
		win = false;
	}
	//fin du jeu si le nombre de tours est passé
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
    
       this->window.display();
    }
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

    if(flag_feed == true){
   			texture_feed.loadFromFile("Assets_visuels/water.png");
   			feed_button.setTexture(texture_feed);
   			feed_button.setScale(0.5f,0.5f);
   			feed_button.setPosition(744,232);
   			window.draw(feed_button);

   		}
   	if(flag_reproduction == true){
   		texture_feed.loadFromFile("Assets_visuels/heart.png");
   		feed_button.setTexture(texture_feed);
   		feed_button.setScale(0.5f,0.5f);
   		feed_button.setPosition(744,232);
   		yes.loadFromFile("Assets_visuels/blue2.png");
   		yes_button.setTexture(yes);
   		yes_button.setScale(0.3f,0.3f);
   		yes_button.setPosition(632,518);
   		no.loadFromFile("Assets_visuels/red.png");
   		no_button.setTexture(no);
   		no_button.setScale(0.3f,0.3f);
   		no_button.setPosition(985,518);
   		window.draw(feed_button);
   		window.draw(yes_button);
   		window.draw(no_button);
   	}

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

   		regles.loadFromFile("Assets_visuels/Regles_du_jeu.png");
   		Regles_du_jeu.setTexture(regles);
   		Regles_du_jeu.setPosition(1000,200);

    	window.draw(s);
    	window.draw(button);
    	window.draw(s2);
    	window.draw(Regles_du_jeu);


    	this->window.display();
		
	}

	//fin du jeu
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
			s.setScale(2.f,2.f);
			window.draw(s);
			this->window.display();		

		}

	}
	
}	
	
}

//fonction de consommation des ressources alimentaires incluant tous les personnages
void Game::consomme(){

	//les humains ne consomment que les ressources alimentaires

	consomme_H();
	consomme_F();
	consomme_pm();
	consomme_Fminus();
	consomme_Fminus();

	for(std::size_t i=0;i<F_plus.size();i++){
		F_plus[i].Perdre_vie();
		//les mutants_plus ne peuvent pas mourir sans ressources, ils ne font que perdre de la vie
	}

}

//fonction de consommation des hommes
void Game::consomme_H(){
		for(std::size_t i=0;i<H.size();i++){
		H[i].Perdre_vie();
		if(E.size()==0 && V.size()==0 && L.size()==0){
			H[i].setVivant(false); //mort de faim 
		}
		//les humains mangent la viande puis les légumes puis l'eau
		if(V.size()> 0){
			V.pop_back();
		}
		else if(L.size()>0){
			L.pop_back();
		}
		else if(E.size()>0){
			E.pop_back();
		}
	}
}

//fonction de consommation des femmes
void Game::consomme_F(){
	for(std::size_t i=0;i<F.size();i++){
		F[i].Perdre_vie();
		if(E.size()==0 && V.size()==0 && L.size()==0){
			F[i].setVivant(false); //mort de faim 
		}
		if(V.size()> 0){
			V.pop_back();
		}
		else if(L.size()>0){
			L.pop_back();
		}
		else if(E.size()>0){
			E.pop_back();
		}
		

	}

}
//fonction de consommation mutants_pm
void Game::consomme_pm(){
	for(std::size_t i=0;i<PM.size();i++){
		PM[i].Perdre_vie();
		//les mutants_pm peuvent consommer n'importe quelle ressource (bois et pierre incluses)
		//ils consomment de préférence les mêmes ressources que les humains mais peuvent survivre uniquement de ressources non alimentaires
		if(E.size()==0 && V.size()==0 && L.size()==0 && B.size()==0 && P.size()==0){
			PM[i].setVivant(false); //mort de faim 
		}
		if(V.size()> 0){
			V.pop_back();
		}
		else if(L.size()>0){
			L.pop_back();
		}
		else if(E.size()>0){
			E.pop_back();
		}
		else if(B.size()>0){
			B.pop_back();
		}
		else if(P.size()>0){
			P.pop_back();
		}

	}
}
//fonction de consommation des mutantsF_minus
//Les mutants F_minus consomment 2 ressources et peuvent consommer les 5 types de ressources
void Game::consomme_Fminus(){
	for(std::size_t i=0;i<F_minus.size();i++){
		F_minus[i].Perdre_vie();
		
		if(E.size()==0 && V.size()==0 && L.size()==0 && B.size()==0 && P.size()==0){
			F_minus[i].setVivant(false); //mort de faim 
		}
		if(V.size()> 0){
			V.pop_back();

		}
		else if(L.size()>0){
			L.pop_back();
			
		}
		else if(E.size()>0){
			E.pop_back();
		
		}
		else if(B.size()>0){
			B.pop_back();
		
		}
		else if(P.size()>0){
			P.pop_back();
			
		}
	
	}

}

//fonction qui permet d'enlever les personnages morts à ce tour
void Game::mourir(){
	
	for(std::size_t i=0;i<H.size();i++){
		if(H[i].getVivant()==false){
			H.pop_back();
			std::cout<<"Un homme est mort"<<std::endl;
		}
	}
	for(std::size_t i=0;i<F.size();i++){
		if(F[i].getVivant()==false){
			F.pop_back();
			std::cout<<"Une femme est morte"<<std::endl;
		}
	}
	for(std::size_t i=0;i<PM.size();i++){
		if(PM[i].getVivant()==false){
			PM.pop_back();
			std::cout<<"Un mutant_pm est mort"<<std::endl;
		}
	}
	for(std::size_t i=0;i<F_minus.size();i++){
		if(F_minus[i].getVivant()==false){
			F_minus.pop_back();
			std::cout<<"Un mutant_minus est mort"<<std::endl;
		}
	}
	for(std::size_t i=0;i<F_plus.size();i++){
		if(F_plus[i].getVivant()==false){
			F_plus.pop_back();
			std::cout<<"Un mutant_plus est mort"<<std::endl;
		}
	}

}

//Fonction qui permet de vérifier si la reproduction est possible
bool Game::repro_ok(){
	if((H.size()+PM.size()+F_minus.size()+F_plus.size())>1){
		return true;
	}
	else if((F.size()+PM.size()+F_minus.size()+F_plus.size())>1){
		//les mutants peuvent se reproduire avec tout le monde peu importe le sexe
		return true;
	}
	else if(F.size()>0 && H.size()>0 ){
		return true;
	}
	else{
		return false;
	}
}

//fonction qui permet de retourner un personnage en entrant son numéro de type
Personnage& Game::return_perso(std::size_t t){
	if(t ==1){
		Hommes hom;
		Hommes& h=hom;
		return h;
	}
	else if(t ==2){
		Femmes fem;
		Femmes& f=fem;
		return f;
	}
	else if(t ==3){
		Mutants_pm mpm;
		Mutants_pm& pm=mpm;
		return pm;
	}
	else if(t ==4){
		MutantsF_plus pfp;
		MutantsF_plus& fp=pfp;
		return fp;
	}
	else if(t ==5){
		MutantsF_minus mfm;
		MutantsF_minus& fm=mfm;
		return fm;
	}
}

//ajout du nouvel individu
void Game::push_list(std::size_t t){
	if(t ==1){
		H.push_back(Hommes());
		std::cout << H<<std::endl;
	}
	else if(t ==2){
		F.push_back(Femmes());
		std::cout << F << std::endl;
	}
	else if(t ==3){
		PM.push_back(Mutants_pm());
		std::cout << PM << std::endl;
	}
	else if(t ==4){
		F_plus.push_back(MutantsF_plus());
		std::cout << F_plus << std::endl;
	}
	else if(t ==5){
		F_minus.push_back(MutantsF_minus());
		std::cout << F_minus << std::endl;
	}

}
