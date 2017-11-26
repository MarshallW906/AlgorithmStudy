#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int> > memo(n, vector<int>(n, 0));
        return memoDp(0, n - 1, memo, s);
    }

    int memoDp(int i, int j, vector<vector<int> >& memo, string& str) {
        if (memo[i][j] != 0) return memo[i][j];
        if (i == j) return 1;
        if (i > j) return 0;

        if (str[i] == str[j]) {
            memo[i][j] = memoDp(i + 1, j - 1, memo, str) + 2;
        } else {
            memo[i][j] = max(memoDp(i, j - 1, memo, str), memoDp(i + 1, j, memo, str));
        }
        return memo[i][j];
    }
};

int main() {
    Solution s;
    string aab = "hiddqscdxrhiddqscdxrhiddqscdxrhiddqscdxrhiddqscdxrhiddqscdxrhiddqscdxrhiddqscdxrhiddqscdxrhiddqscdxr";
    int res = s.longestPalindromeSubseq(aab);
    cout << res << endl;
    return 0;
}
