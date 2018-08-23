#include <iostream>
#include <string>
#include "CD.h"

using namespace std;

CD::CD(string name, string songs[]) {
	songer = name;
	for (int i = 0; i < 6; i++)
		CD::songs[i] = songs[i];
}

string CD::getSonger() {
	return songer;
}

string CD::getSong(int index) {
	return songs[index];
}

void CD::listSongs() {
	cout << "Songer: " << songer << endl;
	for (int i = 0; i < 6; i++)
		cout << "  " << (i + 1) << ". " << (*songs)[i] << endl;
}
