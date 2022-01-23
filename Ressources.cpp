#include "Ressources.hpp"

std::string Ressources::str(){
	if(type == 1){
		return "Viande";
	}
	else if(type == 2 ){
		return "Eau";
	}
	else if(type == 3){
		return "Pierre";
	}
	else if(type == 4){
		return "Bois";
	}
	else if(type == 0){
		return "Legumes";
	}
	else{
		return "Ressources";
	}
}