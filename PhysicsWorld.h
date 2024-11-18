#pragma once
#include "Particle.h"
#include <list>

using namespace std;

class PhysicsWorld
{
private:
	vector<Particle*> particles;
public:
	void addParticle(Particle* particle);
	void Update(float deltaTime);
	void checkCollision();
	static const Vector2d gravity;
};
