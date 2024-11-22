#include <iostream>

int main() {
    std::vector<int> vec;
    vec.reserve(9);
    std::vector<int> other = {1, 2, 3, 4, 5};

    vec.push_back(93);
    auto it = vec.insert(vec.begin() + 1, 15);
    vec.insert(vec.end(), 3, 34);
    vec.insert(vec.begin() + 3, other.begin() + 1, other.end());
    {
        it = vec.end();
        --it;
        std::cout << *it << std::endl;
        --it;
        std::cout << *it << std::endl;
        --it;
        std::cout << *it << std::endl;
    }
    {
        it = vec.begin();
        std::cout << *it << std::endl;
        ++it;
        std::cout << *it << std::endl;
        ++it;
        std::cout << *it << std::endl;

    }

    std::cout << vec.size() << std::endl;
    for (int value : vec) {
        std::cout << value << " ";
    }

    return 0;
}