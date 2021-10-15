#include "config.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int
main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
                            "SAsteroids");
    sf::Font font;
    if(!font.loadFromFile(RES_DIR "Inconsolata-Regular.ttf")) {
        std::cerr << "Faile to load font\n";
        return EXIT_FAILURE;
    }
    sf::Text text("Hello, World!", font);
    auto bounds = text.getGlobalBounds();
    text.setOrigin(bounds.width / 2 + bounds.left,
                   bounds.height / 2 + bounds.top);
    text.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(text);
        window.display();
    }
    return EXIT_SUCCESS;
}