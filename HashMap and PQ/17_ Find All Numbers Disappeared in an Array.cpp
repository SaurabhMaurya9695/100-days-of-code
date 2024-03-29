//Method 1 Optimal Solution
class Solution {
public:
    //TC O(n)
    //SC O(1)
//     vector<int> findDisappearedNumbers(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> ans;
//         for(int i=0;i<n;i++){
//             int index=abs(nums[i])-1;
//             if(nums[index]>0) nums[index]=-nums[index];
//         }
//         for(int i=0;i<n;i++){
//             if(nums[i]>0) ans.push_back(i+1);
//         }
//         return ans;
//     }
// };




//Method 2 O(n) Space and O(n) Time
// class Solution {
// public:
//     //Time Complexity O(n)
//     //Space Complexity O(n)
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        vector<int> cnt(n+1,0);
        for(auto x:nums) cnt[x]++;
        
        for(int i=1;i<=n;i++){
            if(cnt[i]==0) ans.push_back(i);
        }
        return ans;
    }
// };


//Method 3 Brute Force 
// class Solution {
// public:
//     //Time Complexity O(n*n)
//     //Space Complexity O(1)
//     vector<int> findDisappearedNumbers(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> ans;
//         for(int i=1;i<=n;i++){
//             bool found=0;
//             for(int j=0;j<n;j++){
//                 if(nums[j]==i){
//                     found=1;break;
//                 }
//             }
//             if(found==0) ans.push_back(i);
//         }
//         return ans;
//     }
// };