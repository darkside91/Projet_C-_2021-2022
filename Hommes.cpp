#include "Hommes.hpp"


Personnage& Hommes::reproduction(Personnage& p){

	std::size_t x = rand()%7+1;

	if(x == 1 || x == 2 ){
		Hommes h;
		Hommes& hom = h;
		return hom;
	}
	if(x == 3 || x == 4 ){
		Femmes f;
		Femmes& fem = f;
		return fem;
	}
	if(x == 5 ){
		Mutants_pm pm;
		Mutants_pm& p = pm;
		return p;
	}
	if(x == 6 ){
		MutantsF_plus MF;
		MutantsF_plus& m = MF;
		return m;
	}
	if(x == 7 ){
		MutantsF_minus fm;
		MutantsF_minus& mfm = fm;
		return mfm;
	}

}

bool Hommes::choisir(std::size_t x,std::size_t y){


	if(x <1721 && x >1618 && y <185 && y >80){
           				return true;	
           					}
    else{
    	return false;
    }
}