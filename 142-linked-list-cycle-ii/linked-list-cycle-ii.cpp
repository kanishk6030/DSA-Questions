/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
//Floyd's Cycle Detection Algorithm
    ListNode* intersectionPoint(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
         while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            return slow;
        }
        }
        return NULL;
    }
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return NULL;
        // ListNode* intersection = intersectionPoint(head); OR
        ListNode* fast = intersectionPoint(head);

        if(fast == NULL) return NULL; //No Cycle found

        ListNode* slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};