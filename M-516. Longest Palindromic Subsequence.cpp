#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        int memo[1000][1000] = {0};
        return memoDp(0, n - 1, memo, s);
    }

    int memoDp(int i, int j, int memo[1000][1000], string str) {
        if (i == j) return 1;
        if (i > j || i < 0 || j >= str.length()) return 0;
        if (memo[i][j] != 0) return memo[i][j];

        int res = 0;
        if (str[i] == str[j]) {
            res = max(res, memoDp(i + 1, j - 1, memo, str) + 2);
        } else {
            res = max(res, memoDp(i + 1, j, memo, str));
            res = max(res, memoDp(i, j - 1, memo, str));
        }
        return memo[i][j] = res;
    }
};

int main() {
	cout << "aab" << endl;
    Solution s;
    string aab = "bbbab";
    int res = s.longestPalindromeSubseq(aab);
    cout << res << endl;
    return 0;
}
