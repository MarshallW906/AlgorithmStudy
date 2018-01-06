#include "./stdc++.h"

using namespace std;

class Solution {
   public:
    string getString(int n) {
        string ret = "";
        string tmp = "a";
        while (n) {
            char c = n % 10 + '0';
            tmp[0] = c;
            ret = tmp + ret;
            n /= 10;
        }
        return ret;
    }
    int getNum(string str) {
        int ret = 0, len = str.length();
        for (int i = 0; i < len; i++) {
            ret = ret * 10 + (str[i] - '0');
        }
        return ret;
    }
    int monotoneIncreasingDigits(int N) {
        string n_str = getString(N);

        int len = n_str.length();
        int marker = len;
        for (int i = n_str.length() - 1; i > 0; i--) {
            if (n_str[i] < n_str[i - 1]) {
                marker = i;
                n_str[i - 1] = n_str[i - 1] - 1;
            }
        }
        for (int i = marker; i < len; i++) n_str[i] = '9';
        return getNum(n_str);
    }
};
