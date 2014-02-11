#include "Vector.h"

Vector::Vector(float x, float y) : x(x), y(y) {}

Vector Vector::operator+(const Vector *other) {
  Vector result(other->x, other->y);
  return result;
}

Vector Vector::operator*(float scalar) {
  Vector result(x * scalar, y * scalar);
  return result;
}
