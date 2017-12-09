#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> f(n + 1, 0);
        f[0] = f[1] = 1;
        for (int i = 2; i <= n; i++)
            for (int j = 1; j <= n; j++)
                f[i] += f[j - 1] * f[i - j];
        return f[n];
    }
};