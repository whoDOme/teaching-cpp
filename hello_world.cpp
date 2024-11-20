#include <iostream>
#include <climits>

int main() {
    {
        if (int a = rand() > 100) {
            std::cout << "> 100";
        }
        else {
            std::cout << "< 100";
        }
    }

    return 0;
}