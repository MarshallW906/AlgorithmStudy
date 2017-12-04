#include <cstring>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
class Solution {
   public:
    bool canPartitionKSubsets(vector<int> &nums, int K) {
        int N = nums.size();
        if (K == 1) return true;
        if (N < K) return false;

        int sum = 0;
        for (int i = 0; i < N; i++) sum += nums[i];
        if (sum % K != 0) return false;

        int subset = sum / K;
        int subsetSum[K];
        bool taken[N];

        for (int i = 0; i < K; i++) subsetSum[i] = 0;
        for (int i = 0; i < N; i++) taken[i] = false;
        subsetSum[0] = nums[N - 1];
        taken[N - 1] = true;
        return canPartitionKSubsets(nums, subsetSum, taken, subset, K, N, 0,
                                    N - 1);
    }

    // Recursive Utility method to check K equal sum
    // subsetition of array
    /**
     * array           - given input array
     * subsetSum array   - sum to store each subset of the array
     * taken           - boolean array to check whether element
     *                   is taken into sum partition or not
     * K               - number of partitions needed
     * N               - total number of element in array
     * curIdx          - current subsetSum index
     * limitIdx        - lastIdx from where array element should be taken
     */
    bool canPartitionKSubsets(vector<int> &nums, int subsetSum[], bool taken[],
                              int subset, int K, int N, int curIdx,
                              int limitIdx) {
        if (subsetSum[curIdx] == subset) {
            /**
             * current index (K - 2) represents (K - 1) subsets of equal
             * sum last partition will already remain with sum 'subset'
             */
            if (curIdx == K - 2) return true;
            // recursive call for next subsetition
            return canPartitionKSubsets(nums, subsetSum, taken, subset, K, N,
                                        curIdx + 1, N - 1);
        }

        // start from limitIdx and include elements into current partition
        for (int i = limitIdx; i >= 0; i--) {
            if (taken[i]) continue;
            int tmp = subsetSum[curIdx] + nums[i];

            if (tmp <= subset) {
                taken[i] = true;
                subsetSum[curIdx] += nums[i];
                bool nxt = canPartitionKSubsets(nums, subsetSum, taken, subset,
                                                K, N, curIdx, i - 1);
                if (nxt) return true;
                // after recursive call unmark the element and remove from subsetition sum
                taken[i] = false;
                subsetSum[curIdx] -= nums[i];
            }
        }
        return false;
    }
};
