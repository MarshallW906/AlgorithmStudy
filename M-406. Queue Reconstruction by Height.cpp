#include "./stdc++.h"

using namespace std;

class Solution {
   public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        std::sort(people.begin(), people.end(),
                  [](pair<int, int> a1, pair<int, int> a2) -> bool {
                      // height Descending, K value ascending
                      return a1.first > a2.first ||
                             (a1.first == a2.first && a1.second < a2.second);
                  });
        vector<pair<int, int>> ret;
        for (auto& p : people) {
            ret.insert(ret.begin() + p.second, p);
        }
        return ret;
    }
};
