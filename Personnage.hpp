#pragma once
#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp> 

class Personnage{
	public:

		virtual void reproduction(Personnage& p)=0;
		


	private:
		std::size_t Force;
		
		


};