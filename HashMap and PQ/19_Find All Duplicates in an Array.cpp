class Solution {
public:
    vector<int> findDuplicates(vector<int>& arr) {
        // unordered_map<int,int> mp;
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        int n = arr.size();
        vector<int> res;
        // for(int i  = 0 ;i < n ; i++)
        // {
        //     mp[arr[i]]++;
        // }
        // for(auto it : mp)
        // {
        //     if(it.second  >1)
        //     {
        //         int x =it.first;
        //         ans.push_back(x);
        //     }
        // }
       for(int i=0;i<arr.size();i++){
            int z= arr[i]; // go at particular index - 1 of that number and marked as - 1;
            int ab_z = abs(z);
            if(arr[ab_z-1] < 0) 
                res.push_back(ab_z);
            else
                arr[ab_z-1] = -arr[ab_z-1];   
        }
        return res;
    }
};