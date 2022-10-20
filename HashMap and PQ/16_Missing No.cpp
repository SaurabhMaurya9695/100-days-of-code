class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort( nums.begin() , nums.end() );
        int idx  = -1;
        int i ;
        for(i  = 0 ; i< nums.size() ; i++)
        {
            if(nums[i] != i)
            {
                idx = i;
                return idx ;
                
            }
        }
        return (i) ;
    }
};