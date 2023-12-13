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
        if (str[0] == '#') {
            continue;
        }
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

string readFile(string fileName) {
    string str;
    fstream file;
    file.open(fileName, ios::in | ios::out);
    getline(file, str);
    file.close();
    return str;
}

string readFileFrom(string fileName, int line, int maxLength) {
    string str = "";
    string stri;
    fstream file;
    file.open(fileName, ios::in | ios::out);

    // pass the begining of the file to line [line]
    for (int i = 0; i < line; i++) {
        getline(file, stri);
    }
    // get text
    getline(file, stri);
    str += stri;
    while (str.size() < maxLength) {
        getline(file, stri);
        str += ' ' + stri;
    }

    // remove double space
    char lastChar = NULL;
    stri = "";
    for (char& c : str) {
        if (c == ' ' and lastChar == ' ') {
            continue;
        }
        else {
            lastChar = c;
            stri += c;
        }
    }

    // remove traling whitespace if there is one
    const auto strEnd = stri.find_last_not_of(" ");
    stri = stri.substr(0, strEnd+1);
    return stri;
}