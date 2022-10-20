class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) 
    {
        map<int, int >  mp;
        for(auto &x : nums)
        {
            mp[x]++;
        }
        int miss = 0;
        for(int i = 1 ; i<= nums.size() ; i++)
        {
            if(mp.find(i) == mp.end())
            {
                miss = i;
                break;
            }
        }
        int val = 0 ;
        for(auto it : mp)
        {
            if(it.second > 1)
            {
                val = it.first ;
                break;
            }
        }
        return {val , miss} ;
    }
};