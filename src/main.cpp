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
    Game game;
    game.run();
    return EXIT_SUCCESS;
}
