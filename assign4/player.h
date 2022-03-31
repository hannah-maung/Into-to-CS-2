#ifndef PLAYER_H
#define PLAYER_H

#include "event.h"
#include <iostream>


using namespace std;

class Player{


	public:
		Player();
		Player(int length);
		int x1, x2, y1, y2;
		int arrows;
		bool gold;
		bool wumpus;
		bool pit;
		int length;
		void set_x2(int);
		void set_y2(int);
		void reset();
		int random_coordinate();

};
#endif
