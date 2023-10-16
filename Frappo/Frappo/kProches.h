#pragma once

//pour sauvegarder la distances avec la personne
struct Distance
{
	double distance;
	ID* ptr;
};

bool inferieur(Distance a, Distance b);

void predictKNN(vector<double> test, vector<ID> data, int k);