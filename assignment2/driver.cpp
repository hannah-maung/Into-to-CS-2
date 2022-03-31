#include <iostream>
#include <string>
#include "classcard.h"
#include "classdeck.h"
#include "classhand.h"
#include "classgame.h"
#include "classplayer.h"

using namespace std;

/**********************
 * Name: driver.cpp
 * Author: Hannah Maung 
 * Date: 2/2/2020
 * Description: calls functions, runs the whole game 
 * Function name: main 
 * Type: int
**********************/

int main() {

	Hand h;
	Game g;
	g.setup();	
	Player p;
	p.player_name();	
	Deck d;
	cout << "PRINT DECK: " << endl;
	//d.showdeck();
	d.shuffle(); 
	d.showdeck(); 
	//d.deal_deck();
	
	g.run_game();
	g.show_cards();
	//d.deal_card( h, n);
	//d.deal_card();
	Hand p1;
	Hand p2 = p1;
	Hand p3;
	p3 = p1;
	return 0; 

}


