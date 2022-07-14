                                  //  set example
#include<bits/stdc++.h>
using namespace std ;
int main()
{
    vector<int> arr ={ 8 ,78 , 45 , 2 , 2 , 2 , 2  , 1} ;\
    // space -> o(n) -> set space 
    set<int> st ;
    for(int x : arr)
    {
        st.insert(x); // insert in sorted order ; // time -> o(logn);
    }
    for(auto it : st)
    {
        cout<< it << " ";
    }

}


                          // find min in rotated sorted array i 
class Solution
{
    public:
        int findMin(vector<int> &nums)
        {
            int start = 0;
            int n = nums.size();
            int end = n - 1;
            if (nums[start] <= nums[end]) // if array is already sorted ;
            {
                return nums[0];
            }
            else
            {
                while (start <= end)
                {
                    int mid = start + (end - start) / 2;
                    int prev = (mid + n - 1) % n; // mid - 1
                    int next = (mid + 1) % n; // mid + 1

                    if (nums[mid] <= nums[prev] && nums[mid] <= nums[next])  // smaller than its neighbours
                    {
                        return nums[mid];
                    }
                    else if (nums[mid] > nums[end])  // 1 2 3 4 // then make calls in right side ;
                    {
                        start = mid + 1;
                    }
                    else
                    {
                        end = mid;
                    }
                }
            }
            return -1;
        }
};


                           // find min in sorted rotated array ii 



class Solution {
public:
    int findMin(vector<int>& nums) {
        
        // Method 1  ->o(logn) , space -> o(n);
        set<int> st ; // always takes unique values and in asending  order ;
        for(int x : nums)
        {
            st.insert(x);
        }
       return *(st.begin());
        
        // method 2 -> o(n);
        //return *min_element(nums.begin(),nums.end());
        
        // by using binary search // o(logn) , space - o(1);
        
        
    }
};


                                // search in 2D MATRIX;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int k) {
        int rows = arr.size();
        int col = arr[0].size();
        int i =0 ; int  j = col - 1;
        while(i < rows && j >=0)
        {
            if(arr[i][j] == k)
                return true;
            else if( arr[i][j] > k)
                j--;
            else{
                i++;
            }
        }
        return false; 
        
    }
};
static int x=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    return 0;
}();



                                // Peak elememt in 2d array ;
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        //mid == 0 all the elements after mid is lesser ;
        // mid == n - 1 all the elements before mid is lesser ;
        // n >= 3  -> we can apply our algo otherwise return -1;
        
        
        int n = arr.size() ;
        if(n < 3) return -1;
        int start = 0 ;
        int end = n - 1;
        int res = -1 ;
        while(start <= end)
        {
            int mid = start + (end - start) / 2 ;
            if(mid > 0 &&  mid < n - 1)
            {
                if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
                {
                    res = mid;
                    break;
                }
                else if(arr[mid + 1] > arr[mid])
                {
                    start = mid + 1;
                }
                else{
                    end = mid - 1;
                }
            }
             // mid == 0 ;
            if( mid == 0)
            {
                if(arr[0] > arr[1])
                {
                    res = 0;
                    break; 
                }
                else{
                    res = 1 ;
                    break;
                }
            }
            if(mid ==  n- 1)
            {
                if(arr[n-1] > arr[n - 2])
                {
                    res =  n-1;
                    break;
                }
                else{
                    res =  n-2;
                    break;
                }
            }
            
        }
        return res ;
    }
};





