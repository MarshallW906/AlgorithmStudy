class Solution {
public:
    int findComplement(int num) {
        int ret = 0, cur = 1;
        while (num) {
            if (num % 2 == 0) ret += cur;
            cur <<= 1;
            num >>= 1;
        }
        return ret;
    }
};