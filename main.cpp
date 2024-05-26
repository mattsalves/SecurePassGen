#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Function to generate a strong password
string generatePassword(int length, bool useSpecialCharacters, bool useSpacing) {
    string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    if (useSpecialCharacters) {
        characters += "!@#$%^&*()-_+=~`[]{}|;:,.<>?";
    }

    if (useSpacing) {
        characters += " ";
    }

    string password;
    int charactersSize = characters.size();
    srand(time(nullptr));
    for (int i = 0; i < length; ++i) {
        password += characters[rand() % charactersSize];
    }

    return password;
}

int main() {
    int length;
    bool useSpecialCharacters, useSpacing;

    // Question 1: Password length
    cout << "How many characters do you want your password to have? (Recommendation: more than 10 characters): ";
    cin >> length;

    // Question 2: Use special characters
    char response;
    cout << "Can we use special characters? (y/n): ";
    cin >> response;
    useSpecialCharacters = (response == 'y' || response == 'Y');

    // Question 3: Use spacing between characters
    cout << "Can we use spacing between characters? (y/n): ";
    cin >> response;
    useSpacing = (response == 'y' || response == 'Y');

    // Generate password
    string password = generatePassword(length, useSpecialCharacters, useSpacing);

    // Print password
    cout << "Your generated strong password is: " << password << endl;

    return 0;
}
