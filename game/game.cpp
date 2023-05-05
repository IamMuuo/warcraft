#include "game.hpp"
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>

Game::Game()
  : mWindow(sf::VideoMode(800, 600),"Warcraft", sf::Style::Close)
{
  mWindow.setVerticalSyncEnabled(true);
  mWindow.setFramerateLimit(60);
}

void Game::render() {
  // clear the previous frame
  mWindow.clear();

  // draw sprites and other stuff

  // display onto the screen
  mWindow.display();
}

void Game::update() {
  ;
}

void Game::process() {
  // Process key events
  sf::Event event;

  while (mWindow.pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      mWindow.close();
    }
  }
}

void Game::run() {
  while (mWindow.isOpen()) {
    process();
    update();
    render();
  }
}
