#include <iostream>
#include <string>
#include "classgame.h"
#include "classplayer.h"
#include "classdeck.h"
 
using namespace std; 

/****************
 * Program: classgame.cpp
 * Author: Hannah Maung 
 * Date: 2/2/2020
 * Description: represents the state of an entire game
*****************/

/**************
 * Name: Game
 * Type: game
 * Description: intiates objects
***********/
Game::Game(){

	Deck cards;
	players = new Player[2];


}

/**************
 * Name: setup
 * Type: game
 * Description: prints out a welcoming 
************/
void Game::setup() {

	cout << "------------------WELCOME TO CRAZY EIGHTS-------------------" << endl;
	
	
}
/**************
 * Name: draw
 * Type: game
 * Description: draws a card in the deck
 * Input: int n 
************/
void Game::draw(int n){
	
	//this->players->get_hand()[ this->players->get_n_cards() ] = cards->deal_card();
	cout << "-----number of cards in the deck " << cards.get_n_cards() << endl;
	cards.deal_card(players[n].get_hand(), players[n].get_n_cards());

}	

/**************
 * Name: run_game
 * Type: Game
 * Description: runs the game and assigns the cards to a player's hand
**************/
void Game::run_game(){
	cards.shuffle();
	

	cards.deal_hand(players[0].get_hand());
	cards.deal_hand(players[1].get_hand());
	cout << "first card in player 1's hand " << players[1].get_hand().get_cards()[0].getsuit() << endl;
	


	cout << "player 1's hand " << endl;
	players[1].get_hand().show_hand();
	
	draw(1);
	cout << endl << "player 1's hand after draw" << endl;
	players[1].get_hand().show_hand();
	cout << endl;
}

/****************
 * Name: show_cards
 * Type: game 
 * Description: prints out cards 
****************/
void Game::show_cards(){

//	for(int i = 0 ; i < cards.get_n_cards(); i++){
//		cout << cards.getrank(i) << " " << cards.getsuit(i) << endl;
//	}

}







