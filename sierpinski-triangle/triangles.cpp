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

#include "triangles.hpp"

triangles::triangles()
{
  _s.push_back(new triangle(sf::Vector2f(0.5, 0.8),
			    sf::Vector2f(0.9, 0.1),
			    sf::Vector2f(0.1, 0.1)));
}


void triangles::add_one_step()
{
  std::vector<triangle*> tmp(_s);

  _s.clear();

  for(auto e: tmp)
  {
    sf::Vector2f new_vertices[3];
    new_vertices[0] = (e->_vertices[0].position + e->_vertices[1].position) / (float)2.0;
    new_vertices[1] = (e->_vertices[1].position + e->_vertices[2].position) / (float)2.0;
    new_vertices[2] = (e->_vertices[0].position + e->_vertices[2].position) / (float)2.0;

    _s.push_back(new triangle(e->_vertices[0].position, new_vertices[0], new_vertices[2]));
    _s.push_back(new triangle(e->_vertices[1].position, new_vertices[0], new_vertices[1]));
    _s.push_back(new triangle(e->_vertices[2].position, new_vertices[1], new_vertices[2]));

    delete e;
  }
}

void triangles::draw(sf::RenderWindow& window)
{
  for(auto s: _s)
    s->draw(window);
}


triangles::~triangles()
{
  for(auto s: _s)
    delete s;
}
