#include <iostream>
#include <vector>
#include <map>

/* uint16_t CountPairs(const std::vector<int16_t>& values, int16_t k) {
    std::map<int16_t, uint16_t> values_count;
    for (const auto elem : values) {
        ++values_count[elem];
    }

    uint16_t count_pairs = 0;
    for (const auto& [key, value] : values_count) {
        if (key >= k / 2) {
            count_pairs += (value * (value - 1)) / 2;
            break;
        }
        if (values_count.count(k - key)) {
            count_pairs += value * values_count[k - key];
        }
    }

    return count_pairs;
} */
uint16_t CountPairs(const std::vector<int16_t>& values, int16_t k) {
    std:: map<int, size_t> values_count;
    uint16_t count_pairs = 0;
    for (const auto& value: values) {
        int complement = k - value;
        if (values_count.count(complement)) {
            count_pairs += values_count[complement];
        }
        ++values_count[value];
    }

    return count_pairs;
}

int main() {
    size_t values_size = 0;
    std::cin >> values_size;
    std::vector<int16_t> values(values_size);
    for (auto& elem : values) {
        std::cin >> elem;
    }

    int16_t k = 0;
    std::cin >> k;

    std::cout << CountPairs(values, k) << std::endl;

    return 0;
}