#include <iostream>
#include <string>
using namespace std;

//Actual solution submitted to LeetCode.
class Solution {
public:
    string longestPalindrome(string s) {
        string result = s.substr(0, 1);
        string::iterator head, tail;
        
        //For all elements, find the longest palindrome substring with the element as 'center' or 'seed'. 
        for(auto c = s.begin(); c != s.end(); c++){
            head = tail = c;
            //An important part. there can be many cases in how long the length of repeating characters in the center of substring is.
            //So you should check how many repeating characters before making the palindrome substring.
            while(head[0] == tail[1])
                tail++;
            
            //If the previous character of head and next character of tail is same, advance (or decrease) them.
            while((head > s.begin()) && (tail < s.end()) && (head[-1] == tail[1])){
                head--;
                tail++;
            }
            
            //Check if newly made substring is longer than previously existing one.
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