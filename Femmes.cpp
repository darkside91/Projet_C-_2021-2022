#include "Femmes.hpp"
Personnage& Femmes::reproduction(Personnage& p){

	std::size_t x = rand()%7+1;

	//if(p.getType_perso()== 1 && p.getBool()==false)//humains ne peuvent se reproduire qu'avec humains, femme avec homme et vice versa
//{
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
//}

}


bool Femmes::choisir(std::size_t x,std::size_t y){


	if(x <1537 && x >1439 && y <185 && y >80){
           				return true;	
           					}
    else{
    	return false;
    }
}
