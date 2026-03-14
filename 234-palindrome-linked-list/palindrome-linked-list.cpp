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
    ListNode* getMiddle(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;
        // while(fast != NULL && fast-> next != NULL){
        while(fast -> next != NULL && fast-> next -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* temp){
        ListNode* curr = temp;
        ListNode* next = NULL;
        ListNode* prev = NULL;
        while(curr != NULL){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head->next == NULL) return true;

        // Step 1 - find middle of the linked List
        ListNode* middle = getMiddle(head);

        // Step 2 = reverse the LinkedList
        ListNode* temp = middle -> next;
        middle -> next = reverseList(temp);

        // Step 3- Compare thereversed list from mid to start
        ListNode* head1 = head;
        ListNode* head2 = middle -> next;
        while(head2 != NULL){
            if(head1 -> val != head2 -> val ){
                return false;
            }
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
        
        //Step 4 -> repeat the process of reversing the list
        temp = middle -> next;
        middle -> next = reverseList(temp);

        return true;
    }
};