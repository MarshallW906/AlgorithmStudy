#include "./stdc++.h"

using namespace std;

class Solution {
   public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        int lp_count[26] = {0}, lp_len = licensePlate.length(), lp_a_count = 0;
        for (int i = 0; i < lp_len; i++) {
            char c = licensePlate[i];
            if (isAlphabet(c)) {
                ++lp_count[getLowercase(c) - 'a'];
                ++lp_a_count;
            }
        }
        string ret = "11112222333344445555";
        for (auto& str : words) {
            int count[26] = {0}, clen = str.length();
            for (int i = 0; i < clen; i++) {
                ++count[str[i] - 'a'];
            }
            bool ok = true;
            for (int i = 0; i < 26; i++) {
                if (count[i] < lp_count[i]) {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;
            if (clen == lp_a_count) return str;
            if (clen < ret.length()) ret = str;
        }
        return ret;
    }
    bool isAlphabet(const char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }
    char getLowercase(const char c) {
        if (c >= 'A' && c <= 'Z') return c + 32;
        return c;
    }
};