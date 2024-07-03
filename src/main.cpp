#include "main.h"

#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char **argv)
{
  cout << "Hello, World!" << endl;

  int i = 0;
  while (i < 5)
  {
    cout << "Hello, " << i << "!" << endl;
    i++;
  }

  return EXIT_SUCCESS;
}
