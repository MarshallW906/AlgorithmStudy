#include "./stdc++.h"

using namespace std;

class Solution {
   public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        int n = A.size();
        map<int, int> anagram;
        vector<int> ret(n, 0);
        for (int i = 0; i < n; i++) {
            // B
            anagram.insert(pair<int, int>(B[i], i));
        }
        for (int i = 0; i < n; i++) {
            ret[i] = anagram[A[i]];
        }
        return ret;
    }
};
