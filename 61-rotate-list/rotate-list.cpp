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
    ListNode* rotateRight(ListNode* head, int k) {

        if(!head)
        return NULL;

        int n = 1;
        ListNode * tail = head;
        
        while(tail->next)
        {
            n++;
            tail = tail->next;
        }

        k = k % n;
        
        // making it circular linked list
        tail->next = head;

        // now new head is at n-k steps from this head 
        // but before we have to remove n-k-1 steps link
        
        int steps = n-k-1;
        while(steps--)
        {
            head = head->next;
        }

        ListNode * temp = head;
        
        head = head->next; // now head is at it's correct pos
        temp->next = NULL; // removed prev link;

        return head;

    }
};