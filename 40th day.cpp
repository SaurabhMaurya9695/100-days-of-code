#include<bits/stdc++.h>
using namespace std ;


                /* Creation of Linkde List */
/*```````````````````````````````````````````````````````````````````````````````````*/                

class Node{
public:
    int data ;
    Node *next;

};

class Linked_List{
public:
    Node * head ;
    Node * tail;
    int size = 0;
public:
    
    /*constructor*/
    Linked_List()
    {
        head = NULL;
        tail = NULL;
    }


/*`````````````````````````````````````addLast``````````````````````````````````````````````*/

            /* add at Last */
    void addLast(int x)
    {
        if(size == 0) // head = Tail = NULL;
        {
            Node *temp = new Node;
            temp->data = x;
            temp->next = NULL;
            head = tail = temp;
            size++;
        }
        else{
            Node *temp = new Node;
            temp->data = x;
            temp->next = NULL;

            tail->next = temp;
            tail = temp;
            size++;

        }
    }

/*````````````````````````````````Display```````````````````````````````````````````````````*/
    void display()
    {
        cout<<"Our Linked List is : ";
        Node * temp = head;
        while(temp != NULL)
        {
            cout<< temp->data<< " ";
            temp = temp->next;
        }
        cout<< endl;

    }

/*````````````````````````````````Get Value```````````````````````````````````````````````````*/

    void getFirst()
    {
        cout<< "our first value is : " << head->data << endl;
    }

    void getLast()
    {
        cout << "our Last value is : "  << tail->data << endl;
    }

    void getAtIdx1(int idx)
    {
        int cnt = 1 ;
        Node *temp = head;
        while(cnt != idx)
        {
            temp = temp->next;
            cnt++;
        }
        cout<<"our Idx value is : " <<  temp->data << endl;
    }

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

/*````````````````````````````````Add First````````````````````````````````````````````*/

    void addFirst(int val)
    {
        //Creation of Node
        Node * temp = new Node;
        temp->data = val;
        temp->next = NULL;
        if(size == 0)
        {
            head = tail = temp;
            size++;
        }
        else{
            temp->next = head;
            head = temp;
            size++;
            
        }
    }

    /*````````````````````````````````Add at idx First````````````````````````````````````````````*/
    void addAtIdx(int idx , int val)
    {
        if(idx < 0 || idx > size)
        {
            cout<<"Not Valid idx\n";
            return ;
        }
        if(idx == 0)
        {
            addFirst(val);
            return ;
        }
        else if(idx == size)
        {
            addLast(val);
            return ;
        }
        else{
            int cnt =  1;

            Node *temp = new Node;
            temp->data = val;
            temp->next = NULL;

            //for keeping safe head;
            Node *ptr = new Node;
            ptr = head;

            while(cnt < idx - 1)
            {
                ptr = ptr->next;
                cnt++;
            }

            // linking
            temp->next = ptr->next;
            ptr->next = temp;
        }   
    }

    /*````````````````````````````````Remove First````````````````````````````````````````````*/
    void removeFirst()
    {
        if(size == 0)
        {
            cout<<"Can't be possible\n";
            return ;
        }
        else if(size == 1)
        {
            head = tail = NULL;
            size--;
        }
        else{
            head = head->next;
            size--;
        }
    }

    /*````````````````````````````````Remove Last````````````````````````````````````````````*/

    void removeLast()
    {
        if(size == 0)
        {
            cout<<"Can't be possible\n";
            return ;
        }
        else if(size == 1)
        {
            head = tail = NULL;
            size--;
        }
        else{
            int cnt = 1 ;
            Node * temp = head ;
            while(cnt < size - 1 )
            {
                temp = temp->next;
                cnt++;
            }
            tail = temp;
            temp->next = NULL;
            size--;

            
        }

    }

/*``````````````````````````````````removeAtIdx```````````````````````````````````````*/

    void removeAtIdx(int idx)
    {
        if(idx < 0 || idx > size)
        {
            cout<<"Not Valid idx\n";
            return ;
        }
        if(idx == 0)
        {
            removeFirst();
            return ;
        }
        else if(idx == size)
        {
            removeLast();
            return ;
        }
        else{
            int cnt = 1;
            Node * temp  = head;
            while(cnt < idx - 1)
            {
                temp = temp ->next;
                cnt++;
            }

            temp->next = temp->next->next;
            size--;
        }   
    }

