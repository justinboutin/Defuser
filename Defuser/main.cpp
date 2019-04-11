#include "bomb.h"

#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	Bomb bomb;

	string bombFile;
	bool keepPlaying = true;
	char response;

	while (keepPlaying == true) {
		bomb.promptFile();
		bomb.defuse();
		cout << "Keep Playing? (y / n): ";
		cin >> response;
		if (response == 'n') {
			return 1;
		}
	}

	return 1;
}