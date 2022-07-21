// // check two string equal or not ;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& s1, vector<string>& s2) {
        string ans1= "";
        string ans2= "";
        for(auto x: s1)
        {
            ans1 += x;
        }
        for(auto y : s2){
            ans2 += y;
        }
        return (ans2 == ans1);
        
    }
};

// // make the string great
class Solution {
public:
    string makeGood(string s) {
        int n = s.size() ;
        stack<char> stk;
        for(int i = 0 ; i< n ; i++)
        {
            
            if(stk.size() > 0 && (abs(stk.top() - s[i]) == 32))
            {
                stk.pop();
                continue;
            }
            stk.push(s[i]);
        }
        string ans = "";
        while(!stk.empty())
        {
            ans += stk.top();
            stk.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};

#include<bits/stdc++.h>
using namespace std ;

string solve(string s)
{
    string ans = "";
    stack<string> stk;
    int n = s.size() ;
    for(int i = 0 ; i< n ; i++)
    {
        if(s[i] != ' ' && i < n)
        {
            ans += s[i];
        }
        stk.push(ans);
        ans = "";
    }
    string temp = "";
    while(!stk.empty())
    {
        temp =  temp + stk.top() + " ";
        stk.pop();
    }
    return temp;
}

int main()
{
    string s = "hey, how are you doing?";
    cout<< solve(s) << endl;
}




                    // Queue using arrays

// by using stl
// int main()
// {
//     // using stl
//     // queue<data_type> q;
//     //empty() , size() , front() , back() , push(g)  , pop() 
    
//     queue<int> q;
//     q.push(1);
//     q.push(2);
//     q.push(3);
//     // cout<<q.size() << endl;
//     // cout<< q.front() << endl;
//     // cout<< q.back() << endl;
    
//     while(!q.empty())
//     {
//         cout<< q.front() << " ";
//         q.pop();
//     }
    
// }


#include<bits/stdc++.h>
using namespace std;

class Queue
{
    public:
        int size;
        int front;
        int rear;
        int *arr;
        
    // constrcutor
    Queue(int n)
    {
        this->size = n;
        this->rear = 0;
        this->front = 0;
        this-> arr = new int[n];
    }
    
    void enqueu(int x)
    {
        if(rear + 1 == size)
        {
            cout<<"Queue overflow\n";
            
        }
        else{
            arr[rear] = x;
            rear ++;
        }
    }
    
    int dequeu() // remove
    {
        if(front == rear)
        {
            cout<<"queue underflow\n";
            return -1;
        }
        else {
            int x = arr[front];
            for (int i = 0; i < rear - 1; i++) {
                arr[i] = arr[i + 1];
            }
 
            // decrement rear
            rear--;
        }
        return x;
        
    }
    
    int back()
    {
        if(rear + 1 == size)
        {
            cout<<"back doesn't exist\n";
            return -1;
        }
        else{
            return arr[rear];
        }
    }
    
    int front()
    {
        return arr[front];
    }
    
    int size()
    {
        return rear - front + 1 ;
    }
    
    void display()
    {
        for(int i = front ; i < rear ; i++)
        {
            cout<< arr[front] << " " ;
        }
    }
    
    
    
}



int main()
{
    string s;
    cin>> s;
    Queue q(5);
    while(s[i] != "quit")
    {
        if(s[i] == "insert") // insert
        {
            int x;
            cin>> x;
            q.enqueu(x);
        }
        else if(s[i] == "delete")
        {
            if(q.dequeu() != -1)  
            {
                cout<< q.dequeu() << endl;
            }
        }
        else if(s[i] == "back")
        {
            if(q.back() != -1) 
            {
                cout<< q.back<< endl;
            }
        }
        else if(s[i] == "front")
        {
            cout<< q.front() << endl;
        }
        else if(s[i] == "size")
        {
            cout<< q.size() << endl;
        }
        else if(s[i] == "display")
        {
            q.display();
        }
    }
} 
