
#include <vector>
#include "room.h"
#include "wumpus.h"
#include "pits.h"
#include "bats.h"
#include "gold.h"
#include "player.h"
#include "cave.h"


using namespace std;


/***************
 * Program: cave.cpp
 * Author: Hannah Maung 
 * Date: 3/1/2020
 * Description: creates all the Cave class related functions
 * Input: nothing 
 * Output: Cave class functions 
***************/

//Constructor
Cave::Cave() {

	length = 0;
	
}

//Alternate constructor 
Cave::Cave(int length) {
	
	this->length = length;
	play = new Player(length);	
 
}	

/**********************
 * Name: check_num
 * Type: int 
 * Description: checks if string input is a number or not
 * Input: string num
 * Output: return 1, 0
******************/
int Cave::check_num(string num) {
        int count = 0;

        for (int i = 0; i < num.length(); i++) {

                if (!((char(num.at(i)) >= '0') && (char(num.at(i)) <= '9'))) {
                        count = 1;
                }
        }

        if (count == 1) {
                return 1;
        }
        else {
                return 0;
        }
}


/********************
 * Name: print_instructions  
 * Type: void
 * Description: prints out instructions for user
 * Input: nothing
 * Output: print statements
********************/
void Cave::print_instructions() {


	cout << "----Welcome to Hunt the Wumpus----" << endl;
	cout << "Name: ";
	string input;
	getline(cin,input);


}



/********************
 * Name: option 
 * Type: void
 * Description: asks user if they want to move the player or shoot an arrow
 * Input: nothing
 * Output: moves player, shoots arrow
********************/
void Cave::option() {

	int count = 0;
	string input;
	int check = 0;

	cout << "---OPTIONS---" << endl;
	cout << "Move player (1), Shoot arrow (2): ";
	getline(cin,input);
	
	while(!(count)) {
		if (check_num(input)) {
			cout << "Invalid, enter a 1 or 2: ";
			getline(cin,input);
		}
			else{
				check = atoi(input.c_str());
				if (check > 0 && check < 3) {
					count = 1;
				}		
			
		else {
			cout << "Invalid, enter a 1 or 2: ";
			getline(cin,input);
		}
	
	}
	}

	if(atoi(input.c_str()) == 1) {	
		player_move();
	}
	if (atoi(input.c_str()) == 2) {
		shoot_arrow();
	}

}


/********************
 * Name: print_cave
 * Type: void
 * Description: creates cave grid usin vector
 * Input: nothing
 * Output: grid of the cave
********************/
void Cave::make_cave(){

	cave = vector< vector<Room>> ( length, vector<Room>(length));

        for (int i = 0; i < length; i++) {
                for (int j = 0; j < length; j++) {
                        Room x;
                        cave[i][j] = x;
                }
        }
}

void Cave::print_cave() {

	make_cave();
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			cout << "|" << cave[i][j].get_event()  <<  "|";
		}
		cout << endl;
	
	}	
}




/********************
 * Name: play_game
 * Type: void
 * Description: calls functions to play the actual game
 * Input: nothing
 * Output: function call
********************/
void Cave::play_game() {

		
	print_instructions();
	make_cave();
	print_cave();
	option();
	print_cave();			
	player_move();
		
	
}



/********************
 * Name: check_down 
 * Type: int
 * Description: checks down of the grid
 * Input: int 
 * Output: return value
********************/
int Cave::check_down(int y) {

	if (length > (y+1)) {
		return 1;
	}
	return 0;
}



/********************
 * Name: check_downpercept
 * Type: void
 * Description: checks if there is an event wherever the user is, prints out percept hint 
 * Input: nothing
 * Output: hint
********************/
void Cave::check_downpercept() {
	
	if (check_down(this->play->x2)) {
		if (cave[this->play->x2+1][this->play->y2].get_event()){
			cave[this->play->x2+1][this->play->y2].percept();
		}
	}
}


/********************
 * Name: check_up
 * Type: int
 * Description: checks up of the grid
 * Input: int y
 * Output: return value
********************/
int Cave::check_up(int y){

	if (y-1 >=0) {
		return 1;
	}

	return 0;
}


/********************
 * Name: check_uppercept
 * Type: void 
 * Description: checks if there is an event whever the player is, prints out the percept hint 
 * Input: nothing
 * Output: hint
********************/
void Cave::check_uppercept() {

	if (check_up(this->play->x2)) {
		if (cave[this->play->x2-1][this->play->y2].get_event()){	
			cave[this->play->x2-1][this->play->y2].percept();
		}
	}	

}


