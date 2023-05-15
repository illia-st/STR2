#pragma once
#include <random>

std::vector<int> generate_random_sequence(int num_values, int start, int end) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(start, end);
    std::vector<int> result(num_values);

    for (int i = 0; i < num_values; ++i) {
        result[i] = dis(gen);
    }

    return result;
}
