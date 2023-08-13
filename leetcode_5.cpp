#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string result = s.substr(0, 1);
        string::iterator head, tail;
        
        for(auto c = s.begin(); c != s.end(); c++){
            head = tail = c;
            while(head[0] == tail[1])
                tail++;
            
            while((head > s.begin()) && (tail < s.end()) && (head[-1] == tail[1])){
                head--;
                tail++;
            }
            
            if(tail - head + 1> result.length()){
                result = s.substr(head - s.begin(), tail - head + 1);
            }
        }
        
        return result;
    }
};

int main(void){
    Solution solution;
    string s, result;
    
    cout << "Type the string you want to test: ";
    cin >> s;
    result = solution.longestPalindrome(s);
    cout << "The result is: \"" << result << '\"' << endl;
    
    return 0;
}