/********************
 * Name: check_left
 * Type: int
 * Description: checks left of the grid
 * Input: int x
 * Output: return value
********************/
int Cave::check_left(int x) {

	if (x-1 >= 0) {
		return 1;
	}
	return 0;
}


/********************
 * Name: check_leftpercept
 * Type: void
 * Description: checks if there is an event wherever the player is, prints out the precept hint
 * Input: nothing
 * Output: hint
********************/
void Cave::check_leftpercept() {

	if(check_left(this->play->y2)){
		if (cave[this->play->x2][this->play->y2-1].get_event()) {
			cave[this->play->x2][this->play->y2-1].percept();

		}
	}
}


/********************
 * Name: check_rightpercept
 * Type: void 
 * Description: checks if there is an event whever the player is, prints out the percept hint 
 * Input: nothing
 * Output: hint
********************/
void Cave::check_rightpercept() {

	if (check_right(this->play->y2)) {
		if (cave[this->play->x2][this->play->y2+1].get_event()) {
			cave[this->play->x2][this->play->y2+1].percept();
		}
	}

}



/********************
 * Name: check_right
 * Type: int
 * Description: checks right of the grid
 * Input: int x
 * Output: return value 
********************/
int Cave::check_right(int x) {

	if (x+1 <= length) {
		return 1;

	}
	return 0;
}

/********************
 * Name: player_move
 * Type: void
 * Description: asks what direction the user wants to move in, calls that function and moves the player 
 * Input: nothing
 * Output: moves player, changes x and y coordinates
********************/
void Cave::player_move() {

	//check_event();
	/*
	check_leftpercept();
	check_rightpercept();
	check_uppercept();
	check_downpercept();*/
	string direction;
	cout << "What direction would you like to move in (w,a,s,d): ";
	getline(cin,direction);

	if (direction == "w") {
		move_up();
	}

	if (direction == "d") {
		move_right();
	}

	if (direction == "a") {
		move_left();

	}

	if(direction == "s") {
		move_down();
	}
}



/********************
 * Name: move_up
 * Type: void
 * Description: moves the player up when this function is called 
 * Input: nothing
 * Output: print out statement, moves y coordinate up
********************/
void Cave::move_up(){ 

	if(check_up(this->play->x2)){
		cout << "here" << endl;
		this->play->x2 = this->play->x2-1;
	}
}


/********************
 * Name: move_down
 * Type: void
 * Description: moves the player down when this function is called
 * Input: nothing
 * Output: print out statement, moves y coordinate down
********************/
void Cave::move_down() {
	
	cout << "player moving down" << endl;
	if (check_down(this->play->x2)) {
		this->play->x2 = this->play->x2+1;
	}

}


/********************
 * Name: move_right
 * Type: void
 * Description: moves the player right when this function is called
 * Input: nothing
 * Output: prints out statement, moves x coordinate right
********************/
void Cave::move_right() {

	cout << "player moving right" << endl;
	if (check_right(this->play->y2)) {
		this->play->y2 = this->play->y2+1;

	}
}

/********************
 * Name: move_left
 * Type: void
 * Description: moves the player left when this function is called
 * Input: nothing
 * Output: prints out statement, moves x coordinate left 
********************/
void Cave::move_left() {

	cout << "player moving left" << endl;
	if (check_left(this->play->y2)){
		this->play->y2 = this->play->y2-1;
	}

}



/********************
 * Name: shoot_arrow
 * Type: void
 * Description: asks the user what direction they want their arrow to be shot in, checks if there is a marker at that spot
 * Input: nothing
 * Output: function calls 
********************/
void Cave::shoot_arrow() {

	string direction;
	cout << "What direction would you like to shoot the arrow in (w,a,s,d): ";
	getline(cin, direction);

	if (direction == "w") {
		  for(int i = this->play->x2-1; i >= 0; i--) {
                	if (cave[this->play->x2-1][this->play->y2].get_marker() == "W"){
				kill_wumpus();
			}
		}
	}

	if (direction == "a") {
		for (int i = this->play->y2-1; i >= 0;i--) {
               		if (cave[this->play->x2][this->play->y2-1].get_marker() == "W") {
				kill_wumpus();
			}
 		}
	}

	if (direction == "s") {
		for (int i = this->play->x2+1; i < length ; i++) {
                	if (cave[this->play->x2+1][this->play->y2].get_marker() == "W"){
				kill_wumpus();
			}
		}
	}

	if (direction == "d") {
		for (int i = this->play->y2+1; i < length; i++) {
       	        	if (cave[this->play->x2][this->play->y2+1].get_marker() == "W"){
				kill_wumpus();
			}

		}
	}

	this->play->arrows--;
}




