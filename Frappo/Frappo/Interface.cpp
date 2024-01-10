#include "Interface.h"
#include <iostream>
#include <SFML/Window/WindowBase.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "FileHandler.h"
#include "Utils.h"

const string ARIAL = "Arial.ttf";
const string FIXEDSYS = "fixedsys.ttf";
const string TEXTE = "livre2.txt";
const int LEN_TEXTE = 460;
const int LEN_TEST = 120;

int intro() {
    int mode = 0;

    Font font;
    if (!font.loadFromFile(FIXEDSYS))
    {
        // error...
        cout << "fail to load le font" << endl;
    }
    vector<Text> v;

    RenderWindow window(VideoMode(1600, 900), "SFML");

    Text text;
    text.setFont(font);
    text.setString("Frappologie");
    text.setCharacterSize(36);
    text.setFillColor(Color::White);
    text.setStyle(Text::Bold);
    text.setPosition(750, 300);

    Text e;
    e.setFont(font);
    e.setString("Enregistrer");
    e.setCharacterSize(30);
    e.setFillColor(Color::White);
    e.setStyle(Text::Bold);
    e.setPosition(350, 500);

    Text t;
    t.setFont(font);
    t.setString("Tester");
    t.setCharacterSize(30);
    t.setFillColor(Color::White);
    t.setStyle(Text::Bold);
    t.setPosition(1150, 500);

    while (window.isOpen())
    {
        window.clear(Color::Black);

        window.draw(text);
        window.draw(t);
        window.draw(e);

        window.display();

        Event event;
        Vector2i mouse = Mouse::getPosition(window);
        while (window.pollEvent(event))
        {
            switch (event.type) {
            case Event::Closed:
                window.close();
                break;
            case Event::MouseButtonPressed:
                if ((mode == 0) && (isE(mouse.x, mouse.y))) {
                    mode = 1;
                    window.close();
                }
                if ((mode == 0) && (isI(mouse.x, mouse.y))) {
                    mode = 2;
                    window.close();
                }
                break;
            default:
                break;
            }
        }
    }

    return mode;
}

bool isE(int x, int y) {
    if ((250 < x) && (x < 550) && (450 < y) && (y < 550)) {
        return true;
    }
    else {
        return false;
    }
}

bool isI(int x, int y) {
    if ((1050 < x) && (x < 1350) && (450 < y) && (y < 550)) {
        return true;
    }
    else {
        return false;
    }
}

void finiE() {
    Font font;
    if (!font.loadFromFile(FIXEDSYS))
    {
        // error...
        cout << "fail to load le font" << endl;
    }
    vector<Text> v;
    RenderWindow window(VideoMode(1600, 900), "SFML");

    Text text;
    text.setFont(font);
    text.setString("Fin d'enregistrement");
    text.setCharacterSize(36);
    text.setFillColor(Color::White);
    text.setStyle(Text::Bold);
    text.setPosition(600, 300);

    Text e;
    e.setFont(font);
    e.setString("Rentrer");
    e.setCharacterSize(30);
    e.setFillColor(Color::White);
    e.setStyle(Text::Bold);
    e.setPosition(1150, 500);

    while (window.isOpen())
    {
        window.clear(Color::Black);

        window.draw(text);
        window.draw(e);

        window.display();

        Event event;
        Vector2i mouse = Mouse::getPosition(window);
        while (window.pollEvent(event))
        {
            switch (event.type) {
            case Event::Closed:
                window.close();
                break;
            case Event::MouseButtonPressed:
                if (isI(mouse.x, mouse.y)) {
                    window.close();
                }
                break;
            default:
                break;
            }
        }
    }
}

void finiI(string nom) {
    Font font;
    if (!font.loadFromFile(FIXEDSYS))
    {
        // error...
        cout << "fail to load le font" << endl;
    }
    vector<Text> v;
    RenderWindow window(VideoMode(1600, 900), "SFML");

    Text text;
    text.setFont(font);
    text.setString("C'est " + nom + ".");
    text.setCharacterSize(36);
    text.setFillColor(Color::White);
    text.setStyle(Text::Bold);
    text.setPosition(600, 300);

    Text e;
    e.setFont(font);
    e.setString("Rentrer");
    e.setCharacterSize(30);
    e.setFillColor(Color::White);
    e.setStyle(Text::Bold);
    e.setPosition(1150, 500);

    while (window.isOpen())
    {
        window.clear(Color::Black);

        window.draw(text);
        window.draw(e);

        window.display();

        Event event;
        Vector2i mouse = Mouse::getPosition(window);
        while (window.pollEvent(event))
        {
            switch (event.type) {
            case Event::Closed:
                window.close();
                break;
            case Event::MouseButtonPressed:
                if (isI(mouse.x, mouse.y)) {
                    window.close();
                }
                break;
            default:
                break;
            }
        }
    }
}

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
    srand(time(NULL));
    string texte = readFileFrom(TEXTE, rand()%LEN_TEXTE, LEN_TEST);

    Text text;
    Font font = getFont(FIXEDSYS);

    Text text2;
    text2.setString(formatText(texte));
    text2.setFont(font);
    text2.setCharacterSize(36); // in pixels, not points!
    text2.setFillColor(Color(127,127,127));
    text2.setStyle(Text::Regular);
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
            }
        } else {
            lastTouche = "";
            touche = "";
        }
        if (touche != lastTouche) {
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
        }
        if (entree == texte or !*enCours) {
            window->close();
        }
    }
    *enCours = false;
    std::cout << string(text3.getString());
    return float(backspaceNb) / float(texte.size()) * 100;
}
