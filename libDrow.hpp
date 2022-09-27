#ifndef LIBDROW_H_INCLUDED
#define LIBDROW_H_INCLUDED

#include <SFML/Graphics.hpp>

enum WindowParameters
{
    WIDTH = 800,
    HEIGHT = 800,
    PIXELS_AMOUNT = WIDTH*HEIGHT
};

sf::RenderWindow*                   OpenWindow      ();

sf::RectangleShape                  addPixel        (sf::Vector2f position, sf::Color color);//create pixel

std::vector<sf::RectangleShape>     MakePixels      (sf::Color color);

int                                 CycleDrowing    (const std::vector<sf::RectangleShape> *pixels, sf::RenderWindow *window);

#endif