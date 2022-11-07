#include <iostream>
#include <vector>

template<typename T>
int findSmallest(const std::vector<T>& arr) {
    T smallest = arr.front();
    int smallest_index = 0;

    for (auto i = 0; i < arr.size(); ++i) {
        if (arr[i] < smallest) {
            smallest = arr[i];
            smallest_index = i;
        }
    }
    return smallest_index;
};


template<typename T>
std::vector<T> selectionSort(std::vector<T>& arr) {
    std::vector<T> result{};
    while (!arr.empty()) {
        int smallest_index = findSmallest(arr);
        result.push_back(arr[smallest_index]);
        arr.erase(arr.begin() + smallest_index);
    }
    return result;
};


int main() {
    std::vector<int> my_vec {1, 2, 3, 234, 6, 1, 1, 1};
    std::vector<int> sorted_vec = selectionSort(my_vec);
    for (int num : sorted_vec) {
        std::cout << num << std::endl;
    }
}
