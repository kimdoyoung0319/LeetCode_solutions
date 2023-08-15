#include <iostream>
#include <vector>

using namespace std;

//Actual solution class.
class Solution{
public:
    int reverse(int x){
        int result = 0, digit = 1;
        //The maximum absolute value a signed integer can represent.
        vector<int> num, maxAbs = {2, 1, 4, 7, 4, 8, 3, 6, 4, 7};
        bool negative = (x < 0);
        //If x < 0, the last digit of max. abs. value changed into 8.
        *(maxAbs.rbegin()) = negative ? 8 : 7;
        
        //In C/C++ arithmetic, if the divided is negative, the quotient and remainder is negative (or zero) too.
        //To store digits of abs. value of x, change the remainder to positive.
        while(x){
            num.push_back(negative ? -(x % 10) : (x % 10));
            x /= 10;
        }
        
        //First, compare the sizes of maxAbs and num.
        //Because they are both absolute and do not have any leading zero, the length can be directly used to compare them.
        if(num.size() > maxAbs.size()) return 0;
        //If the lengths are same, compare them digit-by-digit.
        else if(num.size() == maxAbs.size()){
            for(auto it = num.begin(); it != num.end(); it++){
                /*
                There is three cases when comparing digit.
                
                The first case is when the digit of maxAbs is smaller than that of num.
                In this case, the reverse integer is larger or smaller than int_max or int_min, so we return 0.
                
                The second case is when the digit of maxAbs is larger than that of num.
                In this case, no additional comparison of smaller digits is needed so we break the loop.
                
                The last case is when the both of of digits are same, where additional comparison of smaller digits is needed.
                */
                if(maxAbs[it - num.begin()] < *it) return 0;
                else if(maxAbs[it - num.begin()] > *it) break;
            }
        }
        
        for(auto it = num.rbegin(); it != num.rend(); it++){
            result += (*it) * digit;
            //When calculating last digit, variable digit might get overflowed.
            //I could not find any elegant solution for this problem, so I hard-coded and compared it.
            digit *= (digit == 1000000000) ? 1 : 10;
        }
        
        return negative ? -result : result;
    }
};

int main(void){
    int x, result;
    string s;
    Solution solution;
    
    cout << "Type the number you want to test: ";
    cin >> s;
    x = stoi(s);
    
    result = solution.reverse(x);
    cout << "The result is: " << result << endl;
    
    return 0;
}