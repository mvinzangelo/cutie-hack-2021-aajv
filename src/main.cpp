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
  // LOG("hello world.");
  sf::RenderWindow window(sf::VideoMode::getDesktopMode(),
   "SFML window",
    sf::Style::Fullscreen);  
  window.setFramerateLimit(60);

  sf::Texture texture;
  texture.loadFromFile("me.png");
  sf::Sprite sprite(texture);

  sf::View view;
  view.setCenter(0.f, 0.f);

  // Initialize the view to a rectangle located at (100, 100) and with a size of 400x200
  //view.reset(sf::FloatRect(100, 100, 400, 200));
  // Rotate it by 45 degrees
  //view.rotate(45);
  // Set its target viewport to be half of the window
  //view.setViewport(sf::FloatRect(0.f, 0.f, 0.5f, 1.f));
  // Apply it
  //window.setView(view);

  while (window.isOpen()) {
    sf::Event event; 
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) 
        window.close();
      if (event.type == sf::Event::MouseButtonPressed) {
        LOG("mouse");
        view.rotate(5.f);
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        view.move(0.f, 10.f);
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        view.move(10.f, 0.f);
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        view.move(0.f, -10.f);
      } 
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        view.move(-10.f, 0.f);
      }  // catch the resize events
      if (event.type == sf::Event::Resized) {
          // update the view to the new size of the window
          sf::FloatRect visibleArea(0.f, 0.f, event.size.width, event.size.height);
          window.setView(sf::View(visibleArea));
      }
    }
    window.setView(view);
    window.clear();
    window.draw(sprite);
    window.display();
  }

  return 0;
}