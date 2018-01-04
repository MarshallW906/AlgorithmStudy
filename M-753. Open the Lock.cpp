#include "./stdc++.h"

using namespace std;

class Solution {
   public:
    int openLock(vector<string>& deadends, string target) {
        set<string> ddends(deadends.begin(), deadends.end());
        set<string> visit;
        string init = "0000";
        if (ddends.find(init) != ddends.end()) return -1;
        if (init == target) return 0;
        visit.insert(init);
        int step = 0;
        queue<string> bfs;
        bfs.push(init);
        while (!bfs.empty()) {
            int sz = bfs.size();
            for (int i = 0; i < sz; i++) {
                string cur = bfs.front();
                bfs.pop();
                vector<string> nbr = std::move(nbrStr(cur));
                for (auto& s : nbr) {
                    cout << s << endl;
                    if (s == target) return step + 1;
                    if (ddends.find(s) != ddends.end()) continue;
                    if (visit.find(s) == visit.end()) {
                        bfs.push(s);
                        visit.insert(s);
                    }
                }
            }
            ++step;
        }
        return -1;
    }
    vector<string> nbrStr(const string& str) {
        vector<string> res;
        for (int i = 0; i < 4; i++) {
            string tmp = str;
            tmp[i] = (str[i] - '0' + 1) % 10 + '0';
            res.push_back(tmp);
            tmp[i] = (str[i] - '0' - 1 + 10) % 10 + '0';
            res.push_back(tmp);
        }
        return res;
    }
};