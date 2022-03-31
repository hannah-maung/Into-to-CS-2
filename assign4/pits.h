#ifndef PITS_H
#define PITS_H

#include <iostream>
#include "event.h"

using namespace std;

/*******************
 * Program: pit.h
 * Author: Hannah Maung 
 * Date: 3/1/2020
 * Description: makes Pits class
 * Input: nothing
 * Output: Pits class
*******************/

class Pits : public Event{


	private:


	public:
		Pits();
		void percept();
		void encounter();

};
#endif