/********************
 * Name: no_arrows
 * Type: void
 * Description: keeps track of how many arrows there are in the game 
 * Input: nothing
 * Output: print out statement if there are no arrows left 
********************/
void Cave::no_arrows(){

	if (this->play->arrows == 0) {
		cout << "No more arrows left" << endl;		
	}

}

/********************
 * Name: kill_wumpus
 * Type: void
 * Description: checks if that grid spit has a W, if there is a W then the wumpus gets killed (= true)
 * Input: nothing
 * Output: wumpus = true, print out statement 
********************/
void Cave::kill_wumpus() {

	Room r;

	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			if (cave[i][j].get_marker() == " W ") {
				cave[i][j] = r;
			}
		}
	}
	cout << "The wumpus has been killed!" << endl;
	this->play->wumpus = true;	
}


/********************
 * Name: bats_move
 * Type: void
 * Description: creates a random coordinate for where the super bats get located when they pick up the user
 * Input: nothing
 * Output: bat moves to random location 
********************/
void Cave::bats_move() {

	srand(time(NULL));

	int b1 = rand() % length;
	int b2 = rand() % length;

	this->play->x2 = b1;
	this->play->y2 = b2;


}



/********************
 * Name: start_pos
 * Type: void
 * Description: sets where the player starts, where the rope is at well
 * Input: nothing
 * Output: start coordinate 
********************/
void Cave::start_pos() {

	cave[this->play->x1][this->play->y1].set_rope("*");
	
}


/********************
 * Name: check_empty 
 * Type: int
 * Description: checks if that grid spot is empty
 * Input: nothing
 * Output: return value
********************/
int Cave::check_empty() {
	
	int count;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			//if (cave[random_coordinate()][random_coordinate()] == ' ');
			count = 1;
		}
	}

	if (count == 1) {
		return 1;
	}
	else{
		return 0;
	}

}


/********************
 * Name: fill_room
 * Type: void
 * Description: sets event 
 * Input: nothing
 * Output: sets up event marker
********************/
void Cave::fill_room() {


	int x = 0;
	int y = 0;
	x = rand() % length;
	y = rand() % length;

	for (int i = 0; i < 7; i++) {
		cave[x][y].get_event();
	}

	cave[this->play->x1][this->play->y1].set_rope("R");
	cave[x][y].set_event("G");
	cave[x][y].set_event("P");
	cave[x][y].set_event("P");
	cave[x][y].set_event("W");
	cave[x][y].set_event("B");
	cave[x][y].set_event("B");
}


/********************
 * Name: check_event
 * Type: void
 * Description: checks the event in that specific player coordinate 
 * Input: nothing
 * Output: print out statement
********************/
void Cave::check_event() {

	Room r;
	if (cave[this->play->x2][this->play->y2].get_marker() == "W") {
		cout << "The wumpus is in the room" << endl;
	}

	if (cave[this->play->x2][this->play->y2].get_marker() == "P") {
		cout << "You fell into the pit" << endl;
	}

	if (cave[this->play->x2][this->play->y2].get_marker() == "B") {

		cout << "You got captured by a bat and they are relocating you" << endl;
	}
	if (cave[this->play->x2][this->play->y2].get_marker() == "G") {
		cout << "You got the gold!" << endl;
		this->play->gold = true;
		cave[this->play->x2][this->play->y2] = r;			
	}
}



/********************
 * Name: repeat_game
 * Type: void
 * Description: asks the user if they want to play the game after they win/die
 * Input: int &again
 * Output: plays game again or quits
********************/
void Cave::repeat_game(int &again) {

	cout << "Would you like to play again? (1-yes) (2-no): " << endl;
	cin >> again;

	if (again == 1) {
		play_game();
	}	
	else { 
		cout << "Thanks for playing" << endl;
		exit(0);
	}
}


/********************
 * Name: win
 * Type: int
 * Description: checks if the player wins the game by checking if they got the gold, killed the wumpus, and are at the rope location
 * Input: nothing
 * Output: wins game
********************/
int Cave::win() {

	int count = 0;

	if (this->play->gold == true) {
		count++;
	}	
	if (this->play->wumpus == true) {
		count++;
	}
	if(cave[this->play->x2][this->play->y2].get_rope()) {
		count++;
	}


	if (count == 3) {
		cout << "---YOU WON THE GAME---" << endl;
		return 1;
	}
	else {
		return 0;
	}
	
}



