#pragma once 
#include "classdeck.h"
#include "classplayer.h"



/*****************
 * Program: classgame.h
 * Author: Hannah Maung
 * Date: 2/2/2020
 * Description: represents the state of an entire game, it contrains objects representing the deck of cards and both players
****************/

class Game {
  private:
    Deck cards;
    Player *players;
  public:

	Game();
	void setup();	
	void draw(int); 
	void run_game();
	void show_cards();
	void showtop_card();
 // must have constructors, destructor, accessor methods, and mutator methods
};
