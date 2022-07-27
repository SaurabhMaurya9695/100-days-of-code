                        // Remove duplicate braces;

int Solution::braces(string A) {
    stack<int> s;
    int n=A.size();
    for(int i=0;i<n;i++){
        if(A[i]==')'){
            int d=0;
            while(s.top()!='('){
                s.pop();
                d++;
            }
            s.pop();
            if(d==1 ||d==0){
                return 1;
            }
        }
        s.push(A[i]);
    }
    return 0;
}


                            // Longest valid substring

            // solution 1:
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int n = s.size() ;
        stk.push(-1);
        int ans = 0;
        for(int i =0 ; i< n ; i++)
        {
            if(s[i] == '(')
            {
                stk.push(i);
            }
            else 
            {
                stk.pop();
                if(stk.size() == 0 )
                {
                    stk.push(i);
                }
                else{
                    // int x = i - stk.top();
                    // if(x> ans)
                    // {
                    //     ans = x;
                    // }
                    ans = max(ans , i - stk.top());
                }
            }
            
        }
        return ans;
    }
};

                //solution 2
class Solution {
public:
    
    int longestValidParentheses(string s) 
    {
        // time -> o(n) + o(n) = > o(n);
        //space -> O(1);
        int maxi = 0;
        int open = 0 , close = 0;
        // int max = 0;
        int n  = s.size() ;
        
        // 0 -- n // left to right
        for(int i=0;i<n ;i++){
            char c = s[i];
            if(c == '('){
                open++;
            }
            else{
                close++;
            }
            
            if(open == close){
                int len = open + close;
                maxi = max(maxi,len);
            }
            else if(close > open ){
                open = close = 0;
            }
        }
        
        open = close = 0;
        // n -- 0
        for(int i= s.length()-1; i>=0 ;i--){
            char c = s[i];
            if(c == '('){
                open++;
            }
            else{
                close++;
            }
            
            if(open == close){
                int len = open + close;
                maxi = max(maxi,len);
            }
            else if(open > close ){
                open = close = 0;
            }
        }
        
        return maxi;
    
    }
};

                                //  Minimum Add to Make Parentheses Valid
// Method 1 : time -o(n) , space ->o(n);
class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt = 0;
        stack<char> stk;
        int n = s.size();
        for(int i = 0 ; i <  n ;i++)
        {
            if(s[i] == ')')
            {
                if(stk.size() > 0 && stk.top() == '(')
                {
                    stk.pop();
                }
                else {
                    stk.push(s[i]);
                }
            }
            else{
                stk.push(s[i]);
            }
        }
        // return stk.size() ;
        while(!stk.empty())
        {
            stk.pop();
            cnt++;
        }
        return cnt;
        
    }
};


            // solution 2
{
int minAddToMakeValid(string s) 
    {
        
        // time -> o(n);
        // space -> o(1);
        int open = 0 , close = 0 , ans = 0;
        for(auto x : s)
        {
            if(x == '(')
            {
                open++;
            }
            else{
                close++;
            }
            if(close > open)
            {
                ans++;
                open++;
            }
        }
        return ans + (abs ( open -close));
    }
};
