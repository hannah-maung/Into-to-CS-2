#ifndef BATS_H
#define BATS_H
#include <iostream> 
#include "event.h"


/**********
 * Program: bats.h
 * Author: Hannah Maung 
 * Date: 3/1/2020
 * Description: creates Bats class
 * Input: none
 * Output: bats class
 ********/

using namespace std;

class Bats: public Event {


	private:

	public:
		Bats();
		void percept();
		void encounter();
};
#endif
