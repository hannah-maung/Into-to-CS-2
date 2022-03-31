#pragma once 
#include "classhand.h"


/**************
 * Program: classplayer.h
 * Author: Hannah Maung 
 * Date: 2/2/2020
 * Descriptiom: represents a single player 
*************/
class Player {
private:
	Hand hand;
	std::string name;
public:
	Player();
	void player_name();	
	void draw(int); 
	void inc_cards();
	int get_n_cards();
	Hand get_hand();
};
