#ifndef BOMB_H
#define BOMB_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Bomb {
public:
	// Data Members
	vector<string> wires;
	char lastWire;
	char firstWire;

	// Member Functions
	void initBomb(string bombFile);
	void displayBomb();
	void promptFile();
	void defuse();
	void defused();
	void blowUp();
	char chooseWire();
	void firstRule(char wire);
	void secondRule(char wire);
	void thirdRule(char wire);
	void fourthRule(char wire);
	void cutWireHandler(char wire);
	bool cutWire(string wire);
};

#endif