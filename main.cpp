#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "player.h"
#include "Brick.h"
#include <vector>

double mapValue(double x, double a, double b, double c, double d) {
	double y = (x - a) / (a - b) * (c - d) + c;
	return y;
}
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int BRICKS_PER_ROW = 10;
const int NUM_ROWS = 5;
const int BRICK_SPACING = 10;
const int BRICKS_TOP_MARGIN = 50;

int main(int argc, char** argv)
{
	Player player(500, 100, 20);

	Ball ball(200, 250, 10, 500);
	sf::RenderWindow window(sf::VideoMode(800, 600), "Jeu de casse-brique");

	sf::RectangleShape rdr2;
	rdr2.setSize(sf::Vector2f(window.getSize().x, 1));


	sf::Clock clock;
	sf::Vector3f xFactor(10, 20, 30);
	float ellapsedTime = 0;

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

	while (window.isOpen())
	{
		ellapsedTime = clock.restart().asSeconds();

		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();

		}

		ball.move(ellapsedTime);
		ball.manageCollisionWith(window);

		window.clear();

		for (int i = 0; i < window.getSize().y; i++)
		{
			double mappedValue = mapValue(i, 0, window.getSize().y, 0, 255);
			rdr2.setFillColor(sf::Color(mappedValue, mappedValue, 190));
			rdr2.setPosition(0, i);
			window.draw(rdr2);
		}

		// Dessiner les briques
		for (Brick& brick : bricks)
		{
			brick.draw(window);
		}

		//window.draw(rectangle);
		//window.draw(circle);
		ball.draw(window);
		player.draw(window);
		window.display();
	}


	return 0;
}
