#include "Vector2d.h"
#include <math.h>
#include <iostream>
Vector2d::Vector2d()
{
    x = 0;
    y = 0;
}
Vector2d::Vector2d(float x, float y)
{
    this->x = x;
    this->y = y;
}
Vector2d Vector2d::operator+(Vector2d other)
{
    Vector2d newVector;
    newVector.x = x + other.x;
    newVector.y = y + other.y;
    return newVector;
}

Vector2d Vector2d::operator-(Vector2d other)
{
    Vector2d newVector;
    newVector.x = x - other.x;
    newVector.y = y - other.y;
    return newVector;
}

Vector2d Vector2d::operator+=(Vector2d other)
{
    return Vector2d(x += other.x, y += other.y);
}

Vector2d Vector2d::operator-=(Vector2d other)
{
    return Vector2d(x -= other.x, y -= other.y);
}

Vector2d Vector2d::operator=(Vector2d other)
{
    x = other.x;
    y = other.y;
    return Vector2d(x , y);
}

bool Vector2d::operator==(Vector2d other)
{
    if (x == other.x && y == other.y)return true;
    return false;
}

Vector2d Vector2d::operator*(float a)
{
    return Vector2d(x * a, y * a);
}
Vector2d Vector2d::operator/(float a)
{
    return Vector2d(x / a, y / a);
}

Vector2d Vector2d::operator*=(float a)
{
    return Vector2d(x *= a, y *= a);
}

float Vector2d::Dot(Vector2d other)
{
    return x*other.x + y *other.y;
}

float Vector2d::getMagnitude()
{
    return sqrt((x*x)+(y*y));
}

Vector2d Vector2d::getNormalized()
{
    float m = getMagnitude();
    return Vector2d(x/m , y/m);
}

void Vector2d::normalize()
{
    float m = getMagnitude();
    x /= m;
    y /= m;
}

Vector2d::operator Vector2f()
{
    Vector2f newvertor;
    newvertor.x = x;
    newvertor.y = y;
    return newvertor;

}

Vector2d Vector2d::getNormal()
{
    return Vector2d(-y , x);
}

void Vector2d::print()
{
    std::cout << "x = " << x << "y = " << y;
}


