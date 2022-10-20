//method 1
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i =0 ; i< n; i++)
        {
            mp[nums[i]]++;
        }
        for(auto it :mp)
        {
            if(it.second >=2)
            {
                return true;
            }
        }
        return false;
        
    }
};

//Method 2;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int flag = 0 , n = nums.size() ;
        for(int i = 0; i< n - 1 ; i++ )
        {
            if(nums[i ] == nums[i+1])
            {
                return true ; 
            }
        }
        
        return false;
    }
};