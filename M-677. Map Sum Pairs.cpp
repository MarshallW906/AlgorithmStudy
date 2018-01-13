#include "./stdc++.h"

using namespace std;

class MapSum {
    map<string, int> m;

   public:
    /** Initialize your data structure here. */
    MapSum() {}

    void insert(string key, int val) { m[key] = val; }

    int sum(string prefix) {
        int ret = 0, n = prefix.length();
        for (auto it = m.lower_bound(prefix);
             it != m.end() && it->first.substr(0, n) == prefix; it++)
            ret += it->second;
        return ret;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
