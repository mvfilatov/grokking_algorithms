#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

void check_voted_list(
    std::unordered_map<std::string, bool>& voted_list,
    std::string name
) {
    auto search = voted_list.find(name);
    if (search == voted_list.end() || search->second == false) {
        voted_list.insert({name, true});
        std::cout << "Let " << name << " vote!" << std::endl;
    } else {
        std::cout << "Kick " << name << " out!" << std::endl;
    }
};

int main() {
    std::unordered_map<std::string, bool> voted_list{
        {"Max", false},
    };
    check_voted_list(voted_list, "Mike");
    check_voted_list(voted_list, "Max");
    check_voted_list(voted_list, "Mike");

}