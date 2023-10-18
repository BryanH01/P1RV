#include<iostream>
#include<numeric>
#include<algorithm>
#include"calculScore.h"

using namespace std;

vector<double> calculScore(vector<double>* DT, vector<double>* FT) {
	vector<double> score;
	// score : moyenne de DT, moyenne de FT, mediane de DT, mediane de FT, variance de DT, . de FT, méthode de Hocquet (cf. note)

	// moyenne 
	score.push_back(moyenne(DT));
	score.push_back(moyenne(FT));

	//mediane
	score.push_back(mediane(DT));
	score.push_back(mediane(FT));

	//variance
	score.push_back(variance(DT));
	score.push_back(variance(FT));

	//Hocquet
	score.push_back(Hocquet(DT));
	score.push_back(Hocquet(FT));

	return score;
}

double moyenne(vector<double>* t) {
	double mean = accumulate(t->begin(), t->end(), 0.0) / t->size();
	return mean;
}

double mediane(vector<double>* t) {
	vector<double> tp = *t;
	sort(tp.begin(), tp.end());
	int k = int(tp.size() / 2);
	return tp[k];
}

double variance(vector<double>* t) {
	double mean = moyenne(t);
	double sq_sum = inner_product(t->begin(), t->end(), t->begin(), 0.0);
	double stdev = sqrt(sq_sum / t->size() - mean * mean);
	return stdev;
}

double Hocquet(vector<double>* t) {
	double mean = moyenne(t);
	double stdev = variance(t);
	double Hocquet = 1;
	for (int i = 0; i < t->size(); i++) {
		double k = -abs((*t)[i] - mean) / stdev;
		Hocquet -= exp(k);
	}
	return Hocquet;
}