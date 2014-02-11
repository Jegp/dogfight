#ifndef VECTOR_H
#define VECTOR_H
/**
 * (Yet another) Vector class.
 */
struct Vector {
  const float x, y;

  Vector();
  Vector(float x, float y);
  Vector operator+(const Vector *other);
  Vector operator*(float scalar);
};
#endif
