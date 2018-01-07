#include "./stdc++.h"

using namespace std;

class Solution {
    set<string> visit;
    string ans;

   public:
    string crackSafe(int n, int k) {
        if (n == 1 && k == 1) return "0";
        string start = "";
        for (int i = 0; i < n - 1; i++) start += "0";
        helper(k, start);
        return ans + start;
    }

    void helper(int k, string last_str) {
        for (int i = 0; i < k; i++) {
            char nxt = ('0' + i);
            string neighbor = last_str + nxt;
            if (visit.find(neighbor) == visit.end()) {
                visit.insert(neighbor);
                helper(k, neighbor.substr(1));
                ans += nxt;
            }
        }
    }
};

int main() {
    Solution s;
    string safe = s.crackSafe(1, 2);
    cout << "safe str: " << safe << endl;
    return 0;
}