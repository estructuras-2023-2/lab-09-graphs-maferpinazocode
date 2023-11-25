#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>

using namespace std;

string find(map<string, string>& parent, const string& s) {
    if (parent.find(s) == parent.end())
        parent[s] = s;
    else if (parent[s] != s)
        parent[s] = find(parent, parent[s]);
    return parent[s];
}

void unite(map<string, string>& parent, const string& a, const string& b) {
    string nodeA = find(parent, a);
    string nodeB = find(parent, b);
    if (nodeA != nodeB)
        parent[nodeA] = nodeB;
}

bool areCitiesConnected(map<string, string>& parent, const string& a, const string& b) {
    return find(parent, a) == find(parent, b);
}

bool isTotalConnection(map<string, string>& parent, const vector<string>& cities) {
    if (cities.empty()) return true;
    string node = find(parent, cities.front());
    for (const auto& city : cities) {
        if (find(parent, city) != node) return false;
    }
    return true;
}

struct Road {
    string id;
    string city1;
    string city2;
    int cost;

    Road(const string& i, const string& c1, const string& c2, int co = -1) : id(i), city1(c1), city2(c2), cost(co) {}
};

vector<string> split(const string& str, char delim) {
    vector<string> keys;
    size_t start = 0;
    size_t end = str.find(delim);
    while (end != string::npos) {
        keys.push_back(str.substr(start, end - start));
        start = end + 1;
        end = str.find(delim, start);
    }
    keys.push_back(str.substr(start));
    return keys;
}
