#include "main.h"
#include "game.h"

#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char **argv)
{
  cout << "Hello, World!" << endl;

  Game game = Game();
  game.run();

  return EXIT_SUCCESS;
}
