#include <iostream>
#include <climits>

int main() {
    {
        if (int a = rand(), b = 100; a > b) {
            std::cout << a << b << "a" << std::endl;
        }
        else {
            std::cout << a << b << "b" << std::endl;
        }
    }

    return 0;
}