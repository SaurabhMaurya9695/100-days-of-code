class Solution {
public:
    int findDuplicate(vector<int>& arr) 
    {
        unordered_map<int,int> mp ;
        for(auto x : arr)
        {
            mp[x] ++;
        }
        int max = INT_MIN;
        int val =  0 ;
        for(auto it : mp)
        {
            if(it.second > max)
            {
                max = it.second;
                val = it.first;
            }
        }
        return val;
    }
};