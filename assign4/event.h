#include <iostream>
#ifndef EVENT_H
#define EVENT_H

using namespace std;
/****************
 * Program: event.h
 * Author: Hannah Maung 
 * Date: 3/1/2020
 * Description: creates Event class
 * Input: none
 * Output: event class
*********/

class Event{

	public:
		virtual void percept() = 0;
		virtual void encounter() = 0;


};
#endif
