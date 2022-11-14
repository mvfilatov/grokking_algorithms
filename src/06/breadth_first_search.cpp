#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>


bool is_seller(const std::string& name) {
    return name.back() == 'm';
}

template<typename T>
bool breadth_first_search(const std::unordered_map<T, std::vector<T>>& graph, const T& name) {
    std::queue<T> to_search;
    std::unordered_set<std::string> searched;

    for (auto&& friend_name : graph.find(name) -> second) {
        to_search.push(friend_name);
    }

    while (!to_search.empty()) {
        T& person = to_search.front();
        to_search.pop();
        if (searched.find(person) == searched.end()) {
            if (is_seller(person)) {
                std::cout << person << " is seller!" << std::endl;
                return true;
            }

            for (auto&& friend_name : graph.find(person) -> second) {
                to_search.push(friend_name);
            }
        }
        searched.insert(person);
    }
    return false;
};


int main() {
    std::unordered_map<std::string, std::vector<std::string>> graph;
    graph.insert({"You", {"Alice", "Bob", "Claire"}});
    graph.insert({"Bob", {"Ann", "Peggy"}});
    graph.insert({"Alice", {"Peggy"}});
    graph.insert({"Claire", {"Tom", "Jonny"}});
    graph.insert({"Ann", {}});
    graph.insert({"Peggy", {}});
    graph.insert({"Tom", {}});
    graph.insert({"Jonny", {}});
    bool have_we_seller = breadth_first_search(graph, std::string{"You"});
    std::cout << std::boolalpha << "Have seller: " << have_we_seller << std::endl;
}