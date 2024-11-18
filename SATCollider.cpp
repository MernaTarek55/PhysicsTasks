#include "SATCollider.h"

void SATCollider::updatePosition(Vector2d position)
{
	Vector2d delta =   position - this->position;
	for (int i = 0; i < points.size(); i++) {
		points[i] += delta;
	}
	this->position = position;
}



bool SATCollider::checkCollision(SATCollider other)
{
	vector<Vector2d> normals = this->getNormals();
	vector<Vector2d> n = other.getNormals();
	normals.insert(normals.end(), n.begin(), n.end());
	
	for (int i = 0; i < normals.size(); i++) {
		Vector2d othershape = other.projectShape(normals[i]);
		Vector2d shape = projectShape(normals[i]);
		if (shape.x > othershape.y || shape.y < othershape.x)return false;
	}
	/*normals = other.getNormals();
	for (int i = 0; i < normals.size(); i++) {
		Vector2d othershape = other.projectShape(normals[i]);
		Vector2d shape = projectShape(normals[i]);
		if (shape.x > othershape.y || shape.y < othershape.x)return false;
	}*/
	return true;
}

vector<Vector2d> SATCollider::getNormals()
{
	vector<Vector2d> normals;
	for (int i = 0; i < points.size() - 1; i++) {
		normals.push_back((points[i + 1] - points[i]).getNormal());
	}
	normals.push_back((points[0] - points[points.size() - 1]).getNormal());
	return normals;
}

Vector2d SATCollider::projectShape(Vector2d axis)
{
	float x = points[0].Dot(axis);
	float mn=x, mx=x;
	for (int i = 0; i < points.size(); i++) {
		x = points[i].Dot(axis);
		if (x < mn)mn = x;
		if (x > mx)mx = x;
	}
	return Vector2d(mn, mx);
}
