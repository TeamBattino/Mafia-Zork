#include "main.h"
#include "game.h"
#include "town.h"
#include <iostream>
#include <string>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
using std::cout;
using std::endl;

int main(int argc, char **argv)
{
  cout << "Hello, World!" << endl;
  using namespace ftxui;

  // Define the document
  Element document =
      hbox({
          text("left") | border,
          text("middle") | border | flex,
          text("right") | border,
      });

  auto screen = Screen::Create(
      Dimension::Full(),       // Width
      Dimension::Fit(document) // Height
  );
  Render(screen, document);
  screen.Print();

  Town town = Town();
  town.dothing();
  Town town2 = Town("Town2", 100);
  town2.dothing();

  Game game = Game();
  game.run();

  return EXIT_SUCCESS;
}
