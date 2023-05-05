#include "Brick.h"

Brick::Brick(float x, float y)
{
    shape.setPosition(x, y);
    shape.setSize(sf::Vector2f(BRICK_WIDTH, BRICK_HEIGHT));
    shape.setFillColor(sf::Color::Green);
    shape.setOrigin(BRICK_WIDTH / 2.f, BRICK_HEIGHT / 2.f);
    destroyed = false;
}

void Brick::draw(sf::RenderWindow& window)
{
    if (!destroyed)
    {
        window.draw(shape);
    }
}

bool Brick::isDestroyed()
{
    return destroyed;
}

void Brick::destroy()
{
    destroyed = true;
}

sf::FloatRect Brick::getBounds()
{
    return shape.getGlobalBounds();
}
