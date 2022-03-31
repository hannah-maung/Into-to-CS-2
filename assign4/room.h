#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include "event.h" 
#include "player.h"

using namespace std;

/*******************
 * Program: room.h
 * Author: Hannah Maung 
 * Date: 3/1/2020
 * Description: creates Room class and all the variables 
 * Input: none
 * Output: Room class
*******************/
class Room{
	public:
		Room();
		Room(int length);
		void make_marker();
		string get_marker();
		bool get_rope();
		bool get_event();
		void set_rope(bool);
		void set_event(bool);
		void percept();
	private:
		string event_marker;
		Event * arr;
		bool event;
		bool rope;
};
#endif
