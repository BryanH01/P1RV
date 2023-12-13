#include "Frappo.h"

using namespace std;

void Enregistrement() {
	string name;
	cout << "Frappologie" << endl;
	cout << "Veuillez entrer votre nom : ";
	cin >> name;
	vector<double> DT, FT;
	//mesure(&DT,&FT);
	// remove first FT and last FT and DT
	FT.erase(FT.begin());
	DT.pop_back();
	FT.pop_back();
	vector<double> scores;
	scores = calculScore(&DT, &FT);
	ID personne(name, scores);
	addData(personne);
}

string Identification() {
	bool enCours = true;
	vector<double> DT, FT;
	thread t1(mesure, &DT, &FT, &enCours);
	auto fut2 = async(afficheTexte, & enCours);
	t1.join();

	// entrer le k
	int k = 1;
	//cout << "entrer le k :";
	//cin >> k;
	vector<double> score = calculScore(&DT, &FT);
	for (int i = 0; i < score.size(); i++) {
		cout << score[i] << " ";
	}
	cout << endl;
	vector<ID> id = readData();
	return predictKNN(score, id, k);
}