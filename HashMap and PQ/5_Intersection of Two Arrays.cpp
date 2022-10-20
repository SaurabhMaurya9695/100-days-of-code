class Solution {
public:
    vector<int> intersection(vector<int>& arr, vector<int>& nums) 
    {
        unordered_map<int,int> mp1 ;
        for(auto x : arr) mp1[x]++;
        unordered_map<int,int> mp2 ;
        for(auto x : nums) mp2[x]++;
        set<int> st ;
        for(auto x : arr)
        {
            if(mp2.find(x) != mp2.end())
            {
                st.insert(x);
            }
        }
        for(auto x : nums)
        {
            if(mp1.find(x) != mp1.end())
            {
                st.insert(x);
            }
        }
        vector<int> ans(st.begin() , st.end());
        return ans;
    }
};