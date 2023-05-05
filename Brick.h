#pragma once

#include <SFML/Graphics.hpp>

const int BRICK_WIDTH = 70;
const int BRICK_HEIGHT = 30;

class Brick
{
public:
    Brick(float x, float y);
    void draw(sf::RenderWindow& window);
    bool isDestroyed();
    void destroy();
    sf::FloatRect getBounds();

private:
    sf::RectangleShape shape;
    bool destroyed;
};
