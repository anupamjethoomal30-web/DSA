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
    ListNode * reverseLL(ListNode * temp)
    {
      if(!temp)
      return NULL;

      if(!temp->next)
      return temp;

      ListNode *prev = NULL , *curr = temp;

      while(curr)
      {
        ListNode * fut = curr->next;

        curr->next = prev;

        prev = curr;
        curr = fut;
      }
      
      return prev;
    }

    ListNode * getKthNode(ListNode * temp , int k)
    {   
        ListNode * curr = temp;
        k--;
        
        while(curr != NULL && k>0)
        {
           k--;
           curr = curr->next;
        }
        return curr;
    }


    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * temp = head;
        ListNode * prevLast = NULL;

        
        while(temp)
        {
          
          ListNode * KthNode = getKthNode(temp,k);
          
          if(!KthNode)
          {
            if(prevLast)
            prevLast->next = temp;

            break;
          }

          ListNode * nextNode = KthNode->next;
          KthNode->next = NULL;

          reverseLL(temp);

          if(head == temp)
          {
            // means it is first group
            head = KthNode;
          }
          else
          {

            prevLast->next = KthNode;
          }

          prevLast = temp;

          temp = nextNode;

        }
        
        return head;
    }
};