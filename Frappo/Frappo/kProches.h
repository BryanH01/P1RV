#pragma once
#include <vector>
#include "ID.h"

using namespace std;
//pour sauvegarder la distances avec la personne
struct Distance
{
	double distance;
	ID* ptr;
};

bool inferieur(Distance a, Distance b);

string predictKNN(vector<double> test, vector<ID> data, int k);