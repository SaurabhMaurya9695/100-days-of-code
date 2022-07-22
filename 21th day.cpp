                            // prefix evaluation ;

// #include<bits/stdc++.h>
// using namespace std ;


// void solve(string s)
// {
//     stack<int > stk ;
//     int n = s.size() ;
//     for(int i = n - 1 ; i>=0 ; i--)
//     {
//         if(s[i] >= '0' && s[i] <= '9')
//         {
//             stk.push(s[i] -'0');
//         } 
//         else{
//             // operator ; + , / , * , - ;
//             int op1 = stk.top();
//             stk.pop();
//             int op2 = stk.top();
//             stk.pop();

//             switch(s[i])
//             {
//                 case '+' :
//                     stk.push(op1 + op2);
//                     break;
//                 case '-' :
//                     stk.push(op1 - op2);
//                     break;
//                 case '*' :
//                     stk.push(op1 * op2);
//                     break;
//                 case '/' :
//                     stk.push(op1 / op2);
//                     break;
//                 case '^' :
//                     stk.push(pow(op1, op2));
//                     break;

//             }

//         }
        
//     }
//     cout<< stk.top() << endl;
// }
// int main()
// {
//     string s = "-+7*45+20";
//     // cout<< solve(s) << endl;
//     solve(s);
//     return 0;
// }


                                    // prefix expression 
// #include<bits/stdc++.h>
// using namespace std ;


// int solve(string s)
// {
//     stack<int > stk ;
//     int n = s.size() ;
//     for(int i = 0 ; i < n ; i ++ )
//     {
//         if(s[i] >= '0' && s[i] <= '9')
//         {
//             stk.push(s[i] -'0');
//         } 
//         else{
//             // operator ; + , / , * , - ;
//             int op1 = stk.top();
//             stk.pop();
//             int op2 = stk.top();
//             stk.pop();

//             switch(s[i])
//             {
//                 case '+' :
//                     stk.push(op2 + op1);
//                     break;
//                 case '-' :
//                     stk.push(op2 - op1);
//                     break;
//                 case '*' :
//                     stk.push(op2 * op1);
//                     break;
//                 case '/' :
//                     stk.push(op2 / op1);
//                     break;
//                 case '^' :
//                     stk.push(pow(op2, op1));
//                     break;

//             }

//         }
        
//     }
//     return stk.top();
// }

// int main()
// {
//     string s = "231*+9-";
//     cout<< solve(s) << endl;
//     // solve(s);
//     return 0;
// }


                                  // infix to postfix ;
#include<bits/stdc++.h>
using namespace std ;


int prec(char op)
{
    if(op == '^')
    {
        return 3;
    }
    else if(op == '*' || op == '/')
    {
        return 2;
    }
    else if(op == '+' || op == '-')
    {
        return 1;
    }
    else{
        return -1;
    }
}

void solve(string s)
{
    int n = s.size() ;
    stack<char> stk;
    string ans ;
    for(int i = 0 ; i < n ; i++)
    {
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            ans += s[i];
        }
        else if(s[i] == '(')
        {
            stk.push(s[i]);
        }
        else if(s[i] == ')')
        {
            while(stk.size() > 0 && stk.top() != '(')
            {
                ans += stk.top();
                stk.pop();
            }
            stk.pop();
        }
        else{
            while(stk.size() > 0 && prec(stk.top()) > prec(s[i]))
            {
                ans += stk.top();
                stk.pop();
            }
            stk.push(s[i]);
        }
    }
    while(!stk.empty())
    {
        ans += stk.top();
        stk.pop();
    }
    cout<< ans << endl;
}
int main()
{
    string s ="(a-b/c)*(a/k-l)";  
    // ans -> abc/-ak/l-*
    solve(s) ;
}
