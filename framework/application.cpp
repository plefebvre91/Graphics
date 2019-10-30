#include "application.hpp"

application::application():
  _window(sf::VideoMode(800, 600), "SFML window"){}

void application::run()
{
  // process image
  process();

  while (_window.isOpen())
  {
    sf::Event event;
    while (_window.pollEvent(event))
    {
      // "close requested" event: we close the _window
      if (event.type == sf::Event::Closed)
	_window.close();
    }
    
    // clear the _window with black color
     _window.clear(sf::Color::Black);

     // draw graphical elements
     draw();
    
    // end the current frame
    _window.display();
  }
}
