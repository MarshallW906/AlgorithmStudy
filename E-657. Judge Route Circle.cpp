class Solution {
public:
    bool judgeCircle(string moves) {
        int u, d, l, r;
        u = d = l = r = 0;
        for (int i = 0; i < moves.size(); i++) {
            switch (moves[i]) {
                case 'U':
                    ++u; break;
                case 'D':
                    ++d; break;
                case 'L':
                    ++l; break;
                case 'R':
                    ++r; break;
                default:
                    continue;
            }
        }
        if ((u - d == 0) && (l - r == 0))
            return true;
        return false;
    }
};