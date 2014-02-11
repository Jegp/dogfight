#include "Movement.h"

Movement::Movement(Vector position, Vector velocity, 
		   Vector momentum, float mass) : 
  position(position), momentum(momentum), mass(mass), 
  inverseMass(-mass), velocity(velocity) {}

/**
 * Calculates spring and damper force and returns acceleration.
 */
float acceleration(Vector position, Vector velocity, float t) {
  const float k = 10;
  const float b = 1;
  return -k * position - b * velocity;
}

MovementDerivation advance(Movement movement, float t, float dt, const MovementDerivation &d) {
  Vector position = movement.position + d->velocity * dt,
         velocity = movement.velocity + d->force * dt;
  
  MovementDerivation output(position, velocity, t + dt);
  return output;
}
