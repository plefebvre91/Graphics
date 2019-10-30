#ifndef _SIERPINSKI_HPP_
#define _SIERPINSKI_HPP_

#include "application.hpp"



class square
{
public:
  void draw(sf::RenderWindow& window)
  {
    sf::RectangleShape rectangle(sf::Vector2f(120.f, 50.f));
    rectangle.setFillColor(sf::Color(0, 0, 250));
    rectangle.setSize(sf::Vector2f(100.f, 100.f));
    window.draw(rectangle);
  }
private:
  //  sf::Point center;
  double size;
};

class squares
{
public:
  squares()
  {
    _s.push_back(square());
  }
  void add_one_step()
  {
    return;
  }
  void draw(sf::RenderWindow& window)
  {
    for(auto s: _s)
      s.draw(window);
  }
private:
  std::vector<square> _s;
};



class sierpinski : public application
{
public:
  sierpinski();
  void process(void);
  void draw(void);
private:
  squares _squares;

};

#endif
