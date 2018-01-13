#include "./stdc++.h"

using namespace std;

class Solution {
    int m, n;

   public:
    int islandPerimeter(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int ret = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid[i][j]) continue;
                int tmp = 4;
                auto nei = getNeibr(i, j);
                for (auto& tnei : nei) {
                    if (grid[i + tnei.first][j + tnei.second]) tmp--;
                }
                ret += tmp;
            }
        }
        return ret;
    }
    vector<pair<int, int>> getNeibr(int r, int c) {
        vector<pair<int, int>> ret;
        if (r > 0) ret.push_back(pair<int, int>(-1, 0));
        if (r < m - 1) ret.push_back(pair<int, int>(1, 0));
        if (c > 0) ret.push_back(pair<int, int>(0, -1));
        if (c < n - 1) ret.push_back(pair<int, int>(0, 1));
        return ret;
    }

    // A more simpler solution:
    int islandPerimeter_Simple(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int count = 0, repeat = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    count++;
                    if (i && grid[i - 1][j]) repeat++;
                    if (j && grid[i][j - 1]) repeat++;
                }
            }
        }
        return count * 4 - repeat * 2;
    }
};
