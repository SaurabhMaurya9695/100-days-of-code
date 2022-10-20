class Solution {
public:
    string removeDuplicates(string s, int k) 
    {
        stack<pair<char , int >>  stk;
        int n = s.size() ;
        for(int i = 0 ; i < n ; i++)
        {
            if(stk.size() == 0 || stk.top().first != s[i])
            {
                stk.push({s[i] , 1});
            }
            else if( stk.size() > 0 &&  stk.top().first == s[i])
            {
                pair<char , int > pp = stk.top() ;
                stk.pop();
                stk.push({s[i] , pp.second + 1 });
            }
            if(stk.top().second == k)
            {
                stk.pop();
            }
                
        }
        string ans ;
        while(!stk.empty())
        {
            pair<char , int > pp = stk.top();
            while(pp.second --)
            {
                ans += pp.first ;
            }
            stk.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans ;
    }
};