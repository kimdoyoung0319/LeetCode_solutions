#include <iostream>
#include <algorithm>
using namespace std;

//Actual solution submitted to LeetCode.
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mergedVec = nums1;
        //Indexes that indicates to the place where the current element should be inserted, and where the previous element have been inserted.
        int insert, prevInsert = 0;

        //For all elements in nums2, find the insertion point in nums1 from previous insertion point to the end of num1 (or mergedVec).
        for(auto elem = nums2.begin(); elem != nums2.end(); elem++){
            insert = lower_bound(mergedVec.begin() + prevInsert, mergedVec.end(), *elem) - mergedVec.begin();
            mergedVec.insert(mergedVec.begin() + insert, *elem);
            prevInsert = insert;
        }

        //Returns the median considering if the number of elements of mergedVec is odd or even.
        int size = mergedVec.size();
        if(size % 2)
            return mergedVec[size / 2];
        else
            return (mergedVec[size / 2] + mergedVec[size / 2 - 1]) / 2.;
    }
};

/* Quick explanation about why using integer index 'insert', 'prevInsert' rather than iterator when finding places for elements of nums2 in mergedVec:
   In the findMedianSortedArrays function, I used a variable 'prevInsert' to indicate the previous insertion point because it can save some amount of time by skipping unnecessary searching.
   When doing this by an iterator, you may get an segmentation fault caused by iterator invalidation.
   This happens because after insertion, the iterator pointing to an element of mergedVec will be invalidated because the structure of mergedVec is changed due to the insertion.
   always keep in mind that the iterator is an abstraction of pointers, so you will get a problem when handling it as if it is just index.*/

int main(void){
    vector<int> nums1 = {1, 2}, nums2 = {3, 4};
    string input;
    Solution solution;
    double result;

    result = solution.findMedianSortedArrays(nums1, nums2);

    cout << result << endl;

    return 0;
}
