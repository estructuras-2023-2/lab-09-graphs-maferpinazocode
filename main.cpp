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

struct Carretera {
    string id;
    string ciudad1;
    string ciudad2;
    int costo;

    Carretera(const string& i, const string& c1, const string& c2, int co = -1) : id(i), ciudad1(c1), ciudad2(c2), costo(co) {}
};

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
