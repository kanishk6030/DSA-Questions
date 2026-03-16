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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head == NULL) return NULL;

        //Dummy ka use isliye kiye hai ki agar 1 element ko delete pada toh kya krenge isliye dummy node ka use kiye hai

        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;

        while(curr != NULL){
            if(curr -> next != NULL && curr -> val == curr -> next -> val){
                int value = curr -> val;
                while (curr != NULL && curr -> val == value){
                    curr = curr -> next;
                }
                prev -> next = curr;
            }
            else{
                prev = curr;
                curr = curr -> next;
            }
        }
        return dummy -> next; 
        
    }
};