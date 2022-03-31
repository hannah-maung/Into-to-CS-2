#include "cave.h"
#include "bats.h"
#include "pits.h"
#include "gold.h"
#include "event.h"
#include "room.h"
#include "player.h"
#include "wumpus.h"
#include <iostream>
#include <vector>
#include "string.h"
using namespace std;

int main(int argc, char * argv[]) {

	//int go = 0;

	Cave c;
	if (argc != 3) {
		cout << "Invalid number of arguments" << endl;
	
	}

		if (atoi(argv[1]) < 4 || atoi(argv[1]) > 20) {
			cout << "Invalid number for grid size" << endl;
			exit(0);
		}
	
		else if (string(argv[2]) == "true") {
			//c.play_game();
		}
		else if (string(argv[2]) == "false") {
			//normal mode
		}
		else {
			cout << "Wrong, enter a true or false" << endl;
			exit(0);
		}
	
	
	Cave make(atoi(argv[1]));
	make.make_cave();
	make.print_cave();
	c.play_game();

		
}
