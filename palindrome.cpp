#include <iostream>
#include <string>

bool IsPalindrome(const std::string& str) {
    auto begin_it = str.begin();
    auto end_it = str.end();
    --end_it;
    while (begin_it < end_it) {
        if (*begin_it == ' ') {
            ++begin_it;
        } else if (*end_it == ' ') {
            --end_it;
        } else if (*begin_it != *end_it) {
            return false;
        } else {
            ++begin_it;
            --end_it;
        }
    }
    return true;
}

int main() {
    std::string str;
    std::getline(std::cin, str);

    bool is_palindrome;
    is_palindrome = IsPalindrome(str);

    std::cout << std::boolalpha;
    std::cout << is_palindrome << std::endl;
}