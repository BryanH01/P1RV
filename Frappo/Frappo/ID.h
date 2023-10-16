#pragma once
#include <iostream>
#include <vector>


class ID {
private :
	std::string personne;
	std::vector<double> score;
public :
	ID();
	//ID(std::string a, std::vector<double> b);
	void setPersonne(std::string a);
	void setScore(std::vector<double> b);

	double distance(ID id);
};