#include "./stdc++.h"

using namespace std;

class Solution {
    vector<vector<bool>> visit;

   public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int nc) {
        visit = vector<vector<bool>>(image.size(),
                                     vector<bool>(image[0].size(), false));
        dfs(image, sr, sc, image[sr][sc], nc);
        return image;
    }

    void dfs(vector<vector<int>>& image, int sr, int sc, int c_prev,
             int c_nxt) {
        if (sr < 0 || sr >= image.size() || sc < 0 || sc > image[0].size() ||
            visit[sr][sc] || image[sr][sc] != c_prev)
            return;
        image[sr][sc] = c_nxt;
        visit[sr][sc] = true;
        dfs(image, sr - 1, sc, c_prev, c_nxt);
        dfs(image, sr + 1, sc, c_prev, c_nxt);
        dfs(image, sr, sc - 1, c_prev, c_nxt);
        dfs(image, sr, sc + 1, c_prev, c_nxt);
    }
};

int main() {
    Solution s;
    vector<vector<int>> a{{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    s.floodFill(a, 1, 1, 2);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) cout << a[i][j] << ' ';
    return 0;
}
/*
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
int newColor) { if (image[sr][sc] != newColor) dfs(image, sr, sc, image[sr][sc],
newColor); return image;
    }

private:
    void dfs(vector<vector<int>>& image, int i, int j, int c0, int c1) {
        if (i < 0 || j < 0 || i >= image.size() || j >= image[0].size() ||
image[i][j] != c0) return; image[i][j] = c1; dfs(image, i, j - 1, c0, c1);
        dfs(image, i, j + 1, c0, c1);
        dfs(image, i - 1, j, c0, c1);
        dfs(image, i + 1, j, c0, c1);
    }
};*/