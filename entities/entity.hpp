/*
 * The base class entity
 */
#pragma once
#include <SFML/Window.hpp>

class Entity{
  public:
    void setVelocity(sf::Vector2f velocity);
    void setVelocity(float x, float y);

    sf::Vector2f getVelocity() const;

  private:
    sf::Vector2f mVelocity;
};
