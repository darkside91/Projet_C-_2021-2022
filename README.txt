################################################################################### LAST EARTH #######################################################################################

Last Earth est un jeu de gestion qui se joue par tour. Le joueur incarne un groupe de villageois qui se reproduit, récolte et consomme des ressources.
Le projet a été réalisé à l'aide de SFML en C++. 

####### SOMMAIRE #######
I - Installation
II - Règles du jeu
III - Tests 
IV - Crédits
########################

######################################################################################################################################################################################
I - Installation

Le jeu est fait pour ne s'exécuter que sur un environnement Linux car il utilise des appels systèmes POSIX. Il n'est pas compatible Windows ou MacOS. 
Il a été développé sous Ubuntu 18.04.6 LTS. 

Sur votre environnement Linux, il faut installer les packages SFML permettant de compiler correctement le projet. 
Entrez la ligne suivante sur le terminal pour permettre l'installation : 

sudo apt-get install libsfml-dev

Cela devrait fonctionner sur la plupart des systèmes Debian. Au cas où l'installation ne se ferait pas correctement, il est possible de télécharger 
manuellement les paquets puis de les décompresser à l'endroit souhaité pour pouvoir ensuite les compiler en spécifiant le chemin des librairies. 
Il faut de préférence les copier dans le chemin standard "/usr/local" pour pouvoir utiliser le Makefile fourni. 

Voici le lien de téléchargement :
https://www.sfml-dev.org/download-fr.php

Une fois l'installation terminée, il faut télécharger le dossier du jeu et le décompresser. Un Makefile est fourni permettant de compiler le jeu
avec l'instruction "make". Le Makefile permet de compiler les testcases avec l'instruction "make testcases". 
Il suffit de lancer le jeu par "./Last_Earth". Pour lancer les testcases, il faut entrer "./testcases".

######################################################################################################################################################################################
II - Règles du jeu

Last Earth se joue par tour. La version du jeu à ce jour, permet de jouer un maximum de 8 tours avant la fin du jeu. 
Pour modifier le nombre de tours, il suffit de modifier la variable tours, argument du constructeur Game() dans le
fichier main.cpp.

Le joueur contrôle un groupe de villageois (initialement composé d’un homme et d’une femme). Ce groupe est dépendant
de 5 types de ressources : viande, légume, eau, bois et pierre. 

A chaque tour joué, la carte s'agrandit un peu plus.

Un tour est constitué de plusieurs étapes :

    1 - Le joueur choisit une direction où se diriger via les touches Z,E,D,X,W,Q.
    
        Z E
      Q     D 
        W X
        
    2 - Le joueur récolte les ressources présentes sur la case (ce n’est possible qu’une seule fois, les ressources s’épuisent).
        Ceci est réalisé automatiquement après le choix du mouvement.
        
    3 - Le joueur nourrit ses villageois (chaque type ayant ses spécificités, que nous discuterons plus bas). Pour réaliser cette
        action il faut appuyer sur le bouton bleu à l'icône d'une goutte d'eau.
        
    4 - Le joueur choisit de reproduire ses villageois ou non (bouton bleu ou bouton rouge). Il faut appuyer sur un personnage
        puis l'autre à tour de rôle. Les personnages sont dans la zone Villageois. On ne peut reproduire que des personnages dont le 
        nombre est égal ou supérieur à 1. Par exemple appuyer sur l'image de la femme puis de l'homme. 
        Après deux secondes, on voit qu’un nouvel individu s’est ajouté si la reproduction a fonctionné, si un paramètre n’est pas bon,
        un message apparaîtra dans le terminal et le jeu continuera. 
        
    5 - Les villageois qui n’ont pas été nourris ou qui ont atteint la fin de leur vie meurent et le prochain tour commence.
    
Chaque type de personnage a un comportement différent de reproduction et de consommation des ressources : 

      * Les humains ne consomment que des ressources alimentaires. Leur reproduction peut donner les 5 types avec une probabilité
        de 57% de donner un autre humain (femme ou homme).
       
      * Les mutants_pm peuvent consommer n’importe quelle ressource, de préférence les ressources alimentaires, ce qui les met en
        concurrence avec les humains. Ils peuvent se contenter de bois ou de pierre (comme des termites du futur).
        
      * Les mutantsF_minus consomment n’importe quelle ressource tout comme les mutants_pm, mais prennent deux ressources à la 
        place d’une. 
        
      * Les mutantsF_plus ne consomment pas de ressources et ne peuvent mourir que de vieillesse. 

Chaque type de personnage a une espérance de vie différente, qui varie de 5 tours pour un humain et un mutant_pm, à 2 tours pour un
mutant_minus. Elle est de 4 tours pour un mutant_plus. 

Le jeu est gagné si à la fin du nombre de tours, il reste au moins un personnage en vie. Le jeu est perdu si tout le monde meurt.

Le jeu peut être mis sur pause et les règles du jeu peuvent être lues sur l’écran de pause accessible par la touche échap. Le jeu 
est réintégré en appuyant sur le bouton en forme de planète Terre.

Certaines informations peuvent être lues de manière plus explicite sur le terminal, par exemple la mort d'un personnage, ou 
l'augmentation d'une ressource. 

######################################################################################################################################################################################
III - Tests

Le but de ces tests unitaires est de couvrir un maximum des fonctions du code. Le testcase est composé de 9 tests différents soit 19 asserts. 
Les tests permettent de vérifier le bon déroulement des fonctions de la classe Personnage, de la classe Cases et bien sûr de la classe Game.
Ces tests ont été volontairement réalisés sur les fonctions au fonctionnement le plus critique pour le jeu. 
     
     * Test 1 : vérifie la bonne initialisation du jeu lors de sa création
     * Test 2 : vérifie si la fonction rand_ressources() de la classe Game retourne bien un objet de type Ressources à l'aide d'un objet type_info
     * Test 3 : vérifie que la fonction return_perso(std::size t) de la classe Game retourne bien le Personnage du type choisi, à l'aide cette fois 
                aussi d'un objet type_info
     * Test 4 : vérifie le bon déroulement de la fonction reproduction(Personnage& p) des classes filles de la classe Personnage. Vérifie que la
                fonction retourne bien un objet Personnage à l'aide d'un objet typer_info
     * Test 5 : vérifie la bonne initialisation des classes filles de la classe Personnage mais aussi la perte de vie
     * Test 6 : vérifie le bon déroulement des fonctions de remplissage et d'effacement de la classe Case ainsi que la surcharge d'opérateur <<
     * Test 7 : vérifie que la surcharge d'opérateur des vecteurs de Personnage renvoie la bonne std::string
     * Test 8 : vérifie que la fonction push_list(std::size_ i) de la classe Game ajoute bien un Personnage au bon vecteur
     * Test 9 : vérifie que la fonction choix_reproduction(std::size_t x, std::size_t y) renvoie la bonne valeur lorsqu'on entre de différentes coordonnées
                

######################################################################################################################################################################################
IV - Crédits
  
  Le projet a été réalisé à l'aide de la documentation SFML : https://www.sfml-dev.org/learn-fr.php
  Je recommande aussi l'utilisation de la documentation C++ de cplusplus.com  : https://www.cplusplus.com/
  
  Ce jeu a été réalisé dans le cadre d'un projet de C++ sur le thème "There is no Planet B" par Maï Ghalioun (spécialité Electronique/Informatique Systèmes embarqués - EISE 4).
  Il a été réalisé sous une environnement Linux/Ubuntu et utilise des appels systèmes POSIX, ce qui nécessite qu'il soit compilé et exécuté sur un environnement Linux.
  
