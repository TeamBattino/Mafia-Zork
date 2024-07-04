#include <iostream>
#include "ftxui/component/captured_mouse.hpp"     // for ftxui
#include "ftxui/component/component.hpp"          // for Input, Renderer, Vertical
#include "ftxui/component/component_base.hpp"     // for ComponentBase
#include "ftxui/component/component_options.hpp"  // for InputOption
#include "ftxui/component/screen_interactive.hpp" // for Component, ScreenInteractive
#include "ftxui/dom/elements.hpp"                 // for text, hbox, separator, Element, operator|, vbox, border
#include "ftxui/util/ref.hpp"                     // for Ref
#include <string>
#include "io.h"

using namespace ftxui;
using namespace std;

void UI::render()
{
    std::string input;

    auto input_component = Input(&input, "Enter text");

    auto component = Container::Vertical({Renderer([&]
                                                   { return vbox({text("History:") | bold,
                                                                  paragraph(history) | border,
                                                                  text("Input:") | bold,
                                                                  input_component->Render() | hbox}); }),
                                          input_component});

    auto screen = ScreenInteractive::Fullscreen();

    screen.Loop(component);
}

void UI::Write(const string &new_data)
{
    history += new_data;
}
