// 1st binary search
class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        // without STL:
        int start =  0 ;
        int end = nums.size() - 1 ;
        int res = -1;
        while(start <= end){
            int mid = start + (end - start) / 2 ;
            // if our target is equal to mid ;
            if(nums[mid] == target){
                return mid ;
            }
            else if(nums[mid] > target){
                end = mid -1;
            }
            else{
                start = mid + 1;
            }
        }
        return res ;
        

        
        
    }
};


// first transaction point;


int transitionPoint(int arr[], int n) {
    int start = 0 ;
    int end =  n - 1;
    int res = -1;
    while(start <= end)
    {
        int mid = start + (end- start )/2;
        // transaction point  1 ;
        if(arr[mid] == 1)
        {
            res = mid ;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return res ;
    
}

//2-> Guess Number Higher or Lower
class Solution {
public:
    #define ll long long
    int guessNumber(int n) {
        ll start = 1;
        ll end = n ;
        ll res = -1;
        while(start <= end)
        {
            ll mid = start + (end - start) / 2;
            if(guess(mid) == 0) // number is founded
            {
                return mid ;
            }
            else if(guess(mid) == 1)  // num < pick
            {
                start = mid + 1;               
            }
            else{
                // num > pick
                end = mid - 1;
            }
        }
        return res ;
    }
};
// 3 - first bad version ;

class Solution {
public:
    int firstBadVersion(int n) {
        long int low = 1;
        long int high = n;
        long int mid;
        long int result = -1;
        
        while(low<=high)
        {
            mid = (low+high)/2;
            if(isBadVersion(mid)  == true)
            {
                result = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        return result;
    }
};


// 4 -> Search Insert Position

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        // lower bound;
        int start = 0 ;
        int end = nums.size() - 1;
        while(start <= end)
        {
            int mid = start + (end - start) / 2;
            if(nums[mid] == target)
            {
                return mid ;
            }
            else if(nums[mid] > target)
            {
                end = mid - 1;
            }
            else{
                start = mid + 1 ;
            }
        }
        return start ;
    }
};


// 4- first and last index of the elemnt;
class Solution {
public:
    int first_occ(vector<int>& arr, int n , int x)
	{
	    int low = 0 ;
	     int high = n -1 ;
	     int ans = -1;
	     while(low <= high)
	     {
	         int mid = low + (high - low)/2;
	         if(arr[mid] == x)
	         {
	             ans = mid;
	             high = mid - 1;
	         }
	         else if(arr[mid] > x)
	         {
	             high = mid - 1;
	         }
	         else if(arr[mid] < x)
	         {
	             low = mid + 1;
	         }
	     }
	     return ans;
	}
    
    int last_occ(vector<int>& arr , int n , int x)
	{
	     int low = 0 ;
	     int high = n -1 ;
	     int ans = -1;
	     while(low <= high)
	     {
	         int mid = low + (high - low)/2;
	         if(arr[mid] == x)
	         {
	             ans = mid;
	             low = mid + 1;
	         }
	         else if(arr[mid] > x)
	         {
	            high = mid - 1;
	         }
	         else if(arr[mid] < x)
	         {
	             low = mid + 1;
	         }
	     }
	     return ans;
	}
    vector<int> searchRange(vector<int>& arr, int k) {
        // vector<int> ans;
        // if(binary_search(arr.begin() , arr.end() , k))
        // {
        //     ans.push_back(lower_bound(arr.begin(), arr.end() , k) - arr.begin());
        //     ans.push_back(upper_bound(arr.begin() , arr.end() ,k) - arr.begin() - 1);
        //     return ans;
        // }
        // else{
        //     return {-1,-1};
        // }
        int n = arr.size() ;
        
        int x = first_occ(arr , n , k);
        int y = last_occ(arr , n , k);
        return {x ,y};
        
        
    }
};
static int x=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    return 0;
}();

