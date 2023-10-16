#include "ID.h"

using namespace std;

ID::ID() {
	string a;
	vector<double> b;
	personne = a;
	score = b;
}

ID::ID(string a, vector<double> b) {
	personne = a;
	score = b;
}

void ID::setPersonne(string a) {
	personne = a;
}

void ID::setScore(vector<double> b) {
	score = b;
}

double ID::distance(ID id) {
	double diff = 0.0;
	for (int i = 0; i < score.size(); i++) {
		diff = score[i] - id.getScore()[i];
		diff += diff * diff;
	}
	return sqrt(diff);
}

vector<double> ID::getScore() {
	return score;
}

string ID::getPersonne() {
	return personne;
}