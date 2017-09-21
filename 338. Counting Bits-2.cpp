class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res = vector<int>(num + 1, 0);
        int pow2 = 1, before = 1;
        for (int i = 1; i <= num; i++) {
            if (i == pow2) {
                res[i] = before = 1;
                pow2 <<= 1;
            } else {
                res[i] = res[before++] + 1;
            }
        }
        return res;
    }
};