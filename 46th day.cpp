                    // remove duplicates i
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode * dummy = new ListNode(-1e8);
        ListNode * itr = dummy;
        ListNode * curr = head;
        while(curr != NULL)
        {
            if( itr->val != curr->val )
            {
                itr-> next = curr; 
                itr = itr -> next;
                curr = curr->next;
                
            }
            else{
                curr = curr->next;
            }
   
        }
        itr-> next = NULL;
        return dummy-> next;
        
    }
};

                    // remove duplicates ii


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(head == NULL || head-> next == NULL) return head;
        ListNode * dummy  = new ListNode(-1e8);
        ListNode * itr = dummy;
        itr -> next = head;  // for temp ans ;
        ListNode * curr = head -> next; // for checking
        while(curr != NULL)
        {
            bool ok = false; // init no rep ele
            while(curr != NULL && itr-> next -> val == curr -> val)
            {
                ok = true;
                curr = curr -> next;
            }
            if(ok == true)
            {
                itr -> next = curr ;
            }
            else{
                itr = itr-> next;
            }
            if(curr != NULL)
                curr = curr -> next;
            
        }
        return dummy-> next;
        
        
    }
};

                    // Rotate by k times


class Solution {
public:
    int getsize(ListNode * head)
    {
        int cnt = 0 ;
        while(head != NULL) 
        {
            cnt ++;
            head = head -> next;
        }
        return cnt;
    }
    ListNode* rotateRight(ListNode* head, int k) 
    {
        int n = getsize(head);
        if(head == NULL || head-> next == NULL || k == 0 || k == n   ) return head;
        
        
        k = k % n  ;  
        if( k == 0) return head;
        ListNode * slowprev = NULL;
        ListNode * slow = head;
        ListNode * fast = head;
        ListNode * fastprev = NULL;
        
        while(k -- && fast != NULL)
        {
            fastprev = fast;
            fast = fast -> next;
        }
        while(fast != NULL)
        {
            slowprev = slow;
            slow = slow -> next;
            fastprev = fast;
            fast = fast -> next;
        }
        if(slowprev != NULL)
            slowprev -> next = NULL;
        fastprev -> next = head;
        return slow;
        
        
    }
};

