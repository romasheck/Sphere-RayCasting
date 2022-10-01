#include "libDrow.hpp"

sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Window with smth...");

Color Color::operator + (Color term)
{
    return Color{CorrectSum(term.R(), R()), CorrectSum(term.G(), G()),CorrectSum(term.B(), B())};
}

Color Color::operator * (Color factor)
{
    return Color{CorrectMul(R(), factor.R()), CorrectMul(G(), factor.G()), CorrectMul(B(), factor.B())};
}

Color Color::operator * (double coef)
{
    //printf("in func oper _%f_\n", coef);
    return Color{CorrectMulC(R(), coef), CorrectMulC(G(), coef), CorrectMulC(B(), coef)};
}

int FillInPixels (Color color, std::vector<Pixel>* pixels)
{
    for (uint32_t i = 0 ; i < PIXELS_AMOUNT ; i++)
    {
        Pixel pixel{{i % WIDTH, i / WIDTH}, color};
        pixels->push_back(pixel);
    }

    return 0;
}

int CycleDrowing (const std::vector<Pixel> *pixels)
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        for (const auto& pixel : *pixels)
        {
            window.draw(pixel.pixel_);
        }
        
        window.display();
        
    }

    return 0;
}