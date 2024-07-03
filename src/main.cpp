#include "main.h"
#include "game.h"
#include <iostream>
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

  Game game = Game();
  game.run();

  return EXIT_SUCCESS;
}
