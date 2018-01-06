#include "./stdc++.h"

using namespace std;

class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        // TLE
        // vector<int> ret(n, 0);
        // for (int i = 0; i < n - 1; i++) {
        //     for (int j = i + 1; j < n; j++) {
        //         if (temperatures[j] > temperatures[i]) {
        //             ret[i] = j - i;
        //             break;
        //         }
        //     }
        // }
        // return ret;

        // Stack version
        stack<int> s;
        vector<int> ret(n, 0);
        for (int i = 0; i < n; i++) {
            while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
                int t = s.top();
                ret[t] = t - i;
                s.pop();
            }
            s.push(i);
        }
        return ret;
    }
};
