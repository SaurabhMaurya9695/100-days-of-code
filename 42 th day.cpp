                    //palindrome LInkde List
class Solution {
public:
    
                //method 1;
    //TLE
  /*  {
    //o(n)
//     int getSize(ListNode* head)
//     {
//         int cnt = 0;
//         ListNode* temp = head;
//         while(temp != NULL)
//         {
//             temp = temp->next;
//             cnt++;
//         }
//         return cnt ;
//     }
    
//     //o(idx)
//     ListNode* getAtidx(int idx , ListNode* head)
//     {
//         int cnt = 1 ;
//         ListNode *temp = head;
//         while(cnt != idx)
//         {
//             temp = temp->next;
//             cnt++;
//         }
//         return  temp;  
//     }
//     bool isPalindrome(ListNode* head) 
//     {
//         int start = 1;
//         int end = getSize(head) ;
        
//         //o(n)
//         while(start <= end)
//         {
//             ListNode * firstNode = getAtidx(start , head) ;
//             ListNode * lastNode = getAtidx(end , head);
//             if(firstNode->val != lastNode->val)
//             {
//                 return false;
//             }
//             start++;
//             end--;
//         }
//         return true;
        
//     }
    }
    */
                //method 2;
    /* {
    bool check(string s)
    {
        int start = 0;
        int end= s.size() - 1;
        while(start < end)
        {
            if(s[start] != s[end] )
            {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    
    bool isPalindrome(ListNode* head)
    {
        string ans ="";
        ListNode * temp = head;
        while(temp != NULL)
        {
            ans += to_string(temp->val);
            temp = temp->next;
        }
        
        return check(ans);
    }
    }
    */
    
                //method 3
    // o(n) ;
    // ListNode * reverse(ListNode * head)
    // {
    //     ListNode * prev = NULL;
    //     ListNode * curr = head;
    //     while(curr != NULL)
    //     {
    //         ListNode * NextNode = curr->next ;
    //         curr->next =prev ;
    //         prev = curr;
    //         curr = NextNode;
    //     }
    //     return prev;
    // }
    // bool isPalindrome(ListNode* head)
    // {
    //     ListNode * rev = reverse(head);
        
    //     ListNode * temp = head;
    //     while(temp != NULL)
    //     {
    //         cout<< temp-> val << " " << rev->val << endl;
    //         if(temp -> val != rev->val)
    //         {
    //             return false;
    //         }
    //         else{
    //             temp = temp->next;
    //             rev = rev->next;
    //         }
    //     }
    //     return true;
    // }


                    // Method 4

    ListNode* middleNode(ListNode* head) {
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
    
    ListNode* reverseList(ListNode* head) 
    {
        if(head == NULL || head->next == NULL) return head;
        ListNode * prev = NULL;
        ListNode * curr = head;
        while(curr != NULL)
        {
            ListNode * nextsavingNode  = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextsavingNode;         
        }

        return prev;

    }
    bool isPalindrome(ListNode* head) 
    {
        if(head == NULL || head->next == NULL) return true;
        ListNode * mid = middleNode(head);
        ListNode * nextptr = mid -> next ;
        mid->next = NULL;
        ListNode * revLL = reverseList(nextptr);
        ListNode * curr1 = head;
        ListNode * curr2 = revLL;
        
        while(curr1 != NULL && curr2 != NULL)
        {
            if(curr1 -> val != curr2-> val)
            {
                return false;
            }
            curr1 = curr1->next;
            curr2 = curr2 -> next;
            
        }
        return true;      
    }
};



                        //REmove Linked List element
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
    ListNode* removeElements(ListNode* head, int val) 
    {
        if(head == NULL) return head;
        ListNode * dummy = new ListNode(-1);
        dummy->next = head;
        ListNode * temp = dummy;
        while(temp != NULL && temp->next != NULL)
        {
            if(temp->next->val == val)
            {
                ListNode * nextNode = temp->next;
                temp->next = nextNode->next;
                delete(nextNode);
                
            }
            else{
                temp= temp->next;
            }
        }
       
        return dummy->next;        
    }
};


                        // Reorder LL 


class Solution {
public:
    
    ListNode* middleNode(ListNode* head) {
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
    
    ListNode* reverseList(ListNode* head) 
    {
        if(head == NULL || head->next == NULL) return head;
        ListNode * prev = NULL;
        ListNode * curr = head;
        while(curr != NULL)
        {
            ListNode * nextsavingNode  = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextsavingNode;         
        }

        return prev;

    }
    
    void reorderList(ListNode* head) 
    {
        if(head == NULL || head->next == NULL)
        {
            return ;
        }
        
        ListNode * mid = middleNode(head);
        
        ListNode * nextNode = mid ->next;
        mid -> next = NULL;
        
        ListNode * revLL = reverseList(nextNode);
        
        //given new name ;
        ListNode * c1 = head;   // head -> mid ;
        ListNode * c2 = revLL;  //reverse LL from mid + 1 ;
        ListNode * f1 = NULL;
        ListNode * f2 = NULL;
        
        while(c1 != NULL && c2 != NULL)
        {
            // backup;
            f1 = c1->next ;
            f2 = c2->next;
            
            
            // link ;
            c1->next = c2;
            c2->next = f1;
            
            //update
            c1 = f1 ;
            c2 = f2;
            
            
        }
        
    }
};


