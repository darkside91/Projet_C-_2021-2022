#pragma once
#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp> 
#include "Viande.hpp"
#include "Eau.hpp"
#include "Bois.hpp"
#include "Pierre.hpp"
#include "Legumes.hpp"
#include <typeinfo>

class Cases{
	public:
		Cases(std::size_t x1,std::size_t y1,std::size_t x2, std::size_t y2);
		void remplir_case(Ressources& r){R.push_back(r);}
		const std::size_t getX1(){return x1;}
		const std::size_t getY1(){return y1;}
		const std::size_t getX2(){return x2;}
		const std::size_t getY2(){return y2;}
		Ressources& getR(std::size_t i){return R[i];}

		std::size_t getTypeR(std::size_t i);
		std::size_t Size_R(){return R.size();}
		void erase_r(std::size_t i){R.erase(R.begin()+i);}


	private:
		//position du joueur
		std::size_t x1;
		std::size_t y1;
		std::size_t x2;
		std::size_t y2;
		std::vector<Ressources> R;



};

std::ostream& operator<< (std::ostream& out, Cases& c);
