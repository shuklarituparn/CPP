#include "Player.h"

int Player::num_players {0}; //Initializing the static variable here. Happens only in .cpp file

Player::Player(std::string name_val, int health_val, int xp_val) 
    : name{name_val}, health{health_val}, xp{xp_val} {
        ++num_players;        //Incrementing number of players in Constructor
}

Player::Player(const Player &source)
       : Player {source.name, source.health, source.xp}  {
}

Player::~Player() {
    --num_players;
}

int Player::get_num_players() {  //returning the number of players active at a moment "static"
    return num_players;
}


