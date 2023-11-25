#include <iostream>
#include <string>

using namespace std;

struct Road {
    string id;
    string city1;
    string city2;
    int cost;

    Road(const string& i, const string& c1, const string& c2, int co = -1) : id(i), city1(c1), city2(c2), cost(co) {}
};

