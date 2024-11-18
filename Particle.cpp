#include "Particle.h"

Particle::Particle(Vector2d postion, float mass, float drag)
{
	this->postion = postion;
	this->mass = mass;
	this->drag = drag;
	forces = Vector2d(0.0f, 0.0f);
	collider.center = Vector2d(20,20);
	collider.r = 20;
	SATcollider.updatePosition(postion);
	SATcollider.points.push_back(postion);
	SATcollider.points.push_back(Vector2d(postion.x+40,postion.y));
	SATcollider.points.push_back(Vector2d(postion.x+40,postion.y + 40));
	SATcollider.points.push_back(Vector2d(postion.x,postion.y + 40));
	aabbcollider.ul = Vector2d(0 ,0);
	aabbcollider.lr = Vector2d(40 ,40);
	aabbcollider.updatePosition(postion);
	

}



void Particle::Update(float dt)
{
	
	this->velocity += (forces / mass)*dt;
	this->postion += velocity * dt;
	collider.center = postion;
	SATcollider.updatePosition(postion);
	aabbcollider.updatePosition(postion);
	forces = Vector2d(0.0f, 0.0f);
}

void Particle::addForce(Vector2d force)
{
	forces += force;
}

