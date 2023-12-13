#include "Temps.h"
#include "ID.h"
#include "kProches.h"

using namespace std;

// pour faire la sort
bool inferieur(Distance a, Distance b) {
	bool i = false;
	if (a.distance < b.distance) {
		i = true;
	}
	return i;
}

string predictKNN(vector<double> test, vector<ID> data, int k) {
	vector<Distance> Table;
	ID id;
	id.setScore(test);

	// calculer les distances
	for (int i = 0; i < data.size(); i++) {
		Distance d;
		d.ptr = &data[i];
		d.distance = id.distance(data[i]);
		Table.push_back(d);
	}

	// faire la sort
	for (int i = 0; i < Table.size(); i++) {
		for (int j = i + 1; j < Table.size(); j++) {
			if (!inferieur(Table[i], Table[j])) {
				Distance trans = Table[i];
				Table[i] = Table[j];
				Table[j] = trans;
			}
		}
	}

	for (int i = 0; i < Table.size();i++) {
		cout << Table[i].ptr->getPersonne() << ": " << Table[i].distance << endl;
	}

	// identifier la personne
	vector<string> kProches;
	for (int i = 0; i < k; i++) {
		kProches.push_back(Table[i].ptr->getPersonne());
	}
	int a = 0; // le nombre le plus grand
	int b = 0;
	string Personne;
	for (int i = 0; i < k; i++) {
		a = count(kProches.begin(), kProches.end(), kProches[i]);
		if (a > b) {
			Personne = kProches[i];
			b = a;
		}
	}
	cout << "c'est " << Personne << " !" << endl;
	return Personne;
}
