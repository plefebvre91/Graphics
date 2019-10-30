#include "application.hpp"
#include "sierpinski.hpp"

int main(int argc, char** argv)
{
  application* app = new sierpinski();
  app->run();

  return 0;
}
