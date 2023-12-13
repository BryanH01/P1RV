#include "Utils.h"

string removeLast(string p) {
    string erased = "";
    int length = p.size();
    if (length < 2) {
        return "";
    }
    for (int i = 0; i < p.size() - 1;i++) {
        erased += p[i];
    }
    return erased;
}


string formatText(string text, int maxLength) {
    string newText;
    int compt = 0;
    string word = "";
    for (char& c : text) {
        compt += 1;
        if (c == ' ') {
            if (compt > maxLength) {
                newText += "\n" + word;
                compt = 0;
            }
            else {
                newText += " " + word;
            }
            word = "";
        }
        else {
            word += c;
        }
    }
    newText += " " + word;
    newText.erase(0, 1);
    return newText;
}

string copyFormatText(string text, string ref) {
    string newText;
    for (int i = 0; i < text.size(); i++) {
        if (text[i] == ' ' and ref[i] == '\n') {
            newText += '\n';
        }
        else {
            newText += text[i];
        }
    }
    return newText;
}

Font getFont(string name) {
    Font font;
    if (!font.loadFromFile(name))
    {
        cout << "erreur" << endl;
    }
    return font;
}
