#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <SFML/Graphics.hpp> 
#include <SFML/Audio.hpp>
#include <vector>
#include <list>
#include "Joueur.hpp"
#include "Hommes.hpp"
#include "Femmes.hpp"
#include "MutantsF_plus.hpp"
#include "MutantsF_minus.hpp"
#include "Mutants_pm.hpp"
#include "Cases.hpp"
#include "Pierre.hpp"
#include "Bois.hpp"
#include "Eau.hpp"
#include "Viande.hpp"
#include "Legumes.hpp"
#include <ctime>
#include <typeinfo>

class Game{
	private:

		sf::RenderWindow window;
		std::size_t tours;
		Joueur j;

		//vecteur de chaque type de personnage
		std::vector<Hommes> H;
		std::vector<Femmes> F;
		std::vector<Mutants_pm> PM;
		std::vector<MutantsF_minus> F_minus;
		std::vector<MutantsF_plus> F_plus;

		//listes de chaque type de ressources
		std::list<Eau> E;
		std::list<Bois> B;
		std::list<Pierre> P;
		std::list<Viande> V;
		std::list<Legumes> L;

		//vecteur de cases
		std::vector<Cases> C;


	public:
		Game(std::size_t t);
		void show();
		void cases(std::size_t x1,std::size_t y1,std::size_t x2, std::size_t y2,std::size_t i);
		void init_cases();
		void recolter();
		void consomme();
		void consomme_Fminus();
		void consomme_pm();
		void consomme_H();
		void consomme_F();
		bool repro_fin();
		bool recolte_direction(int a,int b);
		void mourir();
		bool repro_ok();
		void push_list(std::size_t t);
		std::size_t choix_reproduction(std::size_t x,std::size_t y);
		const std::size_t getTours(){return tours;}
		Personnage& return_perso(std::size_t t);
		Ressources& rand_ressources();
		const std::size_t getSizeE(){return E.size();}
		const std::size_t getSizeL(){return L.size();}
		const std::size_t getSizeV(){return V.size();}
	    std::vector<Hommes> getHvector(){return H;}

};
template<class T>
std::ostream& operator<< (std::ostream& out, std::vector<T> p){
	std::string str;
	for(std::size_t i=0;i<p.size();i++){
		str += p[i].str(p[i].getType_r())+" Vie : " + std::to_string(p[i].getVie())+"\n";
	}
	
    out<<str;
    return out;
}
