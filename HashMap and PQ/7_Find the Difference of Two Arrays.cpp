class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& arr, vector<int>& arr2) 
    {
        unordered_set<int> st1(arr.begin(), arr.end());
        unordered_set<int> st2(arr2.begin() , arr2.end());
        // to store ans ;
        vector<vector<int>> ans (2);
        vector<int> res;
        for(auto &it : st1) // check first element of array into second element ;
        {
            if(st2.count(it) == 0)
            {
                ans[0].push_back(it);
            }
            
        }
        for(auto &it1 : st2)
        {
            if(st1.count(it1) == 0)
            {
                ans[1].push_back(it1);
            }
            
        }
        return ans ;
        
    }
};

