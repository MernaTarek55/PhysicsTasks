#include "Collider.h"

bool Collider::checkCollision(Collider other)
{
	return (other.center - center).getMagnitude() < (other.r + r);
}
