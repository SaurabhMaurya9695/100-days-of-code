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

    void getAtIdx(int idx)
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
        else{
            
            Node *prev  = head;
            Node *curr = head;

            while(curr-> next != tail)
            {
                curr = curr->next;
            }

            curr->next = NULL;
            delete(tail);
            size--;

        }

    }

    /*````````````````````````````````Get the size````````````````````````````````````````````*/
    void getSize()
    {
        int cnt = 0 ;
        Node *temp = head;

        while(temp != NULL)
        {
            temp=  temp ->next;
            cnt++;
        }
        cout<< "size of LL is : " <<  cnt << endl;
    }

    /*`````````````````````````````Get the MIddle Node of LL``````````````````````````*/

    void getMiddle()
    {
        int currsize =  (size + 1) / 2;
        getAtIdx(currsize) ;
    }

};


int main()
{
    Linked_List ll ;
    ll.addLast(5);
    ll.addLast(10);
    ll.addLast(25);
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
    

    ll.display();
    // ll.getSize();
    ll.getMiddle();

}
