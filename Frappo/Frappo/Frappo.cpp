#include "Frappo.h"
#include <SFML/Graphics/RenderWindow.hpp>

using namespace std;

void Enregistrement() {
	string name;
	//cout << "Frappologie" << endl;
	//cout << "Veuillez entrer votre nom : ";
	//cin >> name;
	RenderWindow window(VideoMode(1600, 900), "My window");
	name = getLogin(&window);
	cout << "ça passe ;(";
	vector<double> DT, FT;
	bool enCours = true;
	thread t1(mesure, &DT, &FT, &enCours);
	auto fut2 = async(afficherTexte, &enCours);
	//cout << "nombre " << fut2.get() << endl;
	t1.join();
	////mesure(&DT,&FT);
	// remove first FT and last FT and DT
	FT.erase(FT.begin());
	DT.pop_back();
	FT.pop_back();
	vector<double> scores;
	scores = calculScore(&DT, &FT);
	scores.push_back(fut2.get());
	ID personne(name, scores);
	addData(personne);

	//cout << getLogin(&window) << endl;
}

string Identification() {
	bool enCours = true;
	vector<double> DT, FT;
	thread t1(mesure, &DT, &FT, &enCours);
	auto fut2 = async(afficherTexte, &enCours);
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