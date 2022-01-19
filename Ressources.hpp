#pragma once
#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp> 

class Ressources{
	public:

		
		const std::size_t getNum(){return num;}
		void setNum(std::size_t i){num = i;}

	private:
		
		std::size_t num;
		



};