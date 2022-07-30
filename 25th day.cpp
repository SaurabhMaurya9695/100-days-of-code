class Solution {
public:
    int minInsertions(string s) {
        int open = 0, add = 0;
        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];
            
            if(ch == '(')    
                 open++;
            else if(ch  == ')') {
                if(open > 0) open--;   //())
                else add++;
                
                if(i + 1 < s.size() && s[i + 1] == ')') i++;
                else add++;
            }
        }
        return add + 2 * open;
    }
};

                    //Minimum Remove to Make Valid Parentheses


class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size() ;
        stack<int> stk ; // storing idx ;
        for(int i = 0 ; i< n ; i++)
        {
            if(s[i] == '(')
            {
                stk.push(i);
            }
            else if(s[i] == ')')    // a)b)c)
            {
                if(stk.size() == 0)
                {
                    s[i] = '#';
                }
                else if(stk.size() > 0) // if stk.size() > then it means we pushed '(' ;
                {
                    stk.pop();
                }
            }
        }
        
        string ans = "";
        while(!stk.empty())
        {
            int idx = stk.top();
            s[idx] = '#';
            stk.pop();
        }
        // cout<< s << endl;
        
        for(auto ch : s)
        {
            if(ch != '#')
            {
                ans += ch;
            }
        }
        return ans;
        
    }
};


            // time -> o(n) , space->o(1)
    string minRemoveToMakeValid(string s) {
        int n=s.length();
        int count=0; 
        
        // 1st Traversal for removing invalid ')'
        // left to right , 
        for(int i=0;i<n;++i)
        {
            if(s[i]=='(')
            {
                ++count;  // 
            }
            else if(s[i]==')')
            {
                if(count==0)  // 
                {
                    s[i]='#';
                }
                else
                {
                    --count;  
                }
            }
        }
        
        count = 0;
        
        // 2nd Traversal for removing invalid '('
        
        // right to left
        for(int i=n-1;i>=0;--i)
        {
            if(s[i]==')')
            {
                ++count;
            }
            else if(s[i]=='(')
            {
                if(count==0)
                {
                    s[i]='#';
                }
                else
                {
                    --count;
                }
            }
        }
        
        // cout<< s << endl;
        string ans="";
        for(int i=0; i<n; ++i)
        {
            if(s[i]!='#')
            { 
                ans.push_back(s[i]);
            }
        }
        
        return ans;
    }


                    // Minimum Number of Swaps to Make the String Balanced

class Solution {
public:
    int minSwaps(string s) {
        int n = s.size() ;
        int cnt =0;
        stack<char> stk;
        for(int i = 0; i< n ;i++)
        {
            if(s[i] == '[')
            {
                stk.push(s[i]);
            }
            else {
                if(stk.size()  > 0 && stk.top() == '[')
                {
                    stk.pop();
                }
                else{
                    stk.push(s[i]);
                }
            }
        }
        int b = stk.size() / 2;
        int ans = (b % 2 == 1) ? b/2 + 1 : b /2;
        return ans ;
    }
};
