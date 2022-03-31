#include <iostream>
#include "player.h"
#include <cstdlib>
#include "player.h"
using namespace std;

Player::Player() {

	
	pit = false;
	wumpus = false;
	arrows = 3;
	gold = false;
	
}
Player::Player(int length) {

	pit = false;
	arrows = 3;
        wumpus= false;
        gold = false;
        x1 = rand() % length;
        y1 = rand() % length;
        x2 = rand() % length;
        y2 = rand() % length;

}


int Player::random_coordinate() {

	
        int coord = rand() % length;
        return coord;
}

void Player::set_x2(int x) {
        this->x2 = x;
}

void Player::set_y2(int y) {
        this->y2 = y;
}

void Player::reset() {

        this->arrows = 3;
        this->wumpus = false;
        this->gold = false;
        this->pit = false;
        this->x2 = x1;
        this->y2 = y1;

}
