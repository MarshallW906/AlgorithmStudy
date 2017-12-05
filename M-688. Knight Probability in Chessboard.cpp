class Solution {
    int dirs[8][2] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
public:
    double knightProbability(int N, int K, int r, int c) {
        /* TLE
        if (r < 0 || r >= N || c < 0 || c >= N) return 0;
        else if (K == 0) return 1;
        double prob = 0;
        for (int i = 0; i < 8; i++)
            prob += knightProbability(N, K - 1, r + dirs[i][0], c + dirs[i][1]) / 8;
        return prob;
        */
        vector<vector<vector<double> > > dp(K + 1, vector<vector<double> >(N, vector<double>(N, -1.0)));
        return helper(dp, N, K, r, c) / pow(8, K);
    }
    double helper(vector<vector<vector<double> > >& dp, int N, int K, int r, int c) {
        if (r < 0 || r >= N || c < 0 || c >= N) return 0;
        if (K == 0) return 1;

        if (dp[K][r][c] != -1.0) return dp[K][r][c];
        dp[K][r][c] = 0;
        for (int i = 0; i < 8; i++) {
            dp[K][r][c] += helper(dp, N, K - 1, r + dirs[i][0], c +dirs[i][1]);
        }
        return dp[K][r][c];
    }
};