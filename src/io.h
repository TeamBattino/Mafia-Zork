#pragma once

using namespace std;

class UI
{
private:
    string history = "";

public:
    static void render();
    void Write(const string &new_data);
};