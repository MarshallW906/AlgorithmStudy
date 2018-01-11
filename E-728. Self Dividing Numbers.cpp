#include "./stdc++.h"

using namespace std;

class Solution {
   public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ret;
        for (int i = left; i <= right; i++) {
            int tmp = i;
            if (i % 10 == 0) continue;
            bool flag = true;
            while (tmp) {
                int t = tmp % 10;
                if (!t || i % t) {
                    flag = false;
                    break;
                }
                tmp /= 10;
            }
            if (flag) ret.push_back(i);
        }
        return ret;
    }
};
