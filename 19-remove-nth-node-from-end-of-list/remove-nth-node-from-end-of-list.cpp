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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
     int len = getLength(head);

     if(n == len)   // removing head
        return head->next;

     int pos = len - n;
     int cnt = 1;
     ListNode* temp = head;
     while(cnt < pos){
        temp = temp -> next;
        cnt ++;
     }   
     temp -> next = temp -> next -> next;
     return head;
    }
};