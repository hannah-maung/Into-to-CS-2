#pragma once 

/****************
 * Program: classcard.h
 * Author: Hannah Maung 
 * Date: 2/2/2020
 * Description: rank and suit are represented with int values 
******************/

class Card {
  private:
    int rank;  // Should be in the range 0-12.
    int suit;  // Should be in the range 0-3.
  public:
  // must have constructors, destructor, accessor methods, and mutator methods
 	Card();
//	~Card(); 
	//Card(const Card&);
	//Card& operator = (const Card&);
	Card(int r, int s);
	int getrank();
	void setrank(int r);
	int getsuit();
	void  setsuit(int s);
	int makeranksuit();
};