    /*````````````````````````````````Get the size````````````````````````````````````````````*/
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

    /*`````````````````````````````Get the MIddle Node of LL``````````````````````````*/

    void getMiddle()
    {
        int currsize =  (size + 1) / 2;
        getAtIdx(currsize) ;
    }

    /*`````````````````````````````reversePtr`````````````````````````````*/
    
    void reversePtr()
    {
        Node * prev = NULL;
        Node * curr = head;
        while(curr != NULL)
        {
            Node * nextsavingNode  = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextsavingNode;         
        }

        Node * temp = head;
        head = tail ;
        tail = temp;
    }

    /*`````````````````````````````reverseitertaive`````````````````````````````*/

    void reverseitr()
    {
        int start = 1;
        int end  = getSize() ;
        while(start <= end)
        {
            Node * firstnode = getAtIdx(start);
            Node *  secondNode = getAtIdx(end);

            //swap
            int temp = firstnode->data;
            firstnode->data = secondNode->data;
            secondNode->data = temp;

            
            start++;
            end--;
        }

    }
    /*``````````````````````````Kth Node from end ````````````````````````*/
    void KthNodeFromEnd(int k)
    {
        Node * slow = head;
        Node * fast = head ;
        // making a gap  of k between slow and fast ;
        while(k--)
        {
            fast = fast -> next;
        }
        while(fast != NULL)
        {
            slow = slow->next;
            fast = fast -> next;
        }
        cout<< "our kth last element is " << slow->data << endl;
    }

    void SlowFastMethodofMiddle()
    {
        Node * slow = head;
        Node * fast = head;
        while(fast != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        cout<<"ouer middle element is : " <<  slow->data << endl;

    }

    Linked_List merge(Linked_List* first , Linked_List* second)
    {
        Linked_List ans ; // empty LL
        Node * temp1 = first->head;
        Node * temp2 = second->head;
        while(temp1 != NULL && temp2 != NULL)
        {
            if(temp1 -> data > temp2-> data)
            {
                ans.addLast(temp2->data);
                temp2 = temp2->next;
            }
            else{
                ans.addLast(temp1->data);
                temp1 = temp1->next;
            }
        }

        while(temp1 != NULL)
        {
            ans.addLast(temp1->data);
            temp1 = temp1->next;
        }
        while(temp2 != NULL)
        {
            ans.addLast(temp2->data);
            temp2 = temp2->next;
        }
        return ans ;


    }

};


int main()
{
    Linked_List ll ;
    ll.addLast(1000);
    ll.addLast(250);
    // ll.display();
    // ll.getFirst();
    // ll.getLast();
    // ll.getAtIdx(2);
    ll.addFirst(55);
    ll.addFirst(9);
    ll.addFirst(-1);
    
    // add at index ke liye
    // int n , val;
    // cin>> n >> val;
    // ll.addAtIdx(n , val);

    // ll.removeFirst();
    // ll.removeLast();
    

    // ll.display();

    // ll.removeLast();
    // ll.display();
    
    // ll.getSize();
    // ll.getMiddle();

    // int n;
    // cin >> n;
    // ll.removeAtIdx(n);
    // ll.display();

    // ll.reversePtr();
    // ll.display();


    // ll.reverseitr();
    ll.display();


    // int endidx;
    // cin>> endidx;
    // ll.KthNodeFromEnd(endidx);

    // ll.SlowFastMethodofMiddle();

    Linked_List ll2;
    
    ll2.addLast(251);
    ll2.addLast(256);
    ll2.addLast(890);
    ll2.addFirst(90);
    ll2.addFirst(55);
    ll2.addFirst(-10);

    ll2.display();

    Linked_List res = ll.merge(&ll , &ll2);
    res.display();

}


/*`````````````````````Palindrom question on LL ~~~~~~~~~~~~~*/
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
    ListNode * reverse(ListNode * head)
    {
        ListNode * prev = NULL;
        ListNode * curr = head;
        while(curr != NULL)
        {
            ListNode * NextNode = curr->next ;
            curr->next =prev ;
            prev = curr;
            curr = NextNode;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head)
    {
        ListNode * rev = reverse(head);
        
        ListNode * temp = head;
        while(temp != NULL)
        {
            cout<< temp-> val << " " << rev->val << endl;
            if(temp -> val != rev->val)
            {
                return false;
            }
            else{
                temp = temp->next;
                rev = rev->next;
            }
        }
        return true;
    }
};
