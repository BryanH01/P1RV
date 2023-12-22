#include "fini.h"

void fini(string p) {
    Font font;
    if (!font.loadFromFile("fixedsys.ttf"))
    {
        // error...
        cout << "fail to load le font" << endl;
    }

    RenderWindow window(VideoMode(1600, 900), "SFML");

    Text text;
    text.setFont(font);
    text.setString("C'est " + p + " !");
    text.setCharacterSize(36);
    text.setFillColor(Color::Black);
    text.setStyle(Text::Bold);
    text.setPosition(750, 450);

    Text retu;
    retu.setFont(font);
    retu.setString("Rentrer");
    retu.setCharacterSize(36);
    retu.setFillColor(Color::Black);
    retu.setStyle(Text::Bold);
    retu.setPosition(1400, 800);

    while (window.isOpen())
    {
        window.clear(Color::White);

        window.draw(text);

        window.display();

        Event event;
        Vector2i mouse = Mouse::getPosition(window);
        while (window.pollEvent(event))
        {
            switch (event.type) {
            case Event::Closed:
                window.close();
                break;
            default:
                break;
            }
        }
    }
}