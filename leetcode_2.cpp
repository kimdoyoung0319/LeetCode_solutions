#include <iostream>
using namespace std;

//A struct for node of list provided by the problem in LeetCode.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//Actual solution submitted to LeetCode.
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        int digit = 0, carry = 0;
        //A pointer that refers the first node of answer list.
        ListNode *result = new ListNode();
        //A pointer that refers to currently calculating digit.
        ListNode *current = result;

        do{
            /*
            When calculating each digit, this can be divided into 4 cases. 
            
            1. The first, and second lists are all not yet end.
               In this case, digits in first and second list, and carry are involved in the calculation.
            2. One of the lists are under calculation, while others not.
               In this case, only the list that has elements to calculate should be involved
            3. All of the lists are already traversed, while carry is left and non-zero.
               In this case, only the carry should be copied as the digit.
            4. The lists and carry are all empty and zero.
               In this case, calcuation is ended.
            
            Below if-else statement and condition for while loop check this cases.
            */
            if(l1 && l2){
                digit = (l1->val + l2->val + carry) % 10;
                carry = (l1->val + l2->val + carry) / 10;
            } else if(l1){
                digit = (l1->val + carry) % 10;
                carry = (l1->val + carry) / 10;
            } else if(l2){
                digit = (l2->val + carry) % 10;
                carry = (l2->val + carry) / 10;
            } else{
                digit = carry;
                carry = 0;
            }

            current->val = digit;
            //Important part. If you only check the next element of the list, you will get segmentaition fault.
            //This is because if l1 or l2 is nullptr, it won't be able to be accessed.
            //To solve this, you should first check if l1 or l2 is not nullptr.
            //Thanks to the short-circuit evalutaion in C and C++ language, you do not have to write separate if statement.
            if((l1 && l1->next) || (l2 && l2->next) || carry)
                current->next = new ListNode();
            current = current->next;

            //Advances pointers of l1 and l2 only if they are not nullptr.
            //This is also because a nullptr cannot be advanced.
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        } while((l1 || l2) || carry);

        return result;
    }
};

//A short convert function that converts integer array to list.
ListNode* arrayToList(int* array, int length){
    ListNode *result = new ListNode();
    ListNode *current = result;
    for(int i = 0; i < length; i++){
        current->val = array[i];
        if(i != length - 1)
            current->next = new ListNode();
        current = current->next;
    }

    return result;
}

//A short function that shows the members of the list.
void showList(ListNode *list){
    ListNode *current = list;
    while(current){
        cout << current->val;
        current = current->next;
    }
    cout << endl;

    return;
}

int main(void){
    Solution solution;
    int num1[3] = {2, 4, 9};
    int num2[3] = {5, 6, 4};

    ListNode *l1 = arrayToList(num1, 3);
    ListNode *l2 = arrayToList(num2, 3);

    showList(l1);
    showList(l2);

    ListNode *result;
    result = solution.addTwoNumbers(l1, l2);
    showList(result);

    return 0;
}
