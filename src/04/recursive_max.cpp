#include <iostream>
#include <vector>

template<typename T>
T recursive_max(std::vector<T> arr) {
    if (arr.size() == 1) {
        return arr[0];
    }
    T tmp = arr.back();
    arr.pop_back();
    T cur_max = recursive_max(arr);
    return tmp > cur_max ? tmp : cur_max;
};


int main() {
    std::cout << "Max value is: " << recursive_max(std::vector<int>{3, 56, 2, 2323, 2, 33333, 5}) << std::endl;
}