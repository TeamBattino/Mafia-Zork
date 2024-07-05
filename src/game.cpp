#include "game.h"
#include <iostream>
#include <sstream>
#include <ftxui/dom/elements.hpp>  // for color, Fit, LIGHT, align_right, bold, DOUBLE
#include <ftxui/dom/table.hpp>     // for Table, TableSelection
#include <ftxui/screen/screen.hpp> // for Screen
#include <iostream>                // for endl, cout, ostream
#include <string>                  // for basic_string, allocator, string
#include <vector>                  // for vector
#include <ftxui/dom/node.hpp>      // for Render
#include <ftxui/screen/color.hpp>  // for Color, Color::Blue, Color::Cyan, Color::White, ftxui

Game::Game()
{
    cout << "Default Game Constructor" << endl;
    towns.push_back(Town("Town1", 100, {Drug("Dopamine", 50, 100, 0)}));
    towns.push_back(Town("Town2", 200, {Drug("Dopamine", 50, 100, 0), Drug("Serotonin", 50, 100, 0)}));
    towns.push_back(Town("Town3", 300, {Drug("Dopamine", 50, 100, 0), Drug("Serotonin", 50, 100, 0), Drug("Adrenaline", 50, 100, 0), Drug("Endorphin", 50, 100, 0)}));
    active_town = 0;
}

void Game::run()
{
    while (true)
    {
        string command = get_command();
        handle_base_command(command);
    }
}

string Game::get_command()
{
    string command;
    cout << "\033[1;32m❯ \033[0m";
    cin >> command;
    return command;
}

void Game::handle_base_command(string command)
{

    if (command == "quit")
    {
        exit(0);
    }
    else if (command == "help")
    {
        print_help();
    }
    else if (command == "stats")
    {
        print_stats();
    }
    else if (command == "stock")
    {
        print_stock();
    }
    else if (command == "buy")
    {
        string drug_name;
        int amount;
        cout << "Drug Name: ";
        cin >> drug_name;
        cout << "Amount: ";
        cin >> amount;
        buy_drug(drug_name, amount);
    }
    else if (command == "sell")
    {
        string drug_name;
        int amount;
        cout << "Drug Name: ";
        cin >> drug_name;
        cout << "Amount: ";
        cin >> amount;
        sell_drug(drug_name, amount);
    }
    else if (command == "recruit")
    {
        recruit();
    }
    else
    {
        cout << "Invalid Command" << endl;
    }
}
// Process Functions
void Game::process_round()
{
    // Process the round
    float update_balance = 0;
    for (unsigned long int i = 0; i < towns[active_town].local_drugs.size(); i++)
    {
        if (towns[active_town].local_drugs[i].quantity > 0 && towns[active_town].local_drugs[i].auto_sell)
        {
            towns[active_town].local_drugs[i].quantity--;
            update_balance += towns[active_town].local_drugs[i].sale_price;
        }
    }

    // Update the balance
    this->player.set_balance(this->player.get_balance() + (double)update_balance);
}
// Inventory Managment Functions
void Game::buy_drug(string drug_name, int amount)
{
    int drug_index = towns.at(active_town).get_drug_index(drug_name);
    if (drug_index == -1)
    {
        cout << "Drug not found" << endl;
        return;
    }
    if (towns[active_town].local_drugs[drug_index].purchase_price * amount <= player.get_balance())
    {
        towns[active_town].local_drugs[drug_index].quantity += amount;
        player.set_balance(player.get_balance() - towns[active_town].local_drugs[drug_index].purchase_price * amount);
    }
    else
    {
        cout << "You dont have enough money" << endl;
    }
}

void Game::sell_drug(string drug_name, int amount)
{
    int drug_index = towns.at(active_town).get_drug_index(drug_name);
    if (drug_index == -1)
    {
        cout << "Drug not found" << endl;
        return;
    }
    if (towns[active_town].local_drugs[drug_index].quantity >= amount)
    {
        towns[active_town].local_drugs[drug_index].quantity -= amount;
        player.set_balance(towns[active_town].local_drugs[drug_index].sale_price * amount);
    }
    else
    {
        cout << "You dont have enough drugs" << endl;
    }
}

// Recruit Functions
void Game::recruit()
{
    if (random_by_chance(towns[active_town].reputation / 2))
    {
        towns[active_town].recruits++;
        cout << "Amount of recruits: " << towns[active_town].recruits << endl;
    }
    else
    {
        cout << "Do you want to try and bribe him?" << endl;
        string bribe_choice = get_command();
        if (bribe_choice == "y")
        {
            recruit_bribe(101);
        }
    }
}

bool Game::random_by_chance(int chance)
{
    srand((unsigned)time(0));

    auto test = (rand() % 100) < (chance);
    cout << test << endl;
    return test;
}

void Game::recruit_bribe(int amount)
{
    if (amount >= player.get_balance())
    {
        if (random_by_chance(towns[active_town].reputation / 2))
        {
            player.set_balance(-amount);
            towns[active_town].reputation++;
            towns[active_town].recruits++;

            cout << "Amount of recruits: " << towns[active_town].recruits << endl;
        }
        else
        {
            towns[active_town].reputation--;

            string force_choice;
            cout << "Looks like hes not corrupt. Do you want to force him? (y/n)";
            cin >> force_choice;

            if (force_choice.compare("y") == 0)
            {
                recruit_force();
                towns[active_town].recruits++;
            }
        }
    }
    else
    {
        cout << "Youre broke." << endl;
    }
}

void Game::recruit_force()
{
    towns[active_town].reputation++;
    towns[active_town].influence--;
}

// Print Functions
void Game::print_help()
{
    using namespace ftxui;

    auto avalible_commands = text("Available Commands: ") | bold | color(Color::Blue);
    auto quit = text("quit - Exit the game") | color(Color::White);
    auto help = text("help - Display this message") | color(Color::White);
    auto stats = text("stats - Display the current status") | color(Color::White);
    ftxui::Element separatorHeader = ftxui::separator() | color(Color::White);
    ftxui::Element separator1 = ftxui::separatorDashed() | color(Color::White);
    ftxui::Element separator2 = ftxui::separatorDashed() | color(Color::White);
    auto document = vbox(
                        avalible_commands,
                        separatorHeader,
                        quit,
                        separator1,
                        help,
                        separator2,
                        stats) |
                    border;
    auto screen = Screen::Create(Dimension::Fit(document), Dimension::Fit(document));
    Render(screen, document);
    screen.Print();
    std::cout << std::endl;
}
void Game::print_stock()
{
    using namespace ftxui;

    std::vector<std::vector<std::string>> drugData;
    drugData.push_back({"Name", "Quantity", "Purchase Price", "Sale Price"});
    for (unsigned long int i = 0; i < towns[active_town].local_drugs.size(); i++)
    {
        drugData.push_back({towns[active_town].local_drugs[i].name, std::to_string(towns[active_town].local_drugs[i].quantity), std::to_string(towns[active_town].local_drugs[i].purchase_price), std::to_string(towns[active_town].local_drugs[i].sale_price)});
    }

    auto table = Table(drugData);
    table.SelectAll().Border(LIGHT);
    table.SelectRow(0).Decorate(bold);
    table.SelectColumn(2).DecorateCells(align_right);
    table.SelectColumn(3).DecorateCells(align_right);
    auto document = table.Render();
    auto screen = Screen::Create(Dimension::Fit(document));
    Render(screen, document);
    screen.Print();
    std::cout << std::endl;
}

void Game::print_stats()
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
