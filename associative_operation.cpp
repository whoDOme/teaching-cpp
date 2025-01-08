#include <iostream>
#include <vector>

bool IsAssociative(const std::vector<std::vector<int64_t>>& table) {
    size_t table_size = table.size();
    for (size_t x = 0; x < table_size; ++x) {
        for (size_t y = 0; y < table_size; ++y) {
            for (size_t z = 0; z < table_size; ++z) {
                if (table[table[x][y]][z] != table[x][table[y][z]]) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    size_t table_size = 0;
    std::cin >> table_size;
    std::vector<std::vector<int64_t>> table(table_size, std::vector<int64_t>(table_size));
    for (size_t i = 0; i < table_size; ++i) {
        for (size_t j = 0; j < table_size; ++j) {
            std::cin >> table[i][j];
        }
    }

    std::cout << std::boolalpha << IsAssociative(table) << std::endl;

    return 0;
}