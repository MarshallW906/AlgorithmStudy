#include "./stdc++.h"

using namespace std;

class Solution {
   public:
    int arrayNesting(vector<int>& a) {
        int n = a.size();
        int maxsize = 0;
        vector<bool> visit(n, 0);
        for (int i = 0; i < n; i++) {
            int cursz = 0;
            for (int k = i; a[k] >= 0; cursz++) {
                int ak = a[k];
                a[k] = -1;
                k = ak;
            }
            if (cursz > maxsize) maxsize = cursz;
        }
        return maxsize;
    }
};