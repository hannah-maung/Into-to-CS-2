#include <iostream>
#include "classdeck.h"
#include "classcard.h"
#include "classhand.h"

using namespace std; 

/*******************
 * Program: classdeck.cpp 
 * Name: Hannah Maung 
 * Date: 2/2/2020
 * Description: the source of all the cards, it will be initially start in a deck object and then be transferred to players' hands
********************/

/*****************
 * Name: deck
 * Type: deck
 * Decription: initiates all the objects in the deck class
****************/
Deck::Deck(){

	cards = new Card[52];
	makecards(cards); 	
	n_cards = 52; 

}

/**************
 * Name: Deck
 * Type: deck
 * Description: deletes the cards in the deck
************/
Deck::~Deck(){

	delete [] cards; 


}

/**************
 * Name: Deck 
 * Type: deck
 * Description: initiates all the cards
 * Input: const Deck d
***********/	 
Deck::Deck( const Deck& d) {

	this->n_cards=d.n_cards;
	this->cards = new Card[n_cards];
	for (int i = 0; i < n_cards; i++) {
		this->cards[i] = d.cards[i];

	}
}


/*****************
 * Type: deck
 * Description: assignment operator, assignment value to variable 
 * Input: const Deck& d
****************/
Deck& Deck:: operator=(const Deck& d) {

	delete [] cards; 

	this->n_cards=d.n_cards;
        this->cards = new Card[n_cards];
        for (int i = 0; i < n_cards; i++) {
                this->cards[i] = d.cards[i];

	}
	
	return *this;
}
/*********** 
 * Name: getrank() 
 * Type: int 
 * Description: returns the rank of the card, accessor function 
 * Input: int i
*************/
int Deck::getrank(int i){
	return cards[i].getrank();
}

/************
 * Name: getsuit()
 * Type: int 
 * Description: returns the suit of the card, accessor function 
 * Input: int i 
**************/
int Deck::getsuit(int i){
	return cards[i].getsuit();
}
/***************
 * Name: get_n_cards() 
 * Type: int 
 * Description: gets the amount of cards, accessor function 
****************/
int Deck::get_n_cards(){
	return this->n_cards;
}

/*****************
 * Name: makecards
 * Type: void 
 * Description: creates an array of the card deck 
*/
void Deck::makecards(Card * cards){

        int place = 0;
        for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 13; j++) {
                        cards[place].setrank(j);
			cards[place].setsuit(i);
			place++;
                }
        }

}


/*****************
 * Name: showdeck()
 * Type: void 
 * Description: prints out the deck of cards 
******************/
void Deck::showdeck(){

	for(int i = 0; i < this->n_cards;i++){

		if (cards[i].getrank() == 0) {
			cout << "ACE OF ";
		}
		else if (cards[i].getrank() == 10) {
			cout << "JACK OF ";
		}
		else if (cards[i].getrank() == 11) {
			cout << "QUEEN OF ";
		}
		else if (cards[i].getrank() == 12) {
			cout << "KING OF ";
		}	
		else { 
			cout << cards[i].getrank()+1 << " OF ";
		}	


  		if (cards[i].getsuit() == 0) {
                        cout << "CLUBS" << endl;
                }
                else if (cards[i].getsuit() == 1) {
                        cout << "SPADES" << endl;
                }
                else if (cards[i].getsuit() == 2) {
                        cout << "HEARTS" << endl;
                }
                else if (cards[i].getsuit() == 3) {
                        cout << "DIAMONDS" << endl;
                }
	}	
}

/********************
 * Name: shuffle()
 * Type: void 
 * Description: shuffles the deck of cards using rand()
 ***************/
void Deck::shuffle() {

	int random;
	srand(time(0));
	
	for (int i = 0; i < (52-1); i++) {
		random = i + (rand() % (52-i));
		Card a = cards[i]; 
		cards[i] = cards[random];
		cards[random] = a;								
	}
	
}

/********************
 * Name: deal_hand() 
 * Type: void 
 * Input: Hand h 
 * Description: deals the cards to each hand 
*/
void Deck::deal_hand(Hand h) {

	
	for (int i = 0; i < 7; i++) {
		
		h.get_cards()[i] = cards[52-n_cards];
		n_cards--;

		cout << "card put into hand: " << h.get_cards()[i].getrank() << " " << h.get_cards()[i].getsuit() << endl;
	}
 
	cout << "Amount of cards left in the deck: " << n_cards << endl;
}

/*******************
 * Name: deal_card
 * Type: void 
 * Input: hand h, int n 
 * Description: deals the card to each hand individually 
*******************/
void Deck::deal_card(Hand h, int n) {
	cout << n_cards << endl;
	h.draw(cards[52-n_cards]);
	n_cards--;
}


Card Deck:: drawc() {

	Card tempc = cards[n_cards-1];
	n_cards--;
	return tempc;

}

