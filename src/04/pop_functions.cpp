#include <iostream>
#include <vector>

template<typename T>
T pop_front(std::vector<T>& arr) {
    arr.back() = arr.front();
    T tmp = arr.back();
    arr.pop_back();
    return tmp;
}

template<typename T>
T pop_back(std::vector<T>& arr) {
    T tmp = arr.back();
    arr.pop_back();
    return tmp;
}

template<typename T>
T pop(std::vector<T>& arr, int index) {
    if (index >= arr.size()) {
        throw std::range_error("Index out of range");
    }
    T tmp = arr[index];
    arr.erase(arr.begin() + index);
    return tmp;
}

int main() {
    std::vector<int> my_vec{999, 2, 3, 4, 5, 6};
    std::cout << pop_front(my_vec) << std::endl;
}
