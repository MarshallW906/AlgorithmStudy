#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int prev = 0, cur = 1, nxt;
        for (int i = 1; i <= n; i++) {
            nxt = prev + cur;
            prev = cur;
            cur = nxt;
        }
        return nxt;
    }
};

int main() {
    Solution s;
    cout << s.climbStairs(5) << endl;
}