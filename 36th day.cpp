                        /* climb stairs*/
class Solution {
public:
    int climbStairs(int n) 
    {
        // if(n == 1)
        // {
        //     return 1;
        // }
        // else if(n == 2)
        // {
        //     return 2;
        // }
        // else{          
        //     return climbStairs(n-1) + climbStairs(n-2) ;
        // }
        
        vector<int> fib(n + 1);
        if(n == 1) return 1;
        if(n == 2) return 2;
        fib[1] = 1;
        fib[2] = 2;
        for(int i = 3; i <= n ; i++)
        {
            fib[i] = fib[i-1] + fib[i- 2];
        }
        return fib[n];
        
    }
};


                            /*Generate Parentheses*/

class Solution {
public:
    
    void solve(int n , int open , int close , vector<string>&res , string ans , int idx)
    {
        if( (idx == 2 * n )&& ( (open == n) && (close == n))) 
        {
            res.push_back(ans);
            return ;
        }
        
        //for opening
        if(open < n) 
        {
            solve( n , open + 1 , close , res , ans + "(" , idx + 1);
        }
        // for closing
        if(close < open)
        {
            solve(n , open , close + 1 , res , ans + ")" , idx + 1);
        } 
        
    }
    vector<string> generateParenthesis(int n) 
    {
        vector<string>res;
        solve(n , 0 , 0 , res , "", 0);
        return res;
        
    }
};

                        /*palindrom partition */
class Solution {
public:
    
    bool checkpal(string s)
    {
        int start = 0 , end = s.size() - 1;
        while(start < end)
        {
            if(s[start] != s[end])
            {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    
    void solve( string s , vector<string>&ans ,vector<vector<string>> &res)
    {
        
        // base case ;
        if(s.size() == 0)
        {
            res.push_back(ans);
            return ;
        }
        for(int i = 0 ; i< s.size() ; i++)
        {
            string prefix = s.substr(0, i + 1); // 0 ... i
            string rest = s.substr(i + 1 ); // i + 1 .... n
            cout<< prefix << " " << rest << endl;
            if(checkpal(prefix) == true)
            {
                ans.push_back(prefix);
                solve(rest , ans , res);
                ans.pop_back(); // this is for backtracking 
            }
        }
    }
    
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> res;
        vector<string>ans;
        solve( s, ans , res);
        return res;
        
    }
};


                            /*permutation 1 */
class Solution {
public:
    
    
    void solve(int idx, vector<int>&arr , vector<int>&ans , vector<vector<int>>&res)
    {
        if(idx == arr.size())
        {
            res.push_back(ans);
            return ;
        }
        
        for(int i = 0 ; i<  ans.size() ; i++ )
        {
            if(ans[i] == 0) // pos is empty;
            {
                ans[i] = arr[idx];
                solve(idx + 1 , arr , ans , res);
                ans[i] = 0;
            }
        }
                
    }
    vector<vector<int>> permute(vector<int>& arr) 
    {
        vector<vector<int>> res ;
        int n = arr.size() ;
        vector<int> ans(n , 0) ;
        solve(0 , arr , ans , res);
        set<vector<int>> st;
        for(auto x : res)
        {
            st.insert(x);
        }
        vector<vector<int>> temp;
        for(auto it : st)
        {
            temp.push_back(it);
        }
            
        return temp;
        
    }
};
