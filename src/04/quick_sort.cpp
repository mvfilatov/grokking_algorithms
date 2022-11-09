#include <iostream>
#include <vector>


template<typename T>
std::vector<T> quickSorted(const std::vector<T>& arr) {
    if (arr.size() < 2) {
        return arr;
    }
    const T pivot = arr.front(); // Выбираем опорный элемент
    std::vector<T> left;
    std::vector<T> right;
    for (const T element : arr) {
        if (element == pivot) {
            continue;
        }
        element < pivot ? left.push_back(element) : right.push_back(element);
    }

    left = quickSorted(left);
    right = quickSorted(right);
    left.push_back(pivot);
    left.insert(left.end(), right.begin(), right.end());
    return left;
};

template<typename T>
void quickSort(std::vector<T>& arr) {
    if (arr.size() < 2) {
        return;
    }
    const T pivot = arr.front(); // Выбираем опорный элемент
    std::vector<T> left;
    std::vector<T> right;
    for (const T element : arr) {
        if (element == pivot) {
            continue;
        }
        element < pivot ? left.push_back(element) : right.push_back(element);
    }

    quickSort(left);
    quickSort(right);
    left.push_back(pivot);
    left.insert(left.end(), right.begin(), right.end());
    arr = left;
};

int main() {
    std::vector<int> arr{2, 54, 7, 45, 1, 1, 45, 6, 0, 999};
    std::cout << "sorted vector is [";
    quickSort(arr);
    for (auto el : arr) {
        std:: cout << " " << el << ";";
    }
    std::cout << "]" << std::endl;
}
