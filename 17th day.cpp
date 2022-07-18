                // stack using arrays

#include <iostream>
#include <exception>
using namespace std;

class Stack {

public:
  int* arr;
  int tos; // top of stack
  int MaxCapacity;

public:
    //constructor
  Stack(int size) {
    this->MaxCapacity = size;
    this->arr = new int[this->MaxCapacity];
    this->tos = -1;
  }

public:
  Stack() {
    Stack(10);
  }

public:
  int size() {
    // write your code here
    return tos + 1; // adding one because of zero base indexing
  }

public:
  void push(int data) {
    // we can push until our stack is overflow;
    if(tos + 1== MaxCapacity){
        cout<< "Stack overflow\n" ;
        return;
    }
    tos++; // first we incr our top then push
    arr[tos] = data;
    
  }

public:
  int top()
  {
    if(tos == -1)
    {
        cout<< "Stack underflow\n";
        return -1 ;
    }
    return arr[tos];
  }

public:
  int pop()
  {
    // we can pop until our tos = -1 ;
    if(tos == -1)
    {
        cout<< "Stack underflow\n";
        return -1 ;
    }
    int val = arr[tos];
    tos--;
    return val ;
    
  }

public:
  void display() {
    //start from tos ;
    for(int i  = tos ; i>=0 ; i--)
    {
        cout<< arr[i] <<" ";
    }
    cout<< endl;
  }
};

int main() {
  int n;
  cin >> n;
  Stack st(n);
  string str;
  cin >> str;

  while (str != "quit") {
    if (str == "push") {
      int val;
      cin >> val;
      st.push(val);
    } else if (str == "pop") {
      int val = st.pop();
      if (val != -1) {
        cout << val << endl;
      }
    } else if (str == "top") {
      int val = st.top();
      if (val != -1) {
        cout << val << endl;
      }

    } else if (str == "size") {
      cout << st.size() << endl;
    } else if (str == "display") {
      st.display();
    }
    cin >> str;
  }
}

// pop , push , top ;

// valid parenthesis ;

class Solution {
public:
    bool isValid(string s) {
        stack<char>  stk;
        int n = s.size() ;
        for(int i = 0; i< n ; i++ )
        {
            if(s[i] == ')')
            {
                if(stk.size() == 0) return false;
                if(stk.top() == '(')
                {
                    stk.pop();
                }
                else{
                    return false;
                }
            }
            else if(s[i] == '}')
            {
                if(stk.size() == 0) return false;
                if(stk.top() == '{')
                {
                    stk.pop();
                }
                else{
                    return false;
                }
            }
            else if(s[i] == ']')
            {
                if(stk.size() == 0) return false;
                if(stk.top() == '[')
                {
                    stk.pop();
                }
                else{
                    return false;
                }
            }
            else {
                // openins are coming ;
                stk.push(s[i]) ;
            }
        }
        if(stk.size()== 0)
            return true;
        else{
            return false;
        }
    }
};

// duplicate brackets ;
#include<bits/stdc++.h>
using namespace std ;

bool solve (string s) //(a + b ) + (( c +  d))  
{
    int n = s.size() ;
    stack<char> stk;
    for(int i = 0 ; i< n ; i++)
    {
        if(s[i] == ')')
        {
            if(stk.top() == '(') {
                return true; // ()
            }
            else 
            {
                while(stk.top() != '(')
                {
                    stk.pop();
                }
                stk.pop();
            }
        }
        else{
            // s[i] = ' variable , + , ( ;
            stk.push(s[i]) ;
            
        }
    }
    return false;
}


int main()
{
    string s;
    cin>> s;
    if( solve(s) == true) {
        cout<< "true\n";
        
    }
    else{
        cout<< "false\n";
    }
}


//next greator element to the right;
