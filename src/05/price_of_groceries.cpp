#include <iostream>
#include <string>
#include <unordered_map>


int main() {
    std::unordered_map<std::string, float> book{
        {"apple", 0.67},
        {"orange", 0.87},
        {"milk", 1.48}
    };

    for (std::pair<std::string, float> pair : book) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}