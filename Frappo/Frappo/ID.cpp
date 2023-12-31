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
	double dist = 0.0;
	double diff;
	for (int i = 0; i < score.size(); i++) {
		diff = score[i] - id.getScore()[i];
		if (score[i] < 1) {
			diff *= 500;
		}
		dist += diff * diff;
	}
	return sqrt(dist);
}

vector<double> ID::getScore() {
	return score;
}

string ID::getPersonne() {
	return personne;
}

//ostream& operator<<(ostream& os, ID& id) {
//	os << id.getPersonne() << ' ';
//	for (int i = 0; i < id.getScore().size(); i++) {
//		os << id.getScore()[i] << ' ';
//	}
//	os << endl;
//	return os;
//}