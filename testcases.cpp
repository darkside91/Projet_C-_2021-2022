#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "game.h"
#include <iostream>
#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp> 
#include <string>
#include <fstream>
#include <list>
using namespace std;

TEST_CASE("1: Game","[initialisation]"){
  Game g(10);
  REQUIRE(g.getSizeE() == 2);
  REQUIRE(g.getSizeV() == 1);
  REQUIRE(g.getSizeL() == 2);
}

//vérifie si la fonction rand_ressources() retourne bien une ressource 
TEST_CASE("2: Game","[rand_ressources]"){
  Game g(10);
  Ressources& r = g.rand_ressources();
  Ressources r2;
  Ressources& r3 = r2;
  const type_info& ti = typeid(r);
  const type_info& ti2 = typeid(r3);
  REQUIRE(ti == ti2);
}

//vérifie la si la fonction return_perso() retourne bien homme
TEST_CASE("3: Game","[return_perso]"){
  Game g(10);
  const type_info& ti = typeid(g.return_perso(1));
  Hommes h1;
  Hommes& h = h1;
  const type_info& ti2 = typeid(h);
  REQUIRE(ti == ti2);
}

//Vérifie si la reproduction() fonctionne
TEST_CASE("4: Hommes","[reproduction]"){
  Hommes h;
  //pour cela il faut vérifier qu'on renvoie bien un personnage
  Femmes f2;
  Personnage& p2 = f2.reproduction(h);
  Personnage& p = f2;
  const type_info& ti = typeid(&p);
  const type_info& ti2 = typeid(&p2);

  REQUIRE(ti == ti2);
}

//vérifie l'iniatilisation des personnages et la perte de vie
TEST_CASE("5: Femmes","[initialisation & Perdre_vie]"){
  Femmes f;
  REQUIRE(f.getVie()==5);
  f.Perdre_vie();
  REQUIRE(f.getVie()==4);
  REQUIRE(f.getVivant()== true);
  REQUIRE(f.getBool()==true);
  for(std::size_t i=0;i<4;i++){
  	f.Perdre_vie();
  }
  REQUIRE(f.getVivant()==false);

}

// vérifie les fonctions de remplissage et d'effacement de Cases
// vérifie aussi la surcharge d'opérateurs
TEST_CASE("6: Cases","[fonctions]"){
  Cases c1(1,1,2,2);
  Viande v,v2;
  Ressources& rv = v;
  Ressources& rv2 = v2;
  Eau e,e2;
  Ressources& re = e;
  Ressources& re2 = e2;
  c1.remplir_case(rv);
  c1.remplir_case(re);
  c1.remplir_case(rv2);
  c1.remplir_case(re2);
  REQUIRE(c1.getTypeR(1)==2);
  REQUIRE(c1.getTypeR(0)==1);
  c1.erase_r(1);
  REQUIRE(c1.getTypeR(1)==1);
  //Test de la surcharge
  std::stringstream ss;
  ss << c1;
  REQUIRE(ss.str()=="1 Viande | 2 Viande | 3 Eau | " );

}

//test de la surcharge d'opérateur des vecteurs de Personnage
TEST_CASE("7: Game","[template_surcharge_operateurs]"){
  Game g(5);
  std::vector<Hommes> x = g.getHvector();
  //Test de la surcharge
  std::stringstream ss;
  ss << x;
  REQUIRE(ss.str()=="Homme Vie : 5\n" );

}

//vérifie qu'on ajoute bien un nouveau personnage avec la fonction push_list
TEST_CASE("8: Game","[push_list]"){
  Game g(5);
  g.push_list(1);
  REQUIRE(g.getHvector().size()==2);

}

//Test fonction choix reproduction
TEST_CASE("9: Game","[choix_reproduction]"){
  Game g(5);
  std::size_t p = g.choix_reproduction(1700,100);
  REQUIRE(p == 1 );
  p = g.choix_reproduction(100,100);
  REQUIRE(p==0);

}

