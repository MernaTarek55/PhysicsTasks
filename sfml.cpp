#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "Renderer.h"
#include "PhysicsWorld.h"
#include "SATCollider.h"


int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "physics");
	sf::CircleShape shape(20);
	sf::CircleShape dshape1(5);
	sf::CircleShape dshape2(5);
	sf::ConvexShape debugshape(4),debugshape1(4);
	debugshape.setFillColor(sf::Color::Color(255, 0, 0, 100));
	debugshape1.setFillColor(sf::Color::Color(255, 0, 0, 100));
	shape.setOrigin(20, 20);
	dshape1.setOrigin(2.5, 2.5);
	dshape2.setOrigin(2.5, 2.5);
	shape.setFillColor(sf::Color::Cyan);
	sf::CircleShape shape2(20);
	shape2.setOrigin(20, 20);
	shape2.setFillColor(sf::Color::Red);
	sf::RectangleShape rectShape1(Vector2f(40, 40));
	sf::RectangleShape rectShape2(Vector2f(40, 40));
	Renderer renderer;
	/*
	renderer.AddDrawable(&shape);
	renderer.AddDrawable(&shape2);*/
	renderer.AddDrawable(&rectShape1);
	renderer.AddDrawable(&rectShape2);
	renderer.AddDrawable(&debugshape);
	renderer.AddDrawable(&debugshape1);
	renderer.AddDrawable(&dshape1);
	renderer.AddDrawable(&dshape2);
	rectShape1.setPosition(Vector2f(200, 200));
	rectShape2.setPosition(Vector2f(300, 300));

	rectShape1.setFillColor(sf::Color::Blue);
	rectShape2.setFillColor(sf::Color::Yellow);



	

	PhysicsWorld world;
	/*Particle particle{ Vector2d(20, 20) };
	Particle particle2{ Vector2d(60, 60) };*/

	Particle particle3{ Vector2d(rectShape1.getPosition().x,rectShape1.getPosition().y) };
	Particle particle4{ Vector2d(rectShape2.getPosition().x,rectShape2.getPosition().y)};
	//particle.velocity = Vector2d(20, 20);

	//particle.addForce(Vector2d(60000, 60000));
	//particle2.addForce(Vector2d(40000, 40000));

	particle3.addForce(Vector2d(60000, 60000));
	particle4.addForce(Vector2d(-40000, -40000));


	sf::Clock clock;
	float dt = 0;
	float time = 0;
	//world.addParticle(&particle);
	//world.addParticle(&particle2);
	world.addParticle(&particle3);
	world.addParticle(&particle4);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		dt = clock.getElapsedTime().asSeconds() - time;
		time += dt;
		world.Update(dt);
		world.checkCollision();
		for (int i = 0; i < 4; i++)
		{
			debugshape.setPoint(i, particle3.SATcollider.points[i]);
			debugshape1.setPoint(i, particle4.SATcollider.points[i]);
		}
		dshape1.setPosition(particle3.aabbcollider.ul);
		dshape2.setPosition(particle3.aabbcollider.lr);
		//shape.setPosition((Vector2f)particle.postion);
		//shape2.setPosition((Vector2f)particle2.postion);
		rectShape1.setPosition((Vector2d)particle3.postion);
		rectShape2.setPosition((Vector2d)particle4.postion);
		renderer.Render(&window);
	}

	return 0;
}
