#include <iostream>
#include <vector>
#include "room.h"
#include "event.h"
#ifndef CAVE_H
#define CAVE_H
using namespace std;

#include "room.h"
#include "player.h"


/*******************
 * Program: cave.h
 * Author: Hannah Maung 
 * Date: 3/1/2020
 * Description: makes Cave class
 * Input: nothing
 * Output: cave class
******************/

class Cave{


	private:
		int length;
		vector< vector< Room> > cave;
		Player *play;
	public:
	
		Cave();
		Cave(int);
		void make_cave();
		void print_cave();
		int check_num(string);
		void option();
		void print_instructions();
		void play_game();
		int check_left(int);
		void check_leftpercept();
		int check_right(int);
		void check_rightpercept();
		int check_down(int);
		void check_downpercept();
		int check_up(int);
		void check_uppercept();
		void shoot_arrow();
		void kill_wumpus();
		void player_move();
		void no_arrows();
		void move_right();
		void move_left();
		void move_down();
		void move_up();
		void bats_move();
		int check_empty();
		void fill_room();
		void check_room();
		int random_coordinate();
		void start_pos();
		void check_event();
		int win();
		void repeat_game(int &again);
};	
#endif
