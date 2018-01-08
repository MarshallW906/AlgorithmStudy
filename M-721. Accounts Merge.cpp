#include "./stdc++.h"

using namespace std;

class Solution {
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

   private:
    string find_n(string s, map<string, string>& p) {
        return p[s] == s ? s : find_n(p[s], p);
    }
};
