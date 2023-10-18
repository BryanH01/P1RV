#pragma once


#include <fstream>
#include <iostream>
#include <vector>
#include "ID.h"

using namespace std;

vector<ID> readData();
void addData(ID id);
string readFile(string fileName);
