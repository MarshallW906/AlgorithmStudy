#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int, int> left, right, count;
        int maxCnt = 0, ans = 99999;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            if (left.find(x) == left.end()) left.insert(pair<int, int>(x, i));
            right[x] = i;
            maxCnt = max(maxCnt, ++count[x]);
        }
        cout << maxCnt << endl;
        for (auto it : left) {
            int x = it.first, cnt = count[x];
            if (cnt == maxCnt) ans = min(ans, right[x] - left[x] + 1);
        }
        return ans;
    }
};

int main() {

}
