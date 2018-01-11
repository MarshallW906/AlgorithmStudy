#include "./stdc++.h"

using namespace std;

class Solution {
   public:
    string complexNumberMultiply(string a, string b) {
        int ra, rb, ia, ib;
        char buff;
        int na = a.length(), nb = b.length();
        stringstream aa(a), bb(b), ans;
        aa >> ra >> buff >> ia >> buff;
        bb >> rb >> buff >> ib >> buff;

        cout << ra << ' ' << ia << ' ' << rb << ' ' << ia << endl;
        int real = 0, imag = 0;
        real = ra * rb - ia * ib;
        imag = ra * ib + rb * ia;
        ostringstream ostr;
        ostr << real << '+' << imag << 'i';
        return ostr.str();
    }
};
