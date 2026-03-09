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
    ListNode* kReverse(ListNode* head,int k){
        //Base Call
        if(head == NULL){
            return NULL;
        }

        // Step 0: Check if k nodes exist
        ListNode* temp = head;
        int count = 0;
        
        while(temp != NULL && count < k){
            temp = temp->next;
            count++;
        }
        
        // If less than k nodes → don't reverse
        if(count < k)
            return head;

        //Step 1: Reverse first k nodes
        ListNode* next = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        count = 0;
        while(curr != NULL && count < k){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        //Step 2 : Recursion dekhega aage ka 
        if(next != NULL){
            head -> next = kReverse(next,k);
        }

        //Step 3 : Return head of reversed list
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        return kReverse(head , k);
    }
};