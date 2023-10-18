#include "Temps.h"
#include "FileHandler.h"
#include "ID.h"
#include "calculScore.h"
#include <iostream>

using namespace std;

int main() {
	/*ID id;
	vector<ID> ids;
	ids = readData();
	addData(ids[0]);*/
	//cout << ids[1];
	string name;
	cout << "Frappologie" << endl;
	cout << "Veuillez entrer votre nom : ";
	cin >> name;
	vector<double> DT, FT;
	mesure(&DT,&FT);
	FT.erase(FT.begin());
	DT.pop_back();
	FT.pop_back();
	//cout << DT.size();
	//cout << FT.size();
	//test();
	vector<double> scores;
	scores = calculScore(&DT, &FT);
	ID personne(name, scores);
	addData(personne);
	return 0;
}
