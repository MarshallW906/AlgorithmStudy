class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int> > ssret;
        std::sort(nums.begin(), nums.end());
        
        for (int i = 0; i < (int)nums.size() - 2; i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int remainder = 0 - nums[i];
            int k = i + 1, j = (int)nums.size() - 1;
            while (k < j) {
                if (nums[k] + nums[j] == remainder) {
                    ssret.insert({nums[i], nums[k], nums[j]});
                    while (k < j && nums[k] == nums[k + 1]) ++k;
                    while (k < j && nums[j] == nums[j - 1]) --j;
                    ++k; --j;
                } else if (nums[k] + nums[j] < remainder) ++k;
                else --j;
            }
        }
        vector<vector<int> > ret;
        for (set<vector<int>>::iterator it = ssret.begin(); it != ssret.end(); it++) {
            ret.push_back(*it);
        }
        return ret;
    }
};