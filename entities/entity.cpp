#include "entity.hpp"
#include <SFML/System/Vector2.hpp>

sf::Vector2f Entity::getVelocity() const {
  return mVelocity;
}


void Entity::setVelocity(sf::Vector2f velocity){
  mVelocity = velocity;
}

void Entity::setVelocity(float x, float y){
  mVelocity.x = x;
  mVelocity.y = y;
}
