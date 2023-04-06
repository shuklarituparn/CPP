#include <iostream>
#include <string>
#include "Player.h"
#include "Other_class.h"


class Player;
void Friend_class::set_hero_name(Player &p, std::string name) {
    p.name = name;
}

void Other_class::display_player(Player &p) {
      std::cout << p.name << std::endl;
      std::cout << p.health << std::endl;
      std::cout << p.xp << std::endl; 
   }



void Friend_class::display_player(Player &p) {
      std::cout << p.name << std::endl;
      std::cout << p.health << std::endl;
      std::cout << p.xp << std::endl; 
}


class Friend_class
{
public:
    void set_hero_name(Player &p, std::string name);
    void display_player(Player &p);
};

void display_player(Player &p) {
      std::cout << p.name << std::endl;
      std::cout << p.health << std::endl;
      std::cout << p.xp << std::endl; 
}

using namespace std;

int main() {
  
    Player hero{"Hero", 100, 35};
    display_player(hero);
    
    Other_class other;
    other.display_player(hero);
    
    Friend_class friend_class;
    friend_class.set_hero_name(hero,"SUPER HERO");
    friend_class.display_player(hero);
    
    return 0;
}

