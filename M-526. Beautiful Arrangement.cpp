#include "./stdc++.h"

using namespace std;

class Solution {
   public:
    int countArrangement(int N) {
        vector<int> vs;
        for (int i = 1; i <= N; i++) vs.push_back(i);
        return count(N, vs);
    }
    int count(int N, vector<int>& vs) {
        if (N <= 0) return 1;
        int ret = 0;
        for (int i = 0; i < N; i++) {
            if (vs[i] % N == 0 || N % vs[i] == 0) {
                swap(vs[i], vs[N - 1]);
                ret += count(N - 1, vs);
                swap(vs[i], vs[N - 1]);
            }
        }
        return ret;
    }

    // A more comprehensive version also using backtracking
    int tcount = 0;
    vector<bool> visit;
    int countArrangement_MoreComprehensive(int N) {
        visit = vector<bool>(N + 1, false);
        calculate(N, 1);
        return tcount;
    }
    void calculate(int N, int pos) {
        if (pos > N) tcount++;
        for (int i = 1; i <= N; i++) {
            if (!visit[i] && (pos % i == 0 || i % pos == 0)) {
                visit[i] = true;
                calculate(N, pos + 1);
                visit[i] = false;
            }
        }
    }
};
