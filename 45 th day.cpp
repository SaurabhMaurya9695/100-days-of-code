            // Cycle detection II


class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
        ListNode * hare = head;
        ListNode * turtle = head;
        
        while (hare != NULL && hare->next != NULL) {
            hare = hare->next->next;
            turtle = turtle->next;
            
            if (hare == turtle) {
                turtle = head;
                while (hare != turtle) {
                    hare = hare->next;
                    turtle = turtle->next;
                }
                return turtle;
            }
        }
        return NULL;
        
    }
};


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode * , bool > ump;
        ListNode * curr = head;
        while(curr != NULL)
        {
            if(ump.find(curr) != ump.end()) return curr;
            else{
                ump[curr] = true;
            }
            curr = curr -> next;
        }
        return nullptr;  
    }
};

                        //cycle detection 1

class Solution {
public:
    bool hasCycle(ListNode *head) 
    {
        unordered_map<ListNode * , bool > ump;
        ListNode * curr = head;
        while(curr != NULL)
        {
            if(ump.find(curr) != ump.end()) return true;
            else{
                ump[curr] = true;
            }
            curr = curr -> next;
        }
        return false;
        
    }
};

                    //intersection of Y LL

class Solution {
public:
    
    int getSize(ListNode * head)
    {
        ListNode * curr = head;
        int cnt = 0;
        while(curr != NULL)
        {
            cnt++;
            curr = curr -> next;
        }
        return cnt;
    }
    
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int size1 = getSize(headA);
        int size2 = getSize(headB);
        int diff = size2 - size1;
        // check for max ;
        if(size2 > size1)
        {
           
            for(int i = 0; i<size2 - size1 ;i++)
            {
                headB = headB->next ;
            }
            
        }
        else{
            for(int i = 0; i< size1 - size2 ;i++)
            {
                headA = headA->next;
            }
        }
        while(headA != headB)
        {
            headA = headA->next;
            headB = headB->next;
        }
        return headA; 
        
    }
};

                        // NOT ACCEPTED

Node * reverse(Node * head)
{
    if(head == NULL || head->next == NULL){
            return head;
    }
    Node * prev = NULL;
    Node * curr = head;
    while(curr != NULL)
    {
        Node * nextNode = curr -> next; // backup;
        curr -> next = prev;
        prev = curr;
        curr = nextNode ;
        
    }
    return prev;
}

Node* subLinkedList(Node* l1, Node* l2)
{
   Node * c1 = reverse(l1);
   Node * c2 = reverse(l2);
   Node * dummy = new Node(-1);
   Node * itr = dummy;
   int borrow = 0 ;
   while(c1 != NULL || c2 != NULL || borrow != 0)
   {
       int val1 = (c1 != NULL) ? c1 ->data : 0 ;
       int val2 = (c2 != NULL) ? c2 ->data : 0 ;
       int sum = val1 - val2  + borrow;
    //   cout<< sum << endl;
       if(sum < 0)
       {
           sum += 10;
           borrow = -1;
       }
       else{
           borrow = 0;
           sum = sum;
       }
       Node * temp = new Node(sum);
       itr->next = temp;
       itr = itr->next;
       if(c1 != NULL)
            c1 = c1->next;
       if(c2 != NULL )
            c2 =  c2-> next;
       
   }
   Node * ans = dummy -> next;
   
   
   Node * res =  reverse(ans);
   while(res -> data != 0)
   {
       res = res-> next;
   }
   return res;
   
}
