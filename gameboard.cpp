#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "functions.cpp"


int main() {
	
	
	srand(time(NULL));

	carrier.shipPositionPlacement();
	battleship.shipPositionPlacement();
	cruiser.shipPositionPlacement();
	submarine.shipPositionPlacement();
	destroyer.shipPositionPlacement();

	cout << "Welcome to Battleship!" << endl;
	cout << "Enemy ship positions have been set. Fire Away!" << endl;

	
	
	
	blankBoardDisplay();
	shotAttempt();
	while (!endGame == true) {
		gameDisplay(row, col);
	}

	return 0;
}


	