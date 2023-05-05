#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


class Game {
  public:
    Game();
    void run();

  private:
    void update();
    void render();
    void process();

    sf::RenderWindow mWindow;
};
