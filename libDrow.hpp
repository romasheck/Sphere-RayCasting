#ifndef LIBDROW_H_INCLUDED
#define LIBDROW_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "CorrectOp.hpp"


enum WindowParameters
{
    WIDTH = 800,
    HEIGHT = 800,
    PIXELS_AMOUNT = WIDTH*HEIGHT
};

class Color
{
    sf::Color color_;

    public:

    Color(uint8_t R, uint8_t G, uint8_t B): color_{R, G, B, 255} {};
    Color(uint8_t R, uint8_t G, uint8_t B, uint8_t A): color_{R, G, B, 255} {};
    Color(sf::Color color): color_(color) {};
    ~Color() {};

    uint8_t R() {return color_.r;}
    uint8_t G() {return color_.g;}
    uint8_t B() {return color_.b;}
    uint8_t A() {return color_.a;}

    sf::Color color() {return color_;}

    Color operator + (Color term);
    Color operator * (Color factor);

    Color operator * (double coef);
};

#define WHITE           Color{sf::Color::White}
#define RED             Color{sf::Color::Red}
#define BLACK           Color{sf::Color::Black}
#define GREEN           Color{sf::Color::Green}
#define BLUE            Color{sf::Color::Blue}

struct Pos
{
    float column;
    float line;
};

struct Pixel
{
    sf::RectangleShape pixel_;

    Pixel(Pos pos, Color color)
    {
        sf::Vector2f position;
        position.x = pos.column;
        position.y = pos.line;

        pixel_.setSize ({1.f, 1.f});
        pixel_.setFillColor(color.color());
        pixel_.setPosition(position);
    }

    ~Pixel() {};

    Pos Position () {return {pixel_.getPosition().x, pixel_.getPosition().y};}

    void setColor(Color color) {pixel_.setFillColor(color.color());}
};

sf::RenderWindow*                   OpenWindow      ();

//sf::RectangleShape                  addPixel        (sf::Vector2f position, sf::Color color);//create pixel

int                                 FillInPixels      (Color color, std::vector<Pixel> *pixels);

int                                 CycleDrowing    (const std::vector<Pixel> *pixels);

#endif