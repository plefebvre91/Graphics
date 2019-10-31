/* Copyright 2019 Pierre Lefebvre

Permission is hereby granted, free of charge, to any person obtaining a copy 
of this software and associated documentation files (the "Software"), to
deal in the Software without restriction, including without limitation the 
rights to use, copy, modify, merge, publish, distribute, sublicense, and/or 
sell copies of the Software, and to permit persons to whom the Software is 
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in 
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
DEALINGS IN THE SOFTWARE. */

#include "square.hpp"
#include <iostream>

square::square(sf::Vector2f center, float size):
  _center(center), _size(size) {}


void square::draw(sf::RenderWindow& window)
{
  sf::Vector2u ws(window.getSize());
  sf::Vector2f size(_size*(float)ws.x, _size*(float)ws.y);

  sf::Vector2f position;
  position.x = (_center.x * (float)ws.x/2  + ws.x/2) - size.x/2;
  position.y = (_center.y * (float)ws.y/2  + ws.y/2) - size.y/2;

  sf::RectangleShape rectangle;
  rectangle.setPosition(position);
  rectangle.setSize(size);
  rectangle.setFillColor(sf::Color(200, 200, 200));

  window.draw(rectangle);
}
