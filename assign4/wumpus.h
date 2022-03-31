#include <iostream>
#ifndef WUMPUS_H
#define WUMPUS_H
#include "room.h"
#include "event.h"

using namespace std;

/***********************
 * Program: Wumpus.h
 * Author: Hannah Maung 
 * Date: 3/1/2020
 * Description: creates Wumpus class
 * Input: none 
 * Output: Wumpus class
*******************/
class Wumpus : public Event{

	private:


	public: 
		Wumpus();
		void percept();
		void encounter();

};
#endif
