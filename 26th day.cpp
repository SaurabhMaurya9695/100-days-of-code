                // Minimum Swaps for Bracket Balancing -> gfg


class Solution{   
public:
#define ll long long
    int minimumNumberOfSwaps(string s){
        ll n = s.size() ;
        ll open = 0 , close = 0 , unbalanced = 0, swap = 0;
        for(ll i  = 0 ; i< n ; i++)
        {
            if(s[i] == '[')
            {
                open++;
                if(unbalanced > 0)
                {
                    swap += unbalanced;
                    unbalanced--;
                }
            }
            else{
                close++;
                unbalanced = close -open ;
            }
        }
        return swap;
    }
};

                    
                    // Minimum Number of Swaps to Make the String Balanced -> Leetcode

class Solution {
public:

                            // Method 1;

    // int minSwaps(string s) {
    //     int n = s.size() ;
    //     int cnt =0;
    //     stack<char> stk;
    //     for(int i = 0; i< n ;i++)
    //     {
    //         if(s[i] == '[')
    //         {
    //             stk.push(s[i]);
    //         }
    //         else {
    //             if(stk.size()  > 0 && stk.top() == '[')
    //             {
    //                 stk.pop();
    //             }
    //             else{
    //                 stk.push(s[i]);
    //             }
    //         }
    //     }
    //     int b = stk.size() / 2;
    //     int ans = (b % 2 == 1) ? b/2 + 1 : b /2;
    //     return ans ;
    // }


                        // Method 2

    // int minSwaps(string s) {
        // int start=0,end=s.size()-1,open=0,close=0,ans=0;
        // while(start<end){
        //     if(s[start]==']'){
        //         open++;
        //     } else {
        //         close++;
        //     }
        //     if(open>close){
        //         while(s[end]!='['){
        //             end--;
        //         }
        //         swap(s[start],s[end]);
        //         ans++;
        //         open--;
        //         close++;
        //     }
        //     start++;
        // }
        // return ans;
        
        
                            //Method 3
        
        // int close=0 , maxClose=0;
        // for(char ch:s)
        // {
        //     if(ch==']')
        //         close++;
        //     else if(ch == '[')
        //         close--;
        //     maxClose=max(maxClose,close);
        // }
        // return (maxClose + 1)/2;
        
        
                                //Method 4
        
        
        int n = s.size();
        int open = 0 , ans = 0;
        for(int i = 0 ;i<n ; i++)
        {
            if(s[i] == '[')
            {
                open++;
            }
            else if(s[i] == ']')
            {
                if(open > 0)
                {
                    open--;
                }
                else{
                    ans++;
                }
            }
        }
        return (ans % 2 == 1) ? (ans / 2 + 1) : (ans / 2);
         

};





                                        //count the reversal


// time ->o(n) , space ->o(n);
int countRev (string str)
{
    stack<char> st;
    int ans = 0;
  
    
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '{')
            st.push(str[i]);
        
        else {
            
            if (!st.empty())
                st.pop();
            
            else {
                st.push('{');
                ans++;
            }
        }
    }
    if (st.size() % 2 != 0)
        return -1;
    ans += st.size() / 2;
  
    return ans;
    
}

                // time -> 0(n) , space -> o(1);
int countRev (string s)
{
    int n = s.size() ;
    if(n % 2 == 1)
        return -1;
    int open = 0 , close = 0;
    for(int i = 0 ; i < s.size() ; i++)
    {
        if(s[i] == '{') open++;
        else{
            if(open > 0) 
            {
                open--;
            }
            else{
                res++;
            }
        }
    }
    int ans = ceil(open / 2.0) + ceil(close / 2.0) ;
    return ans ;
}

                    // score of parenthesis
class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0;
        int open = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(') open++;
            else {
                open--;
                if(s[i-1] == '(') {
                    int x = pow(2, open);
                    cout<< x << " " << open << endl;
                    ans += x;
                    cout<< " ans is "  << ans << endl;
                }
            }
        }
        return ans;
    }
};


class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        int count = 0, ans = 0;
        stack<int> st;
        
        for(auto x:s){
            if(x == '('){
                st.push(-1);
            }
            else if(x == ')' && st.top() == -1){
                st.pop();
                st.push(1);
            }
            else if(x == ')' && st.top() != -1){
                while(st.top() != -1){
                    count += st.top();
                    st.pop();
                }
                st.pop();
                st.push(2*count);
                count = 0;
            }
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};

