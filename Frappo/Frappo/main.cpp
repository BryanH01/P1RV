#include "Temps.h"
#include "FileHandler.h"
#include "ID.h"
#include <iostream>

using namespace std;

int main() {
	ID id;
	vector<ID> ids;
	ids = readData();
	addData(ids[0]);
	//cout << ids[1];
	return 0;
}
