#include <iostream>
#include <string> 
#include "classcard.h"
#include "classdeck.h"
using namespace std; 

/***************
 * Program: classcard.cpp
 * Author: Hannah maung 
 * Date: 2/2/2020
 * Description: initiates the cards' rank and suit values as integers
****************/

/*************
 * Function: Card
 * Type: card
 * Description: initiates the objects in the class
************/
Card::Card(){
	rank = 0;
	suit = 0;
}

/************
 * Function: Card
 * Type: card
 * Input: int r, int s
 * Description: assigns the objects to variables
*************/
Card::Card(int r, int s){
	
	rank = r;
	suit = s; 
}


/**********
 * Function: getrank
 * Type: int
 * Description: returns rank number
***********/
int Card::getrank(){
	return rank; 

}


/************
 * Function: setrank
 * Type: void 
 * Description: accesses a member variable of an object through a pointer
************/
void Card::setrank(int r) {
	this->rank = r; 
	
}

/**********
 * Function: getsuit
 * Type: int
 * Description: returns suit number
***********/
int Card::getsuit() {
	return suit;

}
/**************
 * Function: setsuit
 * Type: void 
 * Input: int s
 * Description: accesses a member variable of an object through a pointer
**********/
void Card::setsuit(int s){

	this->suit = s;
	
}




