#include <iostream>
#include <vector>

template<typename T>
int recursive_count(std::vector<T> arr) {
    if (arr.empty()) {
        return 0;
    }
    arr.pop_back();
    return 1 + recursive_count(arr);
};

int main() {
    std::cout << recursive_count(std::vector<char>{'1', 'a', 'b', 't'}) << std::endl;
}