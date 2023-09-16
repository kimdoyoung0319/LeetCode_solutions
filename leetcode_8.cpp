#include <iostream>
#include <vector>

#include <string>
#include <cctype>

using std::string;

class Solution {
    private:
        bool checkSign(string::iterator & it) {
            switch(*it) {
                case '+': it++; return true;
                case '-': it++; return false;
                default: return true;
            }
        }
        
        bool checkOverflow(const string & stripped, bool positive) {
            const int maxDigits = 10;
            const string maxAbsolute
                = positive ? "2147483647" : "2147483648";
            
            if(stripped.size() < maxDigits)
                return false;
            else if(stripped.size() > maxDigits)
                return true;
                
            if(stripped.compare(maxAbsolute) > 0)
                return true;
                
            return false;
        }
        
        int strippedToInt(const string & stripped, bool positive) {
            long long unit = 1;
            long long result = 0;
            
            for(auto it = stripped.rbegin(); it != stripped.rend(); it++) {
                result += (*it - '0') * unit;
                unit *= 10;
            }
            
            return positive ? result : -result;
        }
        
    public:
        int myAtoi(string s) {
            string::iterator it;
            for(it = s.begin(); *it == ' '; it++);
            
            bool positive = checkSign(it);
            string::iterator begin(it), end(it);
            
            for(; *begin == '0'; begin++);
            for(; isdigit(*end) && end <= s.end(); end++);
            
            string stripped(begin, end);
            bool overflow = checkOverflow(stripped, positive);
            
            if(overflow && positive)
                return 2147483647;
            
            if(overflow && !positive)
                return -2147483648;
            
            return strippedToInt(stripped, positive);
        }
};

int main() {
    using std::vector;
    
    Solution solution;
    string input;
    
    while(true) {
        std::cout << "Type the string you want to test.\n";
        std::cin >> input;
        std::cout << "The result of the myAtoi is " << solution.myAtoi(input) << ".\n";
    }
    
    return 0;
}