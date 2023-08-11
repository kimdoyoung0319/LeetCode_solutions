#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        int digit = 0, carry = 0;
        ListNode *result = new ListNode();
        ListNode *current = result;

        do{
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
            if((l1 && l1->next) || (l2 && l2->next) || carry)
                current->next = new ListNode();
            current = current->next;

            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        } while((l1 || l2) || carry);

        return result;
    }
};

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
