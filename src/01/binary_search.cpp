#include <iostream>
#include <vector>
#include <string>


template<typename T>
int binary_search(const std::vector<T>& arr, const T& value) {
    int left = arr.front();
    int right = arr.back();

    while (left <= right) {
        int mid = (left + right) / 2;
        T guess = arr[mid];
        if (guess == value) {
            return mid;
        }
        if (guess < value) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
};

template<typename T>
const T* binary_search2(const std::vector<T>& arr, const T& value) {
    const T* left = &arr.front();
    const T* right = &arr.back();

    while (left <= right) {
        const T* guess = left + ((right - left) / 2);

        if (*guess == value) {
            return guess;
        }

        if (*guess < value) {
            left = guess + 1;
        }
        else {
            right = guess - 1;
        }
    }

    return nullptr;
};


int main() {
    std::vector<int> my_vec {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << binary_search(my_vec, 5) << std::endl;
    std::cout << binary_search(my_vec, 12) << std::endl;
    if (binary_search2(my_vec, 12) == nullptr) {
        std::cout << "Число 12 не найдено" << std::endl;
    }
}
