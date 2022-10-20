class Solution {
public:
    bool canArrange(vector<int>& arr, int k) 
    {
        unordered_map< int  , int> mp ;
        for(auto x : arr)
        {
            int rem = ((x % k) + k) % k;
            mp[rem] ++ ;
        }
        for(auto it :  mp)
        {
            int freq = it.second ;
            int val = it.first ;
            // cout<< val << " " << freq << endl;
            if(val == 0)
            {
                if(freq % 2 != 0) return false;
            }
            else{
               
                    if(mp[val] != mp[k - val])
                    {
                        return false;
                    }
                }
            
        }
  
        return true;
        
    }
};