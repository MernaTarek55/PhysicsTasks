#include "PhysicsWorld.h"

void PhysicsWorld::addParticle(Particle* particle)
{
	particles.push_back(particle);
}

void PhysicsWorld::Update(float deltaTime)
{
	for (Particle* it : particles) {
		it->Update(deltaTime);
	}
}

void PhysicsWorld::checkCollision()
{
	for (int i = 0; i < particles.size()-1; i++) {
		Particle* it = particles[i];
		for (int j = i + 1; j < particles.size(); j++) {
			Particle* itt = particles[j];
				//if (it->collider.checkCollision(itt->collider))cout << "Collision" << endl;
				//if(it->SATcollider.checkCollision(itt->SATcollider))cout << "Collision" << endl;
				if (it->aabbcollider.checkCollision(itt->aabbcollider)) {
					cout << "Collision" << endl;
					float massTotal = it->mass + itt->mass;
					Vector2d temp = it->velocity ;
					it->velocity.x = ((it->mass - itt->mass) / massTotal) + 2 * (itt->mass / massTotal) * itt->velocity.x;
					it->velocity.y = ((it->mass - itt->mass) / massTotal) + 2 * (itt->mass / massTotal) * itt->velocity.y;
					itt->velocity.x = ((itt->mass - it->mass) / massTotal) + 2 * (it->mass / massTotal) * temp.x;
					itt->velocity.y = ((itt->mass - it->mass) / massTotal) + 2 * (it->mass / massTotal) * temp.y;
				}
		}
	}
}
