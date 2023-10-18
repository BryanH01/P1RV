#include "Temps.h"
#include "FileHandler.h"
#include "ID.h"
#include <iostream>

using namespace std;

int main() {
	/*ID id;
	vector<ID> ids;
	ids = readData();
	addData(ids[0]);*/
	//cout << ids[1];
	vector<double> DT, FT;
	mesure(&DT,&FT);
	cout << DT.size();
	cout << FT.size();
	return 0;
}
