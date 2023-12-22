#include "intro.h"

int intro() {
    int mode = 0;

    Font font;
    if (!font.loadFromFile("fixedsys.ttf"))
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
    text.setFillColor(Color::Black);
    text.setStyle(Text::Bold);
    text.setPosition(750, 300);

    Text e;
    e.setFont(font);
    e.setString("Enregistrer");
    e.setCharacterSize(30);
    e.setFillColor(Color::Black);
    e.setStyle(Text::Bold);
    e.setPosition(350, 500);

    Text t;
    t.setFont(font);
    t.setString("Tester");
    t.setCharacterSize(30);
    t.setFillColor(Color::Black);
    t.setStyle(Text::Bold);
    t.setPosition(1150, 500);

    while (window.isOpen())
    {
        window.clear(Color::White);

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
                if ((mode == 0) && (isT(mouse.x, mouse.y))) {
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