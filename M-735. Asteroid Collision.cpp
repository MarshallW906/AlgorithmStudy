#include "./stdc++.h"

using namespace std;

class Solution {
   public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        int left = n;
        while (1) {
            int i = -1, j = n;
            while (asteroids[++i] == 0)
                ;
            while (asteroids[--j] == 0)
                ;
            int collision_count = 0;
            while (i < j) {
                int a = asteroids[i];
                if (!a) {
                    i++;
                    continue;
                }
                int k = i;
                while (asteroids[++k] == 0)
                    ;
                int b = asteroids[k];
                if (a * b > 0) {
                    i = k;
                    continue;
                } else if (a < 0 && b > 0) {
                    i = k;
                    continue;
                } else {
                    a = abs(a);
                    b = abs(b);
                    if (a > b)
                        asteroids[k] = 0;
                    else if (a < b)
                        asteroids[i] = 0;
                    else
                        asteroids[i] = asteroids[k] = 0;
                    --left;
                    ++collision_count;
                    i = k;
                    continue;
                }
            }
            if (collision_count == 0) break;
            if (left <= 0) break;
        }
        vector<int> ret;
        for (auto it = asteroids.begin(); it != asteroids.end(); it++) {
            if (*it) ret.push_back(*it);
        }
        return ret;
    }
};
