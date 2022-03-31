#include <iostream>
#include "wumpus.h"

using namespace std;



/*****************
 * Program: wumpus.h
 * Author: Hannah Maung 
 * Date: 3/1/2020
 * Description: 
 * Input: none
 * Output: Wumpus functions
*****************/

//Wumpus constructor
Wumpus::Wumpus() {


}

//prints out statement if player is near the wumpus
void Wumpus::percept() {

	cout << "You smell a terrible stench." << endl;
}
//function if the player encounters the wumpus
void Wumpus::encounter() {

}
