                    //ODD EVEN LINKED LIST
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) 
    {
        ListNode * evenhead = new ListNode (-1);
        ListNode * oddhead = new ListNode(-1);
        ListNode * eventail = evenhead;
        ListNode * oddtail = oddhead;
        ListNode * curr = head;
        int  cnt = 0 ;
        while(curr != NULL)
        {
            if(cnt % 2 == 0)
            {
                eventail->next = curr;
                eventail = eventail->next;
            }
            else{
                oddtail->next = curr;
                oddtail = oddtail->next;
            }
            curr = curr->next;
            cnt++;
        }
        eventail->next = oddhead->next;
        oddtail->next = NULL;
        return evenhead->next;
    }
};

                    // add two numbers

class Solution {
public:
  
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        if(l1 == NULL || l2 == NULL) return (l1 == NULL ? l2 : l1);
        ListNode * c1 =  (l1);
        ListNode * c2 =  (l2);
        ListNode * dummy  = new ListNode(-1);
        ListNode * itr = dummy;
        int carry = 0;
        while(c1 != NULL || c2 != NULL || carry != 0 )
        {
            int c1data = ( c1 != NULL ? c1->val : 0 ) ;
            int c2data = ( c2 != NULL ? c2->val : 0 ) ;
            int sum = ( c1data + c2data  + carry );
            int rem = sum % 10;
            carry = sum / 10;
            ListNode * temp = new ListNode(rem);
            itr->next = temp;
            itr = itr->next;
            if(c1 != NULL)
            {
                c1 = c1->next;
            }
           if(c2 != NULL)
            {
                c2 = c2->next;
            }
            
        }
        
        // ListNode * ans = reverseList(dummy->next);
        return dummy->next ;
     
    }
};

                    // Linked List cycle

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
    bool hasCycle(ListNode *head) 
    {
        ListNode * slow = head;
        ListNode * fast = head;
        while( fast != NULL && fast -> next != NULL )
        {
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast ) return true;
        }
        return false;
    }
};
