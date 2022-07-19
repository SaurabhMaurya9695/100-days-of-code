
#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    #define ll long long 
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // int  = arr.size() ;
        stack<ll> s;
        vector<ll> arr1(n);

        for (ll i = n - 1; i >= 0; i--)
        {		
            while (!s.empty() && arr[i] >= s.top())
                s.pop();

            if (s.empty())
                arr1[i] = -1;		
            else
                arr1[i] = s.top();	

            s.push(arr[i]);
        }
        return arr1;
    }
};


                                    // next greator element to the left ;

#include<bits/stdc++.h>
using namespace std ;

//24 11 13 21 3

// next greator element to the left 
void solve(vector<int> &arr , int n){
    stack<int> stk;
    vector<int> ngl ;// to store ans ;
    for(int i = 0 ; i< n; i ++)
    {
        while(stk.size() > 0 && stk.top() <= arr[i]){
            stk.pop(); // pop until we get greator element or stack gets empty ;
        }
        if(stk.size() == 0){
            ngl.push_back(-1);
        }
        else{
            ngl.push_back(stk.top()); // stk.top() >= arr[i] ;
        }
        
        stk.push(arr[i]) ; // each and every time we push yourself
    }
    for(int x : ngl)
    {
        cout<< x << " ";
    }
}

int main(){
    int n ;
    cin>> n ;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++)
    {
        cin>> arr[i] ;
    }
    
    solve(arr , n);
    
    
}


                                        // Next Smaller element to the left

#include<bits/stdc++.h>
using namespace std ;

//24 11 13 21 3

//Next Smaller element to the left
void solve(vector<int> &arr , int n){
    stack<int> stk;
    vector<int> nsl ;// to store ans ;
    for(int i = 0 ; i< n; i ++)
    {
        while(stk.size() > 0 && stk.top() >= arr[i]){
            stk.pop(); // pop until we get greator element or stack gets empty ;
        }
        if(stk.size() == 0){
            nsl.push_back(-1);
        }
        else{
            nsl.push_back(stk.top()); // stk.top() >= arr[i] ;
        }
        
        stk.push(arr[i]) ; // each and every time we push yourself
    }
    for(int x : nsl)
    {
        cout<< x << endl;
    }
}

int main(){
    int n ;
    cin>> n ;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++)
    {
        cin>> arr[i] ;
    }
    
    solve(arr , n);
    
    
}


                                            // next smallest element to the right
#include<bits/stdc++.h>
using namespace std ;

//24 11 13 21 3

// next smallest element to the right
void solve(vector<int> &arr , int n){
    stack<int> stk;
    vector<int> nsr ;// to store ans ;
    for(int i = n - 1 ; i >= 0; i-- )
    {
        while(stk.size() > 0 && stk.top() >= arr[i]){
            stk.pop(); // pop until we get greator element or stack gets empty ;
        }
        if(stk.size() == 0){
            nsr.push_back(-1);
        }
        else{
            nsr.push_back(stk.top()); // stk.top() >= arr[i] ;
        }
        
        stk.push(arr[i]) ; // each and every time we push yourself
    }
    reverse(nsr.begin(), nsr.end());
    for(int x : nsr)
    {
        cout<< x << endl;
    }
}

int main(){
    int n ;
    cin>> n ;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++)
    {
        cin>> arr[i] ;
    }
    
    solve(arr , n);
    
    
}
                        // Next Greator element II
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n = arr.size() ;
        int cnt= 2 ; // traverse the array two times ;
        stack<int> s;
        vector<int> arr1(n);
        while(cnt--)  // in circular stack or queue question you just have to traverse arrya two times
        {
            for (int i = n - 1; i >= 0; i--)
            {		
                while (!s.empty() && s.top() <= arr[i])
                    s.pop();

                if (s.empty())
                    arr1[i] = -1;		
                else
                    arr1[i] = s.top();	

                s.push(arr[i]);
            }
        }
        return arr1 ;
        
    }
};

                            // stack creation 

// push , pop , top , size , display , quit;
#include<bits/stdc++.h>
using namespace std ;

class stack{
    public :
    // decleration 
        int size ;
        int *arr;
        int top ;
    
    //constuctor;
    stack(int n){
        this->size = n;
        this->arr = new int[n];
        this->top = -1;
    }
    
    void insert(int val){
        if(top + 1 ==  size)
        {
            cout<<"stack overflow\n";
            return ;
        }
        top++;
        arr[top] = val;
    }
    
    int remove(){
        if(top == -1)
        {
            cout<< "stack underflow\n";
            return -1;
        }
        int x =arr[top];
        top--;
        return x;
    }
    
    int top()
    {
        if(top != -1)
        {
            int x = arr[top];
            return x;
        }
        else{
            return -1;
        }
    }
    
    int size(){
        return top + 1;
    }
    
    
    void display(){
        for(int i = top ; i>=0 ; i--)
        {
            cout<< arr[i] << " ";
        }
    }
}


int main()
{
    int n ;
    cin>> n; // i/p in n ;
    stack stk(n); // object creation of stack ; stk is our object ;
    
    string s;
    cin>> s; 
    if(s != "quit")
    {
        if(s ==  "push")
        {
            int val;
            cin>> val;
            stk.insert(val); // calling insert function 
        }
        else if(s == "pop"){
            if(stk.remove() == -1){
                cout<<"our stack is empty\n";
            }
            else{
                cout<< stk.remove() << endl;
            }
        }
        else if(s == "top"){
            if(stk.top() == -1)
            {
                cout<< "NO top exist \n";
            }
            else{
                cout<< stk.top() << endl;
            }
        }
        else if(s == "size"){
            cout<< stk.size() << endl;
        }
        else if(s == "display")
        {
            stk.display();
        }
    }
}

