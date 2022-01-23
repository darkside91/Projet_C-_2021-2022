#include "Cases.hpp"

std::ostream& operator<< (std::ostream& out, Cases& c){
	std::string str;
	if(c.Size_R()<1){
		str = "ZONE VIDE\n";
	}
	else{
		for(std::size_t i=0;i<c.Size_R();i++){
			str += std::to_string(i+1);
			str += " "+ c.getR(i).str() +" | ";
		}
		
	}

    out<<str;
    return out;
}

Cases::Cases(std::size_t _x1,std::size_t _y1,std::size_t _x2, std::size_t _y2){
	x1 = _x1;
	y1 = _y1;
	y2 = _y2;
	x2 = _x2;
	
}

std::size_t Cases::getTypeR(std::size_t i){	
	return R[i].getType();
}