#include "Personnage.hpp"

void Personnage::Perdre_vie(){
	Vie--;
	if(Vie<=0){
		vivant = false;
	}
}