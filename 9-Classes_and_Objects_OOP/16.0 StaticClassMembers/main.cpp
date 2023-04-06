// Section 13
// Static class members
#include <iostream>
#include "Player.h"

using namespace std;

void display_active_players() {
    cout << "Active players: " << Player::get_num_players() << endl;   //displaying active players
}

int main() {
    display_active_players(); //currently 0. asking player class for active players
    Player hero{"Hero"};  //creating a player called hero
    display_active_players();   //currently active_player=1
    
    {
        Player frank{"Frank"};
        display_active_players();//displaying active player=2
    }
    display_active_players(); //active player =1 as the local block of frank gets out of scope
    
    Player *enemy = new Player("Enemy", 100, 100); //creating an object enemy on heap
    display_active_players();
    delete enemy;
    display_active_players();    



    return 0;
}

