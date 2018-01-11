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
                fizz = buzz = 0;
            } else if (buzz == 5) {
                ret.push_back("Buzz");
                buzz = 0;
            } else if (fizz == 3) {
                ret.push_back("Fizz");
                fizz = 0;
            } else {
                ostringstream ostr;
                ostr << i;
                ret.push_back(ostr.str());
            }
        }
        return ret;
    }
};
