#include "application.hpp"

application::application():
  _window(sf::VideoMode(800, 600), "SFML window"),
  _image()
{
  _image.create(800, 600, sf::Color(0,0,0));
}

void application::run()
{
  // process image
  process();

  sf::Texture texture;
  texture.loadFromImage(_image);
  sf::Sprite sprite(texture);
  
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

    // draw image
    _window.draw(sprite);
    
    // end the current frame
    _window.display();
  }
}
