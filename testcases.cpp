#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "game.h"
#include <iostream>
#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp> 
#include <SFML/Audio.hpp>
#include <string>
#include <fstream>
#include <list>
using namespace std;

TEST_CASE("1: Game","[Game]"){
  Game m(10);
  REQUIRE(m.getTours() == 10);
}