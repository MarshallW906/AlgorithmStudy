class Solution {
public:
    int hammingDistance(int x, int y) {
        int t;
        if (x < y) {
            t = x;
            x = y;
            y = t;
        }
        int hamDist = 0;
        while (x) {
            if (x % 2 != y % 2) ++hamDist;
            x /= 2;
            y /= 2;
        }
        return hamDist;
    }
};