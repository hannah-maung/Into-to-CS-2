#include <iostream>
#include "room.h"
#include "gold.h"
#include "pits.h"
#include "bats.h"
#include "wumpus.h"
 
using namespace std;



/**********************
 * Program: room.cpp
 * Author: Hannah Maung 
 * Date: 3/1/2020
 * Description: creates all the Room functions 
 * Input: none
 * Output: Room functions
*******************/
//Room constructor 
Room::Room() {

	event = false;
	event_marker = "  ";
	arr = nullptr;
}
//Room alternate construtor 
Room::Room(int length) {

	make_marker();
}	

/******************
 * Name: make_marker
 * Type: void 
 * Description: creates the markers for all the events 
 * Input: none
 * Output: markers
****************/
void Room::make_marker() {

	int input = 0;

	for (int i = 0; i < input; i++) {
		if (input == 1) {
			arr = new Pits; 
			event_marker = " P ";
			break;		
		}	

		else if (input == 2) {
			arr = new Wumpus;
			event_marker = " W ";
			break;
		}

		else if (input == 3) {
			arr = new Gold;
			event_marker = " G ";
			break;
		}

		else {
			arr = new Bats;
			event_marker = " B ";
			break;
		}

	}

	event = true;

}

//get function, returns event_marker 
string Room::get_marker() {
	return this-> event_marker;
}

//get function, returns rope status
bool Room::get_rope() {

	return this-> rope;
}
//set function, assigns rope to bool r
void Room::set_rope(bool r) {

	this->rope = r;

}

//get function, returns event status
bool Room::get_event() {

	return this-> event;
}

//set function, assigns event to bool e
void Room::set_event( bool e) {

	this->event = e;
}

//accesses percept functions 
void Room::percept() {

	this->arr->percept();
}
