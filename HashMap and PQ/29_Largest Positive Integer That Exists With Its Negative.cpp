class Solution {
public:
    int findMaxK(vector<int>& arr) 
    {
        set<int> st ;
        for(auto x : arr)
        {
            if(x < 0) 
            {
                st.insert(abs(x));
            }
        }
        int ans = -1;
        for(auto x : arr)
        {
            if(x > 0)
            {
                if(st.find(x) != st.end())
                {
                    if(x > ans)
                    {
                        ans = x;
                    }
                }
            }
        }
        return ans ;
        
    }
};