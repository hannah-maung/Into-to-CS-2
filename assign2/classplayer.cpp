#include <iostream>
#include "classplayer.h"
using namespace std;

/******************
 * Program: classplayer.cpp
 * Author: Hannah Maung 
 * Date 02/02/2020
 * Description: represents a single player, each player will have a Hand object that represents a hand object 
*******************/

/***************
 * Name: player
 * Type: player
 * Description: creates the objects name in the class 
****************/
Player::Player(){

	name = " ";	 
}

/*****************
 * Name: player_name
 * Type: void 
 * Description: asks the player for their name and inputs it into name 
******************/
void Player::player_name() {

	cout << "Enter your name: " << endl;
	getline(cin,name);

	cout << "--------------Welcome " << name << "------------------" << endl;
		
}

/*****************
 * Name: inc_cards
 * Type: void 
 * Description: increases cards, counts them 
*****************/
void Player::inc_cards(){
	this->hand.inc_cards();
}

/****************
 * Name: get_n_cards
 * Type: int 
 * Description: counts the number of cards in players hand 
 * Output: n
******************/
int Player::get_n_cards(){
	int n = hand.get_n_cards();
	cout << "number of cards in players hand: " << n << endl;
	return n;
}

/****************
 * Name: get_hand
 * Type: Hand 
 * Description: returns hand
***************/
Hand Player::get_hand(){
	return this->hand;
}

		


