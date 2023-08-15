#include <iostream>
#include <vector>

using namespace std;

//A simple matrix-printing function for test purpose.
//It was used to test zigzagVec conversion and deleted in final submit.
void printCharMatrix(vector<vector<char>> vec){
    for(auto row = vec.begin(); row != vec.end(); row++){
        for(auto col = row->begin(); col != row->end(); col++)
            cout << *col << ' ';
        cout << endl;
    }
    
    return;
}

//Actual solution class.
class Solution {
public:
    string convert(string s, int numRows) {
        //A matrix that represents the converted string.
        vector<vector<char>> zigzagVec;
        //A 'unit' is defined as the sequence of characters that is from a peak character to next peak.
        //Integer unitLen is the length of these units, and initialized as 2 * (numRows - 1) except the case that numRows == 1.
        //In the case that numRows == 1, the above equation dosen't work because the correct unitLen is 1.
        int unitLen = (numRows == 1) ? 1 : 2 * (numRows - 1);
        string result;
        
        for(int i = 0; i < s.length(); i++){
            //Initializes vector that represents a column.
            //It initialized with non-alphabet character 0 to specify it is blank.
            vector<char> col(numRows, '0');
            
            //When the index is divisible with the unitLen, it means the character represented by the index is in peak.
            if((i % unitLen) == 0){
                //If the index is at peak, store next {numRows} charactors to the column
                for(int j = 0; j < numRows && i + j < s.length(); j++)
                    col[j] = s[i + j];
                //...and advances the index as numRows.
                i += numRows - 1;
            } else{
                //If the index is not at the peak, store the character to right place in zigzag conversion.
                col[unitLen - i % unitLen] = s[i];
            }
            
            zigzagVec.push_back(col);
        }
        
        //With the zigzag matrix, make the zigzag string ignoring all character 0.
        for(int i = 0; i < numRows; i++){
            for(auto row = zigzagVec.begin(); row != zigzagVec.end(); row++){
                if((*row)[i] != '0')
                    result.push_back((*row)[i]);
            }
        }
       
        return result;
    }
};

int main(void){
    Solution solution;
    string result, s;
    int numRows;
    
    cout << "Enter the string you want to convert: ";
    cin >> s;
    cout << "Enter the number of rows: ";
    cin >> numRows;
    result = solution.convert(s, numRows);
    
    cout << result << endl;
    
    return 0;
}