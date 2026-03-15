/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void insertAtTail(ListNode* &ansHead,ListNode* &ansTail,int digit){
        ListNode* temp = new ListNode(digit);
        if(ansHead == NULL){
            ansHead = temp;
            ansTail = temp;
            return;
        }
        else{
            ansTail -> next = temp;
            ansTail = temp;
        }
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;
        
        int carry = 0;

        while(l1 != NULL || l2 != NULL || carry != 0){

            int val1 = 0;
            if(l1 != NULL) val1 = l1 -> val;

            int val2 = 0;
            if(l2 != NULL) val2 = l2 -> val;

             int sum = carry + val1 + val2;
            int digit = sum % 10;
            //create a node for the digit and add in the answer node
            insertAtTail(ansHead,ansTail,digit);
            carry = sum / 10;

            if(l1 != NULL) l1 = l1 -> next;
            if(l2 != NULL)l2 = l2 -> next;
        }

        return ansHead;
    }
};