#pragma once 
#include "classcard.h"


/**************
 * Program: classhand.h
 * Author: Hannah Maung 
 * Date: 02/02/2020
 * Description: holds the cards in one player's hands
************/
class Hand {
  private:
	Card* cards;
	int n_cards;  
  public:

	Hand();	
	~Hand(); 
	Hand(const Hand&);
	Hand& operator = (const Hand&); 
	void inc_cards();
	int get_n_cards();
	void draw(Card);
	void show_hand();
	Card * get_cards();
};

