class Solution {
public:
    string removeDuplicates(string s) {
        stack<char > stk;
        for(int i = 0 ; i< s.size() ; i++)
        {
             if(!stk.empty())
            {
                if(stk.top() == s[i])
                {
                    stk.pop();
                }
                 else{
                     stk.push(s[i]);
                 }
            }
            else{
                stk.push(s[i]);
            }
        }
        string ans = "";
        while(stk.size() != 0)
        {
            char ch =  stk.top();
            stk.pop();
            ans += ch;
        }
        reverse(ans.begin() , ans.end());
        return ans ;
    }
};