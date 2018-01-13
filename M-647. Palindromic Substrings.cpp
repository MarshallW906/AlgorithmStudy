#include "./stdc++.h"

using namespace std;

class Solution {
    int count, n;

   public:
    int countSubstrings(string s) {
        n = s.length();
        if (n == 0) return 0;
        if (n == 1) return 1;
        for (int i = 0; i < n; i++) {
            extendPalindrome(s, i, i);
            extendPalindrome(s, i, i + 1);
        }
        return count;
    }
    void extendPalindrome(string& s, int left, int right) {
        while (left >= 0 && right < n && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
    }
};