class Solution {
    #define ll long long
public:
    
    ll M = 1e9+7;
    ll BinaryExp(ll a,ll b)
    {
        ll ans=1;
        while(b){
            if(b&1) ans=(ans*a)%M;
            a=(a*a)%M;
            b>>=1;
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        ll even=(n+1LL)/2;
        ll odd=n-even;
        
        return (BinaryExp(5LL,even)%M * BinaryExp(4LL,odd)%M)%M;
    }
};


              /* ways to add parenthesis */
class Solution {
public:
    
    int operate(int x  , int y , char c)
    {
        if(c == '*') return x * y;
        else if(c == '+') return x + y;
        else{
            return x - y;
        }
    }
    
    vector<int> solve(string s)
    {
        vector<int> ans;
        int n = s.size() ;
        bool allarenumbers = true;
        for(int i = 0 ; i< s.size() ; i++)
        {
            if(s[i] == '*' || s[i] == '+' || s[i] == '-')
            {
                allarenumbers = false;
                string left = s.substr(0 , i); // 0.. i-1
                string right = s.substr(i + 1 , n) ;
                vector<int> leftv = solve(left) ;
                vector<int> rightv = solve(right);
                
                for(int k = 0 ; k < leftv.size() ; k++)
                {
                    for(int j = 0 ; j< rightv.size() ; j ++)
                    {
                        ans.push_back(operate(leftv[k] , rightv[j] , s[i]));
                    }
                }
            }
        }
        
        if(allarenumbers == true)
        {
            ans.push_back(stoi(s));
        }
        return ans ;
        
    }
    vector<int> diffWaysToCompute(string expression) 
    {
        return solve(expression) ;
    }
};


#include<bits/stdc++.h>
using namespace std ;

                /* item on level */
                // 1--- , -1---, --1- , ---1;

// void solve(int n , int k , vector<int>&boxes , vector<bool>&vis , int item)
// {
//     if(item > k)
//     {
//         for(int x : boxes)
//         {
//             cout<< x ;
//         }
//         cout<< endl;
//         return ;
//     }

//     for(int i = 0 ; i< boxes.size() ; i++)
//     {
//         if(vis[i] == 0)
//         {
//             vis[i] = 1;
//             boxes[i] = item;
//             solve(n, k , boxes , vis , item + 1);

//             // backtracking
//             boxes[i] = 0;
//             vis[i] = 0;
//         }
//     }

// }


                        /* Box on level */
                    // 1--- , 2---,  ----;
/*
void solve(int n , int k , int selected , vector<bool> &vis , int currentbox , string asf)
{

    if(currentbox > n)
    {
        if(selected ==  k)
        {
            cout<< asf << endl;
        }
        return ;
    }

    for(int i = 0 ; i< k ; i++)
    {   
        if(vis[i] == 0)
        {
            vis[i] = 1 ;
            solve(n ,  k , selected + 1 , vis , currentbox + 1 , asf + to_string(i + 1));
            vis[i] = 0;
        } 
    }
    solve(n ,  k , selected + 0 , vis , currentbox + 1 , asf + "0");

}   
*/

// int main()
// {
//     int n , k ;
//     cin>> n >> k;
//     vector<bool> vis(n , false);
//     vector<int> boxes(n,0);
//     solve(n ,  k , 0 , vis , 1,"");
// }
