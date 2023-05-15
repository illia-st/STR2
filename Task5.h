#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include "core.h"

void find_n_less(int n, std::vector<int> arr) {
    std::size_t vector_size = arr.size();
    auto start_time = std::chrono::high_resolution_clock::now();
    int m {std::min(static_cast<std::size_t>(n), arr.size())};
    std::vector<int> res;
    for(int i {}; i < m; ++i) {
        int min {INT32_MAX};
        int index {};
        for(int j {}; j < arr.size(); ++j) {
            if(min < arr[j]) {
                index = j;
                min = arr[j];
            }
        }
        res.push_back(min);
        arr.erase(arr.begin() + index);
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    auto time_diff = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    std::cout << "(No sort) Elapsed time for " << vector_size << " elements : " << time_diff.count() << "ms\n";
}
void find_n_less_sort(int n, std::vector<int> arr) {
    auto start_time = std::chrono::high_resolution_clock::now();
    int m {std::min(static_cast<std::size_t>(n), arr.size())};
    std::sort(arr.begin(), arr.end());
    std::vector<int> res = {arr.begin(), arr.begin() + m};
    auto end_time = std::chrono::high_resolution_clock::now();
    auto time_diff = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    std::cout << "(Sort) Elapsed time for " << arr.size() << " elements : " <<  time_diff.count() << "ms\n";
}

int main() {
    auto val = generate_random_sequence(1000, 1, 100);
    find_n_less(5, val);
    find_n_less_sort(5, val);

    find_n_less(100, val);
    find_n_less_sort(100, val);

    find_n_less(500, val);
    find_n_less_sort(500, val);

    find_n_less(900, val);
    find_n_less_sort(900, val);
    return 0;
}