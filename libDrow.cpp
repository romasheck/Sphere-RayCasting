#include "libDrow.hpp"

sf::RectangleShape addPixel(sf::Vector2f position, sf::Color color)
{
    sf::RectangleShape pixel;

    pixel.setSize({ 1.f, 1.f });
    pixel.setFillColor(color);
    pixel.setPosition(position);

    return pixel;
}

std::vector<sf::RectangleShape> MakePixels (sf::Color color)
{
    std::vector<sf::RectangleShape> pixels;

    for (uint32_t i = 0 ; i < PIXELS_AMOUNT ; i++)
    {
        pixels.push_back(addPixel({i % WIDTH, i / WIDTH}, color));
    }

    return pixels;
}

int CycleDrowing (const std::vector<sf::RectangleShape> *pixels, sf::RenderWindow *window)
{
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        window->clear();
        for (const auto& pixel : *pixels)
        {
            window->draw(pixel);
        }
        window->display();
        
    }

    return 0;
}