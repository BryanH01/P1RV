#include "Temps.h"
#include "kProches.h"
#include "calculScore.h"
#include "FileHandler.h"
#include <vector>
#include <iostream>

using namespace std;

void Enregistrement() {
	string name;
	cout << "Frappologie" << endl;
	cout << "Veuillez entrer votre nom : ";
	cin >> name;
	vector<double> DT, FT;
	mesure(&DT,&FT);
	// remove first FT and last FT and DT
	FT.erase(FT.begin());
	DT.pop_back();
	FT.pop_back();
	vector<double> scores;
	scores = calculScore(&DT, &FT);
	ID personne(name, scores);
	addData(personne);
}

void Identification() {
	vector<double> DT, FT;
	mesure(&DT, &FT);

	// entrer le k
	int k;
	cout << "entrer le k :";
	cin >> k;
	vector<double> score = calculScore(&DT, &FT);
	for (int i = 0; i < score.size(); i++) {
		cout << score[i] << " ";
	}
	cout << endl;
	vector<ID> id = readData();
	predictKNN(score, id, k);
}