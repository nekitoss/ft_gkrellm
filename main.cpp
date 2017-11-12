
#include "CPU.hpp"
#include <SFML/Graphics.hpp>

int main(void)
    {
        sf::RenderWindow window(sf::VideoMode(1200, 600), "ft_gkrellm");

        sf::Text text;
    sf::Font font;
        font.loadFromFile("GloriaHallelujah.ttf");
// select the font
    text.setFont(font); // font is a sf::Font

// set the string to display
    text.setString("Hello world");

// set the character size
    text.setCharacterSize(24); // in pixels, not points!

// set the color
    text.setFillColor(sf::Color::Black);
    text.setPosition(0, 0);

// set the text style
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);




    while (window.isOpen())
        {
            // check all the window's events that were triggered since the last iteration of the loop
            sf::Event event;
            while (window.pollEvent(event))
            {
                // "close requested" event: we close the window

                if (event.type == sf::Event::Closed)
                    window.close();
            }

            // clear the window with black color
            window.clear(sf::Color::White);

            // draw everything here...
            // window.draw(...);
            window.draw(text);
            // end the current frame
            window.display();
        }
        return 0;
    }q