#pragma once
#include <iostream>
#include <vector>

using namespace std;

class ID {
public :
	std::string personne;
	std::vector<double> score;
	ID();
	ID(std::string a, std::vector<double> b);
	void setPersonne(std::string a);
	void setScore(std::vector<double> b);

	double distance(ID id);
	std::vector<double> getScore();
	std::string getPersonne();
};
