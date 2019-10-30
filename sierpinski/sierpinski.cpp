#include "sierpinski.hpp"

#define SIERPINSKI_STEPS 3

sierpinski::sierpinski()
{
  
}


void sierpinski::process(void)
{
  for(int i=0; i<SIERPINSKI_STEPS; i++)
    _squares.add_one_step();     
}


void sierpinski::draw(void)
{
  _squares.draw(_window);
}
