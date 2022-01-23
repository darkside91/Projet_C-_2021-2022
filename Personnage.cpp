#include "Personnage.hpp"

void Personnage::Perdre_vie(){
	Vie--;
	if(Vie<=0){
		vivant = false;
	}
}

std::string Personnage::str(std::size_t t){
	if(t == 1){
		return "Homme";
	}
	else if(t == 2 ){
		return "Femme";
	}
	else if(t == 3){
		return "Mutants_pm";
	}
	else if(t == 4){
		return "MutantsF_plus";
	}
	else if(t == 5){
		return "MutantsF_minus";
	}
	
}

