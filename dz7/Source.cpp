// дз 7
#include <vector>
#include <string>
#include <set>
#include <map>
#include <iostream>

using namespace std;

template<typename String>
map<set<typename String::value_type>, vector<String>> GroupHeavyStrings(const vector<String>& strings) {
    map<set<typename String::value_type>, vector<String>> groups;
    for (const auto& str : strings) {
        set<typename String::value_type> unique_chars(str.begin(), str.end());
        groups[unique_chars].push_back(str);
    }
    return groups;
}

int main() {
    setlocale(LC_ALL, "RUS");
    vector<string> strings = { "law", "port", "top", "laptop", "pot", "paloalto", "wall", "awl", "lwa", "file"};
    auto groups = GroupHeavyStrings(strings);

    for (const auto& group : groups) {
        cout << "Группа с уникальными символами: ";
        for (const auto& unique_char : group.first)
            cout << unique_char << " ";
        cout << endl;

        cout << "Строки в этой группе: ";
        for (const auto& str : group.second)
            cout << str << " ";
        cout << endl << endl;
    }

    return 0;
}