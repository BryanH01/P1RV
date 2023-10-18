#include "Temps.h"
#include "kProches.h"
#include "calculScore.h"
#include "FileHandler.h"
#include <vector>
#include <iostream>

using namespace std;

void Identification() {
	vector<double> DT, FT;
	mesure(&DT, &FT);

	// entrer le k
	int k;
	cout << "entrer le k :";
	cin >> k;
	vector<double> score = calculScore(&DT, &FT);
	vector<ID> id = readData();
	predictKNN(score, id, k);
}