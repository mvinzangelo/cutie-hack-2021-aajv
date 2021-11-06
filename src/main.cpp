#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

#define DEBUG 1

#if DEBUG
  #define LOG(x) (cout << x << endl)
#else
  #define LOG(x) 
#endif


int main() {
  LOG("hello world.");
  sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "SFML window", sf::Style::Fullscreen);
  window.setFramerateLimit(60);
  sf::Texture texture;
  texture.loadFromFile("me.png");
  sf::Sprite sprite(texture);
  while (window.isOpen()) {
    sf::Event event; 
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) 
        window.close();
      else if (event.type == sf::Event::MouseButtonPressed)
        LOG("mouse");
    }
    window.clear(); 
    window.draw(sprite);
    window.display();
  }
  return 0;
}