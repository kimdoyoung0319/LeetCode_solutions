#include <string>
#include <cstring>

using std::string;

class Solution {
public:
    bool isMatch(string s, string p) {
        // m[i][j] stores if s[:i] matches p[:j].
        bool m[s.length() + 1][p.length() + 1];
        memset(m, false, sizeof(m));

        m[0][0] = true;

        // i for index of string s, j for index of pattern p.
        for(int i = 0; i <= s.length(); i++) {
            for(int j = 1; j <= p.length(); j++) {
                if(p[j - 1] == '*') {
                    m[i][j] = m[i][j - 2] || (i != 0) && m[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.');
                } else {
                    m[i][j] = (i != 0) && m[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.'); 
                }
            }
        }

        return m[s.length()][p.length()];
    }
};