//Casey Capp and Laura Lucas
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include "classes.h"
using namespace std;

const int ROWS = 12;
const int COLUMNS = 12;

int battleshipHitCount = 0;

char blankBoard[ROWS][COLUMNS];
char board[ROWS][COLUMNS];
char row;
char col;

char rowLabel2 = 47;								//Sets blank grid row labels on program start
char colLabel2 = 64;								//Sets blank grid column labels on program start

bool endGame = false;

char shotAttempt();

void Ship::shipPositionPlacement() {				//Function to set random ship placements

	int orientation = rand() % 2;

	int a = 0;
	int b = 0;
	int x = rand() % 9 + 65;
	int y = rand() % 8 + 48;

	if (orientation == 0) {							//Horizantal ship orientation
		this->shipRow[a] = x;
		this->shipCol[b] = y;
		y++;
		b++;
		for (b = 1; b < this->size; ++b) {
			this->shipCol[b] = y++;
			this->shipRow[b] = x;
		}
	}
	else {
		this->shipRow[a] = x;						//Vertical ship orientation
		x++;
		a++;
		this->shipCol[b] = y;
		for (a = 1; a < this->size; a++) {
			this->shipRow[a] = x++;
			this->shipCol[a] = y;
		}
	}
}

Carrier carrier;									//Creates classes for each ship
Battleship battleship;
Cruiser cruiser;
Submarine submarine;
Destroyer destroyer;



bool checkHit(char x, char y, const Ship &s) {		//Checks the coordinates of the ship versus the user input
	char shotRow = x;
	char shotCol = y;
	int f = 0;
	for (f = 0; f < s.size; f++) {
		if (s.shipRow[f] == shotRow && s.shipCol[f] == shotCol) {
			return true;
		}
	}
	return false;
}




void gameDisplay(char x = ' ', char y = ' ') {		//Displays edited game board
	int i = 1;
	int j = 1;

	char rowLabel = 47;
	char colLabel = 64;

	char row = x;
	char col = y;

	char hit = 'X';
	char miss = '~';

	bool carrierHit = checkHit(row, col, carrier);	//Checks for hits on ships
	bool battleshipHit = checkHit(row, col, battleship);
	bool cruiserHit = checkHit(row, col, cruiser);
	bool submarineHit = checkHit(row, col, submarine);
	bool destroyerHit = checkHit(row, col, destroyer);

	for (i = 1; i < ROWS; ++i)						//Begins checking
	{
		for (j = 1; j < COLUMNS; ++j)
		{
			
			if (carrierHit == true) {
				board[x - 63][y - 46] = hit;
				carrier.status = "Hit!";
			}
			else if (battleshipHit == true) {
				board[x - 63][y - 46] = hit;
				battleship.status = "Hit!";
			}
			else if (cruiserHit == true) {
				board[x - 63][y - 46] = hit;
				cruiser.status = "Hit!";
			}
			else if (submarineHit == true) {
				board[x - 63][y - 46] = hit;
				submarine.status = "Hit!";
			}
			else if (destroyerHit == true) {
				board[x - 63][y - 46] = hit;
				destroyer.status = "Hit!";
			}
			else 
				board[x - 63][y - 46] = miss;
			if (i == 1 && j == 1) {
				board[i][j] = ' ';
			}
			if (i == 1) {
				board[i][j] = rowLabel;
				if (rowLabel == '/')
					board[i][j] = ' ';
				rowLabel = rowLabel + 1;
			}
			if (j == 1) {
				board[i][j] = colLabel;
				if (colLabel == '@')
					board[i][j] = ' ';
				colLabel = colLabel + 1;
			}	
			
		cout << board[i][j] << "  ";
		}
			
	cout << endl;
	}
	if (battleshipHit == true) {					//Increments counter if the battleship is hit. Once counter reaches 4 hits, the battleship is sunk and the game ends.
		++::battleshipHitCount;
		if (::battleshipHitCount == 4)
			battleship.status = "destroyed!";
	}
	shotAttempt();
}



char shotAttempt() {
	const string errorMessage = "Numbers out of bounds. Please input 0-9.";
	ofstream fout("battleship_user_input.txt", ios_base::app);	
	while (battleshipHitCount == 4) {
		endGame = true;								//opens file and appends it with user inputs
		system("CLS");
		cout << battleship << endl;
		break;
	}
	cout << "Enter the row (A-J) and column (0-9): " << endl;
	cin >> row;
	if (islower(row))								//Handles if lowercase letters are used instead of uppercase letters.
		row = toupper(row);
	cin >> col;
	try {
		if (col < 48 || col > 57) {
			throw(errorMessage);
		}
	}
	catch(...){
		cout << "Exception caught"<<endl;
		shotAttempt();
	}
	fout << "Row: " << row << ", Col: " << col << endl;
	cout << endl;
	fout.close();
	return row, col;
	
}


void blankBoardDisplay() {							//Displays initial blank game board.
	for (int a = 1; a < ROWS; ++a){
		for (int b = 1; b < COLUMNS; ++b){
			if (a == 1 && b == 1) {
				blankBoard[a][b] = ' ';
			}
			if (a == 1) {
				blankBoard[a][b] = rowLabel2;
				if (rowLabel2 == '/')
					blankBoard[a][b] = ' ';
				rowLabel2 = rowLabel2 + 1;
			}
			if (b == 1) {
				blankBoard[a][b] = colLabel2;
				if (colLabel2 == '@')
					blankBoard[a][b] = ' ';
				colLabel2 = colLabel2 + 1;
			}
			cout << blankBoard[a][b] << "  ";
		}
		cout << endl;
	}
}




ostream& operator<<(ostream &os, const Ship &s) {	//Overloaded extraction operator.
	cout << "The " << s.name << " has been " << s.status << " Game over" << endl;
	return os;
}
