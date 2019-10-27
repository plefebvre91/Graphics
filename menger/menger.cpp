#include "menger.hpp"

void menger::process(void)
{
  for(sf::Uint32 i = 0; i<800; i++)
    for(sf::Uint32 j = 0; j<600; j++)
    {
      int r = (int)((float)i / 800.0 * 255.0);
      int g = (int)((float)i / 800.0 * 255.0);
      _image.setPixel(i,j, sf::Color(r,g,0));
    }
}
