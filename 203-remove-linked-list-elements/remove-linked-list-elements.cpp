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
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode * dummy = new ListNode(-1);
        dummy->next = head;

        ListNode*prev =dummy , *curr = head;

        while(curr)
        {
          
          while(curr && curr->val == val)
          {
            prev->next = curr->next;
            curr = curr->next;
          }
        
          if(!curr)
          break;

          prev = curr;
          curr = curr->next;

        }
        
        return dummy->next;
    }
};