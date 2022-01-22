#include "Mutants_pm.hpp"

Personnage& Mutants_pm::reproduction(Personnage& p){
	std::size_t x = rand()%3+1;

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

bool Mutants_pm::choisir(std::size_t x,std::size_t y){


	if(x <1685 && x >1567 && y <343 && y >227){
           				return true;	
           					}
    else{
    	return false;
    }
}