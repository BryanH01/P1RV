#pragma once
#include <iostream>
#include <SFML/Graphics/Font.hpp>

using namespace std;
using namespace sf;

string removeLast(string p);

string formatText(string text, int maxLength = 60);

string copyFormatText(string text, string ref);

Font getFont(string name);