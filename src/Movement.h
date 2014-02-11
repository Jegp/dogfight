#ifndef MOVEMENT_H
#define MOVEMENT_H
#include "Vector.h"

/**
 * A struct representing the state of the movement of an object.
 */
struct Movement {
  const Vector velocity, position, momentum;

  const float mass, inverseMass;

  Movement(Vector position, Vector velocity, Vector momentum, float mass);
};

/**
 * A derivation of the movement struct with precalculated values.
 */ 
struct MovementDerivation {
  const Vector velocity, force;
};

MovementDerivation advance(Movement movement, float t, float dt, 
			   const MovementDerivation &d);
float acceleration(Movement movement, float t);

#endif
