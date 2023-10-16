#include "FileHandler.h"

#include <string>
#include <sstream>

using namespace std;

vector<ID> readData() {
    vector<ID> data;

    string str;
    fstream file;
    file.open("data.txt", ios::in | ios::out);
    while (getline(file, str)) {
        cout << str << endl;
        string name = str.substr(0, str.find(' '));
        str.erase(0, str.find(" ") + 1);
        vector<double> scores;
        stringstream ss(str);
        while (getline(ss, str, ' ')) {
            string score = str.substr(0, str.find(" "));
            str.erase(0, str.find(" ") + 1);
            scores.push_back(stod(score));
        }
        ID id(name, scores);
        data.push_back(id);
    }
    file.close();

    /*for (vector<ID>::iterator it = data.begin(); it != data.end(); it++) {
        cout << it->personne << endl;
        for (vector<double>::iterator ite = it->score.begin(); ite != it->score.end(); ite++) {
            cout << *ite << ' ';
        }
    }*/

    return data;

}

void addData(ID id) {
    string str;
    fstream file;
    file.open("data.txt", ios::app);
    ostringstream os;
    os << id.getPersonne() << ' ';
    for (int i = 0; i < id.getScore().size(); i++) {
        os << id.getScore()[i] << ' ';
    }
    file << os.str() << endl;
    file.close();

}