#include <iostream>
using namespace std;

//Actual solution submitted to LeetCode.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        //For all character in s, find the longetst subStr that starts with the character and does not contains repeating character.
        for(auto head = s.begin(); head != s.end(); head++){
            string subStr(1, *head);
            //std::string.find() returns std::string::npos if the query has not been found.
            for(auto it = head + 1; (it != s.end()) && (subStr.find(*it) == subStr.npos); it++)
                subStr.push_back(*it);
            //If the length of newly found substring is longer than already existing one, change it to the longer one.
            if(subStr.length() > result)
                result = subStr.length();
        }

        return result;
    }
};

int main(void){
    string s;
    Solution solution;
    cout << "Type the string you want to test." << endl;
    cin >> s;
    cout << "The tested value is: " << solution.lengthOfLongestSubstring(s) << endl;

    return 0;
}
