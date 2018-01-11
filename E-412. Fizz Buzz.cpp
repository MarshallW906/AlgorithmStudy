#include "./stdc++.h"

using namespace std;

class Solution {
   public:
    vector<string> fizzBuzz(int n) {
        vector<string> ret;
        for (int i = 1, fizz = 0, buzz = 0; i <= n; i++) {
            fizz++;
            buzz++;
            if (fizz == 3 && buzz == 5) {
                ret.push_back("FizzBuzz");
            } else if (buzz == 5) {
                ret.push_back("Buzz");
            } else if (fizz == 3) {
                ret.push_back("Fizz");
            } else {
                ostringstream ostr;
                ostr << i;
                ret.push_back(ostr.str());
            }
        }
        return ret;
    }
};
