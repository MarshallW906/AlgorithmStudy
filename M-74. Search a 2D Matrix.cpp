#include "./stdc++.h"

using namespace std;

class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();

        int l = 0, r = m * n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            cout << matrix[mid / n][mid % n] << endl;
            if (matrix[mid / n][mid % n] == target)
                return true;
            else if (matrix[mid / n][mid % n] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        /* simple iteration can AC
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (target == matrix[i][j]) return true;
            }
        }
        */
        return false;
    }
};
