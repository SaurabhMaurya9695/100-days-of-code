                    // reverse a LL ;
            
            //Method 1;

/*  overall ->  o(n) + o(n * o(2n))
    overall ->  o(n) + o(n * n)
    overall -> o(n ^ 2);

Node* getAtIdx(int idx)
{
    int cnt = 1 ;
    Node *temp = head;
    while(cnt != idx)
    {
        temp = temp->next;
        cnt++;
    }
    return  temp;  
}
int getSize()
{
    int cnt = 0 ;
    Node *temp = head;

    while(temp != NULL)
    {
        temp=  temp ->next;
        cnt++;
    }
    // cout<< "size of LL is : " <<  cnt << endl;
    return cnt;
}

void reverseitr()
    {
        int start = 1;
        int end  = getSize() ;  //  o(n) ;
        while(start <= end) // o(n);
        {
            Node * firstnode = getAtIdx(start); //o(n);
            Node *  secondNode = getAtIdx(end); // o(n)

            //swap
            int temp = firstnode->data;
            firstnode->data = secondNode->data;
            secondNode->data = temp;

            
            start++;
            end--;
        }

    }
*/

            // Method 2

//overall -> o(n);
/*
class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        ListNode * prev = NULL;
        ListNode * curr = head;
        while(curr != NULL)    //o(n);
        {
            ListNode * nextsavingNode  = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextsavingNode;         
        }
        
        return prev;
        
    }
};

*/

                // Method 3 ;


//overall complexity - > o(n);
/*

class Solution {
public:
    // creation of Node
    ListNode * th = NULL;
    ListNode * tt = NULL;
    void addFirst(ListNode * currnode)  //o(1)
    {
        if(currnode == NULL)
        {
            th = currnode;
            tt = currnode;
        }
        else{
            currnode->next = th;
            th = currnode;
        }
    }
    
    
    ListNode* reverseList(ListNode* head) 
    {
        if(head == NULL || head->next == NULL) return head;
        ListNode * curr = head;
        while(curr != NULL)   //o(n);
        {
            //backup
            ListNode * nextNode = curr->next;
            //breaking link
            curr->next = NULL;
            addFirst(curr);
            curr = nextNode;
        }
        return th;
        
    }
};
*/




// ```````````````````````````reverse in k groups```````````````````````````````````````````````````````

class Solution {
public:
    

    //overall-> o(n) + o(n) -> 2 * o( n) => o(n);


    // addfirst
    ListNode * th = NULL;
    ListNode * tt = NULL;
    void addFirst(ListNode * currnode)  //o(1)
    {
        if(currnode == NULL)
        {
            th = currnode;
            tt = currnode;
        }
        else{
            currnode->next = th;
            th = currnode;
        }
    }
    
    //size;
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
    
    
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        
        if(head == NULL || head->next == NULL || k == 0) return  head;
        int length = getSize(head); //o(n)
        ListNode * oh = NULL;
        ListNode * ot = NULL;
        ListNode * curr = head;
        while(length  >= k) //o(1)
        {
            int tempk = k;
            while(tempk -- > 0) //k + k + k + k + ..... till not equal to n; => o(n);
            {
                ListNode * p = curr->next;
                curr->next = NULL;
                addFirst(curr);
                curr = p;                
            }
            if(oh == NULL)
            {
                oh = th;
                ot = tt;
            }
            else{
                // if(ot->next == NULL)retur
                ot->next = th;
                ot = tt;
            }
            th = NULL;
            tt = NULL;
            length  = length - k;
        }
        ot -> next = curr;
        return oh;
    }
};


// `````````````````````````````Merge Sort```````````````````````````````````


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode * dummy = new  ListNode(-1);
        ListNode * prev = dummy;
        ListNode * c1 = list1;
        ListNode * c2 = list2;
        while(c1 != NULL &&  c2 != NULL)
        {
            if(c1->val > c2->val)
            {
                prev->next = c2;
                c2 = c2->next;              
            }
            else{
                prev->next = c1;
                c1 = c1->next;
                
            }
            prev = prev->next ;
        }
        if(c1 != NULL)
        {
            prev->next = c1;
        }
        else
        {
            prev->next = c2;
        }
        return dummy->next;
        
    }
    
    ListNode * mid(ListNode * head)
    {
        if(head == NULL || head->next == NULL) return head;
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast->next != NULL && fast->next->next != NULL )
        {
            slow = slow->next;
            fast = fast->next->next;
        }

       return  slow ;
    }
    
    ListNode* sortList(ListNode* head) 
    {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        
        ListNode * left = mid(head);
        ListNode * right = left->next;
        left -> next = NULL;
        
        ListNode * ll1 = sortList(head);
        ListNode * ll2 = sortList(right);
        return mergeTwoLists(ll1 , ll2);
        
    }
};
