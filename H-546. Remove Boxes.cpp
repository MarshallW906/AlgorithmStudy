#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
    	int n = boxes.size();
    	int memo[100][100][100] = {0};
        return memoSearch(boxes, memo, 0, n - 1, 0);
    }

private:
    int memoSearch(vector<int>& boxes, int memo[100][100][100], int i, int j, int k) {
        if (j < i) return 0; // memo[i][j][k] = 0;
        if (i == j) return (k + 1) * (k + 1); // memo[i][j][k] = (k + 1) * (k + 1);
        if (memo[i][j][k] > 0) return memo[i][j][k];
        // cout << i << ' ' << j << ' ' << k << ' ' << endl;

        for (; i + 1 <= j && boxes[i] == boxes[i + 1]; i++, k++);
        int res = (k + 1) * (k + 1) + memoSearch(boxes, memo, i + 1, j, 0);
        for (int m = i + 1; m <= j; m++) {
            if (boxes[i] == boxes[m])
                res = max(res, memoSearch(boxes, memo, i + 1, m - 1, 0) + memoSearch(boxes, memo, m, j, k + 1));
        }
        return memo[i][j][k] = res;
    }
};

int main() {
    Solution s;
    vector<int> a = {1, 3, 2, 2, 2, 3, 4, 3, 1}; // -std=c++11
    int sss = s.removeBoxes(a);
    cout << sss << endl;
}
