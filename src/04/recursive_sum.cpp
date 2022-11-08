#include <iostream>
#include <vector>

template<typename T>
T recursive_sum(std::vector<T> arr) {
    if (arr.size() == 1) {
        return arr[0];
    }
    T tmp = arr.back();
    arr.pop_back();
    return tmp + recursive_sum(arr);
};


int main() {
    std::cout << std::boolalpha << (recursive_sum(std::vector<int>{1, 1, 1, 1, 1}) == 5) << std::endl;
}