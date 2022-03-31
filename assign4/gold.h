#include <iostream>
#include "event.h"
#ifndef GOLD_H
#define GOLD_H
using namespace std;


/********************
 * Program: gold.h
 * Author: Hannah Maung 
 * Date: 3/1/2020
 * Description: creates Gold class
 * Input: nothing
 * Output: Gold class
******************/

class Gold : public Event{

	private:
		

	public:
		Gold();
		void percept();
		void encounter();

};
#endif
