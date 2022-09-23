                    //segregate 012

class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
       Node * x = new Node(-1);
       Node * y = new Node(-1);
       Node * z = new Node(-1);
       
       Node * xt = x;
       Node * yt = y;
       Node * zt = z;
       int cntz =0 , cnto = 0 , cntt = 0;
       
       Node * curr = head;
       while(curr != NULL)
       {
           if(curr->data == 0)
           {
               xt->next = curr;
               xt = xt -> next;
               cntz++;
           }
           else if(curr -> data == 1)
           {
               yt ->next = curr;
               yt = yt -> next;
               cnto++;
           }
           else{
               zt ->next = curr;
               zt = zt -> next;
               cntt++;
           }
           curr = curr ->next;
       }
       
       if(cntz == 0 )
       {
            yt ->next = z ->next;
            zt ->next = NULL;
            return y -> next;
       }
        else if(cnto == 0 )
        {
            xt ->next = z ->next;
            zt ->next = NULL;
            return x ->next;
        }
        else if(cntt == 0)
        {
            xt ->next = y ->next;
            yt ->next = NULL;
            return x ->next;
        }
        else if(cntz > 0 && cnto > 0 && cntt > 0)
        {
            xt->next = y->next;
            yt->next = z-> next;
            zt -> next = NULL;
            return x -> next;
        }
        
    }
};


                        //swapping the data in LL


class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) 
    {
        //Kth Node form the end;
        ListNode * slow = head;
        ListNode * fast = head;
        int fk = k;
        //we want the gap of k ;
        while(k--)
        {
            fast = fast->next;
        }
        while(fast != NULL)
        {
            slow = slow -> next;
            fast = fast -> next;
        }
        
        ListNode * curr2 = slow;
        
        //start kth node;
        ListNode * curr = head;
        while(fk != 1)
        {
            curr = curr -> next;
            fk--;
        }
        // cout<< curr->val << " " <<curr2->val << endl;
        
        int temp = curr2->val;
        curr2->val = curr->val;
        curr->val = temp;
        
        return head;
        
    }
};


                    // reverse Nodes in k groups && swap nodes in k groups

class Solution {
public:
    

    ListNode * th = NULL;
    ListNode * tt = NULL;
    
    void addFirst(ListNode * node)
    {
        if(th == NULL)
        {
            th = node;
            tt = node;
        }
        else{
            node->next = th;
            th = node;
        }
    }
        
    int getSize(ListNode * head) //o(n);
    {
        int cnt = 0 ;
        ListNode *temp = head;

        while(temp != NULL)
        {
            temp=  temp ->next;
            cnt++;
        }
        return cnt;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head; 
        ListNode * curr = head;
        int n = getSize(head);
        ListNode * oh = NULL;
        ListNode * ot = NULL;
        while(n >= k)
        {
            int tempk = k;
            while(tempk-- > 0)
            {
                ListNode * next = curr->next;
                curr->next = NULL;
                addFirst(curr);
                curr = next;
            }
            if(oh == NULL)
            {
                oh = th ;
                ot = tt;
            }
            else{
                ot->next = th;
                ot = tt;
            }   
            
            th = NULL;
            tt = NULL;
            n -= k;
        }
        
        ot->next = curr;
        return oh;
        
    }
};
