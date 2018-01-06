#include "./stdc++.h"

using namespace std;

/**
 * We can always take abs(target), since the axis is symmetric.
 * First of all we keep adding sum=1+2+..+n>=target, solve this quadratic
 * equation gives the smallest n such that sum>=target. If 1+2+..+n==target,
 * return n. Now we must minus res=sum-target. If res is even, we can flip one
 * number x in [1,n] to be -x. Otherwise if res is odd, and n+1 is odd, we can
 * first add n+1, then res is even. Next flip an x to be -x. If res is odd and
 * n+1 is even, we add n+1 then subtract n+2, res becomes even, then flip an x.
 */

class Solution {
   public:
    int reachNumber(int target) {
        target = abs(target);
        long long n = ceil((-1.0 + sqrt(1 + 8.0 * target)) / 2);
        long long sum = n * (n + 1) / 2;
        if (sum == target) return n;
        long long res = sum - target;
        if ((res & 1) == 0)
            return n;
        else
            return n + ((n & 1) ? 2 : 1);
    }
};
