#include "game.h"
#include <iostream>
#include <sstream>
#include <ftxui/dom/elements.hpp>  // for color, Fit, LIGHT, align_right, bold, DOUBLE
#include <ftxui/dom/table.hpp>     // for Table, TableSelection
#include <ftxui/screen/screen.hpp> // for Screen
#include <iostream>                // for endl, cout, ostream
#include <string>                  // for basic_string, allocator, string
#include <vector>                  // for vector
#include "ftxui/dom/node.hpp"      // for Render
#include "ftxui/screen/color.hpp"  // for Color, Color::Blue, Color::Cyan, Color::White, ftxui

Game::Game()
{
    cout << "Default Game Constructor" << endl;
    towns.push_back(Town("Town1", 100));
    towns.push_back(Town("Town2", 200));
    towns.push_back(Town("Town3", 300));
    active_town = 0;
}

void Game::run()
{
    while (true)
    {
        get_command();
    }
}

void Game::get_command()
{
    string command;
    cout << "\033[1;32m❯ \033[0m";
    cin >> command;
    // split the command at " " into a vector<String>
    handle_command(command);
}

void Game::handle_command(string command)
{

    if (command == "quit")
    {
        exit(0);
    }
    else if (command == "stats")
    {
        print_status();
    }
    else
    {
        cout << "Invalid Command" << endl;
    }
}

void Game::print_status()
{
    using namespace ftxui;

    auto table = Table({
        {"Name", "Population", "Influence", "Balance"},
        {towns[0].name, to_string(towns[0].population), to_string(towns[0].influence), "CHF " + to_string(player.get_balance())},
    });

    table.SelectAll().Border(LIGHT);

    // Add border around the first column.
    table.SelectColumn(0).Border(LIGHT);

    // Make first row bold with a double border.
    table.SelectRow(0).Decorate(bold);
    table.SelectRow(0).SeparatorVertical(LIGHT);
    table.SelectRow(0).Border(DOUBLE);

    // Align right the "Release date" column.
    table.SelectColumn(2).DecorateCells(align_right);

    // Select row from the second to the last.
    auto content = table.SelectRows(1, -1);
    // Alternate in between 3 colors.
    content.DecorateCellsAlternateRow(color(Color::Blue), 3, 0);
    content.DecorateCellsAlternateRow(color(Color::Cyan), 3, 1);
    content.DecorateCellsAlternateRow(color(Color::White), 3, 2);

    auto document = table.Render();
    auto screen = Screen::Create(Dimension::Fit(document));
    Render(screen, document);
    screen.Print();
    std::cout << std::endl;
}