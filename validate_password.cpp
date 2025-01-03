#include <iostream>
#include <string>

bool ValidatePassword(const std::string& password) {
    if (password.size() < 8 or password.size() > 14) {
        return false;
    }

    size_t capital_letters = 0;
    size_t small_letters = 0;
    size_t numbers = 0;
    size_t other_characters = 0;
    for (const char& elem : password) {
        if (elem < 33 or elem > 126) {
            return false;
        } else if (elem >= 'A' and elem <= 'Z') {
            ++capital_letters;
        } else if (elem >= 'a' and elem <= 'z') {
            ++small_letters;
        } else if (elem >= '0' and elem <= '9') {
            ++numbers;
        } else {
            ++other_characters;
        }
    }

    if (capital_letters < 3 or small_letters < 3 or numbers < 3 or other_characters < 3) {
        return false;
    }
    return true;
}

int main() {
    std::string password;
    std::cin >> password;

    std::cout << std::boolalpha;
    std::cout << ValidatePassword(password);
}