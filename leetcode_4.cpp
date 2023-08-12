#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mergedVec = nums1;
        int insert, prevInsert = 0;

        for(auto elem = nums2.begin(); elem != nums2.end(); elem++){
            insert = lower_bound(mergedVec.begin() + prevInsert, mergedVec.end(), *elem) - mergedVec.begin();
            mergedVec.insert(mergedVec.begin() + insert, *elem);
            prevInsert = insert;
        }

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
   This happens because after insertion, the iterator pointing to an element of mergedVec will be invalidated because the structure of mergedVec is changed because of the insertion.
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
