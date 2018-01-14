#include <vector>

using namespace std;

class Solution {
   private:
    vector<vector<int>> V;
    vector<int> ans;
    vector<bool> vis;
    void dfs(int u) {
        int v, i;
        vis[u] = true;
        for (i = 0; i < V[u].size(); i++) {
            v = V[u][i];
            if (!vis[v]) dfs(v);
        }
        ans.push_back(u);
    }

   public:
    vector<int> topologicalSort(int n, vector<pair<int, int>>& edges) {
        int u, v, i;
        V.resize(n);
        vis.resize(n);
        for (i = 0; i < edges.size(); i++) {
            u = edges[i].first;
            v = edges[i].second;
            V[v].push_back(u);
        }
        for (i = 0; i < n; i++) vis[i] = false;
        for (i = 0; i < n; i++)
            if (!vis[i]) dfs(i);
        return ans;
    }
};