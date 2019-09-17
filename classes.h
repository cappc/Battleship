#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>
using namespace std;

class Ship {
public:
	int size;
	string name;
	string status = "Okay";
	char shipRow[5];
	char shipCol[5];
	void shipPositionPlacement();
	friend ostream& operator<<(ostream &os, const Ship&);
	Ship() {};
	~Ship() {};
};



class Carrier : virtual public Ship{
public:
	char shipRow[5];
	char shipCol[5];
	Carrier() { this->name = "Carrier"; this->size = 5; };

};

class Battleship : public Ship {
public:
	char shipRow[4];
	char shipCol[4];
	Battleship() { this->name = "Battleship"; this->size = 4; };
};

class Cruiser : public Ship {
public:
	char shipRow[3];
	char shipCol[3];
	Cruiser() { this->name = "Cruiser"; this->size = 3; };
};

class Submarine : public Ship {
public:
	char shipRow[3];
	char shipCol[3];
	Submarine() { this->name = "Submarine"; this->size = 3; };
};

class Destroyer : public Ship {
public:
	char shipRow[2];
	char shipCol[2];
	Destroyer() { this->name = "Destroyer"; this->size = 2; };
};
