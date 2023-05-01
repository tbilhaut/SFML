#include <SFML/Graphics.hpp>
#include "Ball.h"
/*
double mapValue(double value, double min, double max, double nMin, double nMax) 
{
	double newVal = ((value - min) / (max - min) * (nMax - nMin)) + nMin;
	return newVal;
		
}

int main(int argc, char **argv)
{
	Ball ball(200, 250, 10, 1500);
	sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(100, 50));
	rectangle.setFillColor(sf::Color::Cyan);
	rectangle.setOutlineColor(sf::Color::Magenta);
	rectangle.setOutlineThickness(2);
	rectangle.setPosition(100, 100);
	
	sf::CircleShape circle;
	circle.setRadius(10);
	circle.setPosition(200, 170);
	circle.setFillColor(sf::Color::Cyan);
	circle.setOutlineColor(sf::Color::Magenta);
	circle.setOutlineThickness(2);

	sf::RectangleShape rdr2;
	rdr2.setSize(sf::Vector2f(window.getSize().x, 1));
	
	sf::Clock clock;
	sf::Vector3f xFactor(10, 20, 30);
	float ellapsedTime = 0;

	// on fait tourner le programme jusqu'à ce que la fenêtre soit fermée
	while (window.isOpen())
	{
		ellapsedTime = clock.restart().asSeconds();
		// on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
		sf::Event event;
		while (window.pollEvent(event))
		{
			// évènement "fermeture demandée" : on ferme la fenêtre
			if (event.type == sf::Event::Closed)
				window.close();
		}

		ball.move(ellapsedTime);
		ball.manageCollisionWith(window);

		window.clear();

		for (int i = 0; i < window.getSize().y; i++) {
			double mappedValue = mapValue(i, 0, window.getSize().y, 0, 255);
			rdr2.setFillColor(sf::Color(mappedValue, mappedValue, 0));
			rdr2.setPosition(0, i);
			window.draw(rdr2);
		}

		window.draw(rectangle);
		window.draw(circle);
		ball.draw(window);
		window.display();
	}

	return 0;
}
*/
#include <SFML/Graphics.hpp>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

const int BRICKS_PER_ROW = 10;
const int NUM_ROWS = 5;
const int BRICK_WIDTH = 70;
const int BRICK_HEIGHT = 30;
const int BRICK_SPACING = 10;
const int BRICKS_TOP_MARGIN = 50;

class Brick
{
public:
	sf::RectangleShape shape;
	bool destroyed;

	Brick(float x, float y)
	{
		shape.setPosition(x, y);
		shape.setSize(sf::Vector2f(BRICK_WIDTH, BRICK_HEIGHT));
		shape.setFillColor(sf::Color::Green);
		shape.setOrigin(BRICK_WIDTH / 2.f, BRICK_HEIGHT / 2.f);
		destroyed = false;
	}
};

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Casse-briques");

	std::vector<Brick> bricks;

	// Ajouter les briques à l'écran
	for (int i = 0; i < NUM_ROWS; ++i)
	{
		for (int j = 0; j < BRICKS_PER_ROW; ++j)
		{
			float x = (j + 0.5f) * (BRICK_WIDTH + BRICK_SPACING);
			float y = BRICKS_TOP_MARGIN + i * (BRICK_HEIGHT + BRICK_SPACING);
			bricks.emplace_back(x, y);
		}
	}

	// Boucle principale
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		// Dessiner les briques
		for (const Brick& brick : bricks)
		{
			if (!brick.destroyed)
			{
				window.draw(brick.shape);
			}
		}

		window.display();
	}

	return 0;
}
