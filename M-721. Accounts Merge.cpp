#include "./stdc++.h"

using namespace std;

class Solution {
   private:
    string find_n(string s, map<string, string>& p) {
        return p[s] == s ? s : find_n(p[s], p);
    }

   public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string, string> parents;
        map<string, string> owner;
        // use one of the union emails as the key, and all the set is the value
        // at last generate a vector<string> for all the set, and insert the
        // owner at the begin().
        map<string, set<string>> unions;

        int n = accounts.size();
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                parents[accounts[i][j]] = accounts[i][j];
                owner[accounts[i][j]] = accounts[i][0];
            }
        }
        for (int i = 0; i < n; i++) {
            string p = find_n(accounts[i][1], parents);
            for (int j = 2; j < accounts[i].size(); j++)
                parents[find_n(accounts[i][j], parents)] = p;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++)
                unions[find_n(accounts[i][j], parents)].insert(accounts[i][j]);
        }
        vector<vector<string>> res;
        for (pair<string, set<string>> p : unions) {
            vector<string> emails(p.second.begin(), p.second.end());
            emails.insert(emails.begin(), owner[p.first]);
            res.push_back(emails);
        }
        return res;
    }

    /**
     * Actually It is more similar to BFS: find one, then the nearest neighbors,
     * then 2nd nearest ... And it means that DFS and BFS are similar in many
     * aspects And this question is a perfect use of Union Find, not DFS or BFS
     * I found the author of this solution called it a DFS
     * but anyway and actually it's doing what BFS does.
     */
    vector<vector<string>> accountsMerge_BFS(vector<vector<string>>& accounts) {
        int n = accounts.size();
        map<string, vector<int>> email_group;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                // build connection between two which have same emails
                email_group[accounts[i][j]].push_back(i);
            }
        }

        vector<vector<string>> ret;
        bool visit[1010];
        memset(visit, 0, sizeof(visit));
        for (int i = 0; i < n; i++) {
            if (visit[i]) continue;
            visit[i] = true;

            set<string> emails;
            // keep the components index need to visit, use to_visit to
            // "imitate" the recursion
            vector<int> to_visit{i};
            // BFS
            for (int j = 0; j < to_visit.size(); j++) {
                int cur = to_visit[j];
                // push all email in the current component into emails
                // emails is a std::set<string>, which guarantees all the
                // entries are unique.
                emails.insert(accounts[cur].begin() + 1, accounts[cur].end());

                // BFS Find all the grouped(connected) emails(components)
                for (int k = 1; k < accounts[cur].size(); k++) {
                    for (auto idx : email_group[accounts[cur][k]]) {
                        if (visit[idx]) continue;
                        visit[idx] = true;
                        to_visit.push_back(
                            idx);  // more similar to bfs (not dfs)
                    }
                }
            }
            vector<string> tmp{accounts[i][0]};
            tmp.insert(tmp.end(), emails.begin(), emails.end());
            ret.push_back(tmp);
        }
        return ret;
    }
};

/* Here's a DFS version by Python:

class Solution(object):
    def accountsMerge(self, accounts):
        em_to_name = {}
        graph = collections.defaultdict(set)
        for acc in accounts:
            name = acc[0]
            for email in acc[1:]:
                graph[acc[1]].add(email)
                graph[email].add(acc[1])
                em_to_name[email] = name

        seen = set()
        ans = []
        for email in graph:
            if email not in seen:
                seen.add(email)
                stack = [email]
                component = []
                while stack:
                    node = stack.pop()
                    component.append(node)
                    for nei in graph[node]:
                        if nei not in seen:
                            seen.add(nei)
                            stack.append(nei)
                ans.append([em_to_name[email]] + sorted(component))
        return ans
*/