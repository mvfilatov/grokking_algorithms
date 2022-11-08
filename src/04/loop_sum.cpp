#include <iostream>
#include <vector>

template<typename T>
T loop_sum(const std::vector<T>& arr) {
    T sum = arr.front();
    for (int i = 1; i < arr.size(); ++i) {
        sum += arr[i];
    }
    return sum;
};

int main() {
    std::cout << std::boolalpha  << (loop_sum(std::vector<int>{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}) == 10) << std::endl;
}