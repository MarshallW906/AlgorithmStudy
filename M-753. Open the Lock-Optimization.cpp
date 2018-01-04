#include "./stdc++.h"

using namespace std;

class Solution {
   public:
    // Bidirectional BFS improves the efficiency
    int openLock(vector<string>& deadends, string target) {
        set<string> dds(deadends.begin(), deadends.end());
        set<string> q1, q2, pass, visited;
        string init = "0000";
        int step = 0;
        if (dds.find(init) != dds.end() || dds.find(target) != dds.end())
            return -1;
        if (init == target) return 0;
        visited.insert(init);
        q1.insert(init);
        q2.insert(target);
        // Bidirectional BFS
        // implicitly ignores a huge amount of useless search
        while (!q1.empty() && !q2.empty()) {
            if (q1.size() > q2.size()) std::swap(q1, q2);
            pass.clear();
            for (auto& s : q1) {
                vector<string> nbr = std::move(nbrStr(s));
                for (auto& snbr : nbr) {
                    // Judge Correct Answer: not find it in q2
                    // Changed from (snbr == target)
                    //         to (q2.find(snbr) != q2.end())
                    if (q2.find(snbr) != q2.end()) return step + 1;
                    if (dds.find(snbr) != dds.end()) continue;
                    if (visited.find(snbr) == visited.end()) {
                        pass.insert(snbr);
                        visited.insert(snbr);
                    }
                }
            }
            std::swap(q1, pass);
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