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

#include "triangle.hpp"


triangle::triangle(sf::Vector2f x, sf::Vector2f y, sf::Vector2f z):
  _vertices(3)
{
  _vertices[0].position = x;
  _vertices[1].position = y;
  _vertices[2].position = z;

  for(auto v: _vertices)
  {
    v.color = sf::Color::White;
  }
}


void triangle::draw(sf::RenderWindow& window)
{
  sf::Vector2u ws(window.getSize());

  std::vector<sf::Vertex> points(_vertices);

  for(auto& p: points)
  {
      p.position.x *= (float)ws.x;
      p.position.y *= (float)ws.y;
  }
  
  window.draw(points.data(), 3, sf::Triangles);
}
