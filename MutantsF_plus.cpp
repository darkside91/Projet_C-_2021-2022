#include "MutantsF_plus.hpp"

Personnage& MutantsF_plus::reproduction(Personnage& p){
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