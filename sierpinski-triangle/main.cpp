#include "application.hpp"
#include "sierpinski_triangle.hpp"

int main(int argc, char** argv)
{
  application* app = new sierpinski_triangle();
  app->run();

  return 0;
}
