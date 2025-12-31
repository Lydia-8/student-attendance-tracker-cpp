#include "validation.h"
#include <iostream>
#include <string>
using namespace std;

// get integer input between min and max
int getInt(string prompt, int min, int max) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail() || value < min || value > max) {
            cin.clear();            // clear error
            cin.ignore(1000, '\n'); // discard input
            cout << "Invalid input. Try again.\n";
        } else {
            cin.ignore(1000, '\n'); // remove leftover newline
            return value;
        }
    }
}

string getString(string prompt) {
    string input;
    while (true) {
        cout << prompt;
        getline(cin, input);

        if (!input.empty()) {
            return input;
        }
        cout << "Input cannot be empty. Try again.\n";
    }
}
