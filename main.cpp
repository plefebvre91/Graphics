#include "application.hpp"
#include "menger.hpp"

int main(int argc, char** argv)
{
  application* app = new menger();
  app->run();

  return 0;
}
