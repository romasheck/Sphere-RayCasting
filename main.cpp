#include "DrowScene.hpp"
#include <iostream>

int main()
{
    PRINT_LINE
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Window with smth...");//need global 
    PRINT_LINE
    std::vector<sf::RectangleShape> pixels = MakePixels({255, 255, 255, 55});
    PRINT_LINE
    scene_objs::Sphere sphere(scene_objs::Point{0,0,0}, X_LIM);
    PRINT_LINE
    Light_t Light({400, 400, 400}, sf::Color::White);
    SpherInPixels(&pixels, sphere, Light);
    PRINT_LINE
    CycleDrowing(&pixels, &window);

    return 0;
}