#include "Temps.h"
#include "ID.h"

using namespace std;

//pour sauvegarder la distances avec la personne
struct Distance
{
	double distance;
	ID* ptr;
};

// pour faire la sort
bool inferieur(Distance a, Distance b) {
	bool i = false;
	if (a.distance > b.distance) {
		i = true;
	}
	return i;
}

void predictKNN(vector<double> test, vector<ID> data, int k) {
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

	// identifier la personne
	vector<ID*> kProches;
	for (int i = 0; i < k; i++) {
		kProches.push_back(Table[i].ptr);
	}

}
