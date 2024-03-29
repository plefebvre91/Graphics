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

#ifndef _SQUARE_HPP_
#define _SQUARE_HPP_

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

struct square
{
  /**
   * Default constructor
   */
  square() = default;

  /**
   * Constructor, creates the central square
   */
  square(sf::Vector2f center, float size);
  
  /**
   * Draw the square
   */
  void draw(sf::RenderWindow& window);

  /**
   * Square position (between -1 and 1)
   */
  sf::Vector2f _center;

  /**
   * Edge size (between 0 and 1)
   */
  float _size;
};

#endif
