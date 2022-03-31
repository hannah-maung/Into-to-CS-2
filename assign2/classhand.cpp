#include <iostream>
#include "classhand.h"
#include "classcard.h"

using namespace std; 


Hand::Hand() {

	n_cards = 7;
	cards = new Card[52];
}

Hand::~Hand() {

	//cout << "destructor" << endl;
	delete [] cards;

}

Hand::Hand( const Hand& e){


	//cout << "copy construct " << endl;
	this->n_cards=e.n_cards;
	this->cards = new Card[n_cards];
	for(int i = 0; i < n_cards; i++) {
		this->cards[i] = e.cards[i];
	}

}


Hand& Hand:: operator=(const Hand& e){

	//cout << "assignment operator overload" << endl;
	delete [] cards;
	
	this->n_cards=e.n_cards;
        this->cards = new Card[n_cards];
        for(int i = 0; i < n_cards; i++) {
                this->cards[i] = e.cards[i];
        }
	return *this;

}

Card * Hand::get_cards(){
	return cards;
}	

void Hand::show_hand(){
	cout << "number of cards in players hand: " << n_cards << endl;
	for(int i = 0; i < n_cards;i++){
		cout << cards[i].getrank() << " " << cards[i].getsuit() << endl;
	}
}	

int Hand::get_n_cards(){
	return this->n_cards;
}

void Hand::inc_cards(){
	this->n_cards++;
}

void Hand::draw(Card c){	
	cout << "drawing card: " << c.getrank() << endl;
	n_cards++;
	cards[n_cards] = c;
	cout << "card: " << cards[n_cards].getrank() << endl;
}
