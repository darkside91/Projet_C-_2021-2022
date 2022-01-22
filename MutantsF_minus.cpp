#include "MutantsF_minus.hpp"

Personnage& MutantsF_minus::reproduction(Personnage& p){
	std::size_t x = rand()%3;

	if(x == 1){
		Mutants_pm p;
		Mutants_pm& pm = p;
		return pm;
	}
	if(x==2 ){
		MutantsF_minus fm;
		MutantsF_minus& f = fm;
		return f;

	}
	if(x==3){
		MutantsF_plus fp;
		MutantsF_plus& pf = fp;
		return pf;

	}

}

bool MutantsF_minus::choisir(std::size_t x,std::size_t y){


	if(x <1839 && x >1723 && y <343 && y >239){
           				return true;	
           					}
    else{
    	return false;
    }
}