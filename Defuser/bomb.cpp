#include "bomb.h"

void Bomb::initBomb(string bombFile) {
	string wire;
	ifstream file;;

	file.open(bombFile);

	if (file.is_open())
	{
		while (file.good()) {
			getline(file, wire);
			wires.push_back(wire);
		}
		file.close();
	}
	else {
		cout << "file not opened" << endl;
		promptFile();
	}
}

void Bomb::promptFile() {
	string bombFile;
	cout << "Enter Bomb File: ";
	cin >> bombFile;
	initBomb(bombFile);
}

void Bomb::displayBomb() {
	//cout << string(100, '\n');
	for (int i = 0; i < wires.size(); i++) {
		cout << wires[i] << endl;
	}
}

void Bomb::defuse() {
	char wire = chooseWire();
	firstRule(wire);

}

void Bomb::defused() {
	cout << "Defused!" << endl;
	wires.clear();
}

void Bomb::blowUp() {
	exploded = true;
	cout << endl << "Boom!" << endl;
	wires.clear();
}

char Bomb::chooseWire() {
	char colorChoice;
	bool invalidChoice = true;

	while (invalidChoice) {
		displayBomb();
		cout << endl << "Choose a wire (W, B, R, O, G): ";
		cin >> colorChoice;

		colorChoice = toupper(colorChoice);
		switch (colorChoice) {
		case 'W':
			return 'W';
		case 'B':
			return 'B';
		case 'R':
			return 'R';
		case 'O':
			return 'O';
		case 'G':
			return 'G';
		default:
			break;
		}
	}
}

void Bomb::firstRule(char wire) {
	if (wire == 'B' || wire == 'O' || wire == 'G') {
		blowUp();
	}
	else {
		cutWireHandler(wire);
		secondRule(chooseWire());
	}
}

void Bomb::secondRule(char wire) {
	if (lastWire == 'W') {
		if (wire == 'R' || wire == 'O' || wire == 'G') {
			blowUp();
		}
		else {
			cutWireHandler(wire);
			firstWire = 'W';
			thirdRule(chooseWire());
		}
	}
	else if (lastWire == 'R') {
		if (wire == 'W' || wire == 'O' || wire == 'G') {
			blowUp();
		}
		else {
			cutWireHandler(wire);
			firstWire = 'R';
			thirdRule(chooseWire());
		}
	}
}

void Bomb::thirdRule(char wire) {
	if (firstWire == lastWire) {
		if (wire != 'B') {
			blowUp();
		}
		else {
			cutWireHandler(wire);
			fourthRule(chooseWire());
		}
	}
	else if (firstWire != lastWire) {
		if (wire != 'O') {
			blowUp();
		}
		else {
			cutWireHandler(wire);
			fourthRule(chooseWire());
		}
	}
}

void Bomb::fourthRule(char wire) {
	if (lastWire == 'B') {
		if (wire != 'G') {
			blowUp();
		}
		else {
			cutWireHandler(wire);
			fifthRule(chooseWire());
		}
	}
	else if (lastWire == 'O') {
		if (wire != 'G') {
			blowUp();
		}
		else {
			defused();
		}
	}
}

void Bomb::fifthRule(char wire) {
	if (wire != 'O') {
		blowUp();
	}
	else {
		defused();
	}
}

void Bomb::cutWireHandler(char wire) {
	switch (wire) {
	case 'W':
		if (cutWire("White")) {
			lastWire = 'W';
		}
		else {
			cutWireHandler(chooseWire());
		}
		break;
	case 'B':
		if (cutWire("Black")) {
			lastWire = 'B';
		}
		else {
			cutWireHandler(chooseWire());
		}
		break;
	case 'R':
		if (cutWire("Red")) {
			lastWire = 'R';
		}
		else {
			cutWireHandler(chooseWire());
		}
		break;
	case 'O':
		if (cutWire("Orange")) {
			lastWire = 'O';
		}
		else {
			cutWireHandler(chooseWire());
		}
		break;
	case 'G':
		if (cutWire("Green")) {
			lastWire = 'G';
		}
		else {
			cutWireHandler(chooseWire());
		}
		break;
	}
}

bool Bomb::cutWire(string wire) {
	auto wireIterator = find(wires.begin(), wires.end(), wire);

	if (wireIterator != wires.end()) {
		int index = distance(wires.begin(), wireIterator);
		wires[index] = "(cut)" + wire + "(cut)";
		return true;
	}
	else {
		cout << "Wire doesn't exist!";
		return false;
	}
}

bool Bomb::keepPlaying(istream& input) {
	/*
	Will be something like this:

	int value;
    std::cout << "Enter a number: ";
    input >> value;
    return value;
	
	*/
	return false;
}