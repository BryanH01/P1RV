#include "Interface.h"
#include <iostream>
#include <SFML/Window/WindowBase.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "FileHandler.h"
#include "Utils.h"

const string ARIAL = "Arial.ttf";
const string FIXEDSYS = "FSEX302.ttf";
const string TEXTE = "livre2.txt";
const int LEN_TEXTE = 460;
const int LEN_TEST = 10;


string getLogin(RenderWindow* window) {
    Text text;
    Font font = getFont(FIXEDSYS);

    Text text2;
    text2.setString("Nom : ");
    text2.setFont(font);
    text2.setCharacterSize(36); // in pixels, not points!
    text2.setFillColor(Color::White);
    text2.setStyle(Text::Regular);
    text2.setPosition(sf::Vector2f(200, 300));

    string entree = "";
    Text text3 = text2;
    text3.setString("");
    text3.setFillColor(Color::White);
    text3.setPosition(sf::Vector2f(300, 300));

    string touche = "";
    string lastTouche = "";
    window->setActive(true);
    while (window->isOpen()) {
        // inside the main loop, between window->clear() and window->display()
        window->clear();
        //window->draw(text);

        window->draw(text2);
        window->draw(text3);
        window->display();
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window->close();
        }
        if (event.type == Event::TextEntered) {
            if (event.text.unicode) {
                //std::cout << "     ASCII character typed:      " << static_cast<char>(event.text.unicode) << event.text.unicode << std::endl;
                if (event.text.unicode == 8) {
                    touche = "backspace";
                } else if (event.text.unicode == 13) {
                    touche = "return";
                } else {
                    touche = static_cast<char>(event.text.unicode);
                }
            }
        }
        else {
            if (lastTouche == "return") {
                //window->setActive(false);
                window->close();
                break;
            }
            lastTouche = "";
            touche = "";
        }
        if (touche != lastTouche) {
            
            lastTouche = touche;
            if (touche == "backspace") {
                entree = removeLast(entree);
            } else if(touche != "return") {
                entree += touche;
            }
            text3.setString(entree);
        }
    }
    return entree;
}

float afficherTexte(bool* enCours) {
    RenderWindow window(VideoMode(1600, 900), "My window");
    return afficheTexte(enCours, &window);
}

float afficheTexte(bool* enCours, RenderWindow* window) {
    //RenderWindow window(VideoMode(1600,900), "My window");
    srand(time(NULL));
    string texte = readFileFrom(TEXTE, rand()%LEN_TEXTE, LEN_TEST);

    Text text;
    Font font = getFont(FIXEDSYS);

    Text text2;
    text2.setString(formatText(texte));
    //cout << formatText(texte) << endl;
    text2.setFont(font);
    text2.setCharacterSize(36); // in pixels, not points!
    text2.setFillColor(Color(127,127,127));
    text2.setStyle(Text::Regular);
    //FloatRect rc = text2.getLocalBounds();
    //text2.setOrigin(rc.width / 2, rc.height / 2);
    text2.setPosition(sf::Vector2f(200, 300));

    string entree = "";
    Text text3 = text2;
    text3.setString("");
    text3.setFillColor(Color::White);

    string touche = "";
    string lastTouche = "";
    int backspaceNb = 0;

    window->setActive(true);
    while (window->isOpen()) {
        // inside the main loop, between window->clear() and window->display()
        window->clear();
        //window->draw(text);
        
        window->draw(text2);
        window->draw(text3);
        window->display();
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window->close();
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
                //cout << touche << endl;
            }
        } else {
            lastTouche = "";
            touche = "";
        }
        if (touche != lastTouche) {
            //cout << touche + lastTouche << endl;
            lastTouche = touche;
            if (touche == "backspace") {
                entree = removeLast(entree);
                backspaceNb++;
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
        if (entree == texte or !*enCours) {
            window->close();
        }
    }
    *enCours = false;
    std::cout << string(text3.getString());
    return float(backspaceNb) / float(texte.size()) * 100;
}
