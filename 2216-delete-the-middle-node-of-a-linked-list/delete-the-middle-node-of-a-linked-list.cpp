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
    int getLength(ListNode* head){
        int len = 0;
        while(head != NULL){
            head = head -> next;
            len ++;
        }
        return len;
    }
    ListNode* deleteMiddle(ListNode* head) {
        int len = getLength(head);
        if(len <= 1){
            return NULL;
        }
        //Calculating the mid
        int mid = (len/2);
        ListNode* temp = head;
        int cnt = 1;
        while(cnt < mid){
            temp = temp -> next;
            cnt++;
        }
        temp -> next = temp -> next -> next;
        // temp -> next -> next = NULL;
        return head;
    
    }
};