#include "./stdc++.h"

using namespace std;

class Solution {
   public:
    string reverseWords(string s) {
        stack<char> ss;
        int n = s.length();
        string ret;
        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                ss.push(s[i]);
            } else {
                while (!ss.empty()) {
                    ret += ss.top();
                    ss.pop();
                }
                ret += ' ';
            }
        }
        while (!ss.empty()) {
            ret += ss.top();
            ss.pop();
        }
        return ret;
    }
};
