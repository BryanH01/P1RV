#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Window.hpp>


using namespace sf;
using namespace std;

void affiche();
Font getFont(string name);
Text toText(string text);