#include <iostream>
#include <vector>

void moving_zeros(std::vector<uint32_t>& vec) {
    size_t index_none_zero_elements = 0;

    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i] != 0) {
            std::swap(vec[i], vec[index_none_zero_elements]);
            ++index_none_zero_elements;
        }
    }
}

int main() {
    std::vector<uint32_t> vec;
    size_t n;

    std::cout << "Введите количество элементов: " << std::endl;
    std::cin >> n;
    vec.resize(n);

    std::cout << "Введите элементы" << std::endl;
    for (size_t i = 0; i < n; ++i) {
        std::cin >> vec[i];
    };

    moving_zeros(vec);
    for (auto value : vec) {
        std::cout << value << " ";
    };

    return 0;
}