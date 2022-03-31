#ifndef CLASSDECK_H
#define CLASSDECK_H
#include "classhand.h"
#include "classcard.h"


/********************
 * Program: classhand.cpp 
 * Author: Hannah Maung 
 * Date: 2/2/2020
 * Description: hand class that holds the cards in one player's hand 
********************/

class Deck {
  private:
    Card * cards;
    int n_cards;  // Number of cards remaining in the deck.
  public:
 	Deck();
	~Deck();	
	Deck(const Deck&);
	Deck& operator = (const Deck&);
	void makecards(Card * cards);
	void showdeck(); 	
	void shuffle();
	void deal_hand(Hand);
	void deal_card(Hand , int); 
	int get_n_cards(); 
	int getrank(int);
	int getsuit(int);
};
#endif
