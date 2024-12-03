#include <iostream>
#include <vector>

int64_t find_max_subarray_sum(const std::vector<int32_t>& array) {
    int64_t max_sum = INT64_MIN;
    int64_t local_sum = 0;

    /*
    for (size_t i = 0; i < array.size(); ++i) {
        for (size_t j = i; j < array.size(); ++j){
            local_sum += array[j];
            if (local_sum > max_sum) {
                max_sum = local_sum;
            }
        }
        local_sum = 0;
    }
    */
    for (size_t i = 0; i < array.size(); ++i) {
        local_sum += array[i];
        if (local_sum > max_sum) {
            max_sum = local_sum;
        }
        if (local_sum < 0) {
            local_sum = 0;
        }
    }

    return max_sum;
}

int main() {
    int64_t max_sum = 0;
    size_t n;
    std::vector<int32_t> array;

    std::cout << "Введите количество элементов массива: " << std::endl;
    std::cin >> n;
    array.resize(n);
    std::cout << "Введите элементы" << std::endl;
    for (size_t i = 0; i < n; ++i) {
        std::cin >> array[i];
    }

    max_sum = find_max_subarray_sum(array);

    std::cout << "Максимальная сумма: " << max_sum << std::endl;

    return 0;
}