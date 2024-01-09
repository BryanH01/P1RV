#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


using namespace sf;
using namespace std;

string getLogin(RenderWindow* window);
float afficheTexte(bool* enCours, RenderWindow* window);
float afficherTexte(bool* enCours);
Font getFont(string name);