#include "Interface.h"
#include <iostream>
#include <SFML/Window/WindowBase.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "FileHandler.h"

const string ARIAL = "Arial.ttf";
const string FIXEDSYS = "FSEX302.ttf";
const string TEXTE = "livre2.txt";
const int LEN_TEXTE = 460;
const int LEN_TEST = 10;


string removeLast(string p) {
    string erased = "";
    int length = p.size();
    if (length <2) {
        return "";
    }
    for (int i = 0; i < p.size()-1;i++) {
        erased += p[i];
    }
    return erased;
}


string formatText(string text, int maxLength = 60) {
    string newText;
    int compt = 0;
    string word = "";
    for (char& c : text) {
        compt += 1;
        if (c == ' ') {
            if (compt > maxLength) {
                newText += "\n" + word;
                compt = 0;
            } else {
                newText += " " + word;
            }
            word = "";
        } else {
            word += c;
        }
    }
    newText += " " + word;
    newText.erase(0,1);
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


void afficheTexte(bool* enCours) {
    RenderWindow window(VideoMode(1600,900), "My window");
    //RenderWindow window(sf::VideoMode(1000,1000), "My window");
    srand(time(NULL));
    string texte = readFileFrom(TEXTE, rand()%LEN_TEXTE, LEN_TEST);

    Text text;
    Font font = getFont(FIXEDSYS);

    // Text
    text.setString("Hello");
    text.setFont(font);
    text.setCharacterSize(36); // in pixels, not points!
    text.setFillColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    Text text2;
    text2.setString(formatText(texte));
    cout << formatText(texte) << endl;
    text2.setFont(font);
    text2.setCharacterSize(36); // in pixels, not points!
    text2.setFillColor(Color(127,127,127));
    text2.setStyle(Text::Regular);
    FloatRect rc = text2.getLocalBounds();
    //text2.setOrigin(rc.width / 2, rc.height / 2);
    text2.setPosition(sf::Vector2f(200, 300));

    string entree = "";
    Text text3 = text2;
    text3.setString("");
    text3.setFillColor(Color::White);

    string touche = "";
    string lastTouche = "";

    while (window.isOpen()) {
        // inside the main loop, between window.clear() and window.display()
        window.clear();
        window.draw(text);
        
        window.draw(text2);
        window.draw(text3);
        window.display();
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (event.type == Event::TextEntered) {
            if (event.text.unicode) {
                std::cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << event.text.unicode << std::endl;
                if (event.text.unicode == 8) {
                    touche = "backspace";
                }
                else {
                touche = static_cast<char>(event.text.unicode);
                }
                cout << touche << endl;
            }
        } else {
            lastTouche = "";
            touche = "";
        }
        if (touche != lastTouche) {
            cout << touche + lastTouche << endl;
            lastTouche = touche;
            if (touche == "backspace") {
                entree = removeLast(entree);
            } else {
                entree += touche;
            }

            if (entree == texte.substr(0, entree.size())) {
                text3.setFillColor(Color::Green);
            } else {
                text3.setFillColor(Color::Red);
            }
            text3.setString(copyFormatText(entree,text2.getString()));
            
            //cout << touche + lastTouche << endl;
        }
        if (entree == texte) {
            window.close();
        }
    }
    *enCours = false;
    std::cout << string(text3.getString());
}

Font getFont(string name) {
    Font font;
    if (!font.loadFromFile(name))
    {
        cout << "erreur" << endl;
    }
    return font;
}

