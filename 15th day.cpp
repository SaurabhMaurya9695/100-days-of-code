                                // find peak element

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int start =0 ;
        int end = nums.size() - 1;
        int n = nums.size() ;
        if(n == 1) return 0;
        if(n == 2)
        {
            if(nums[0] > nums[1]) return 0;
            else  return 1;
        }
        
        int res = -1;
        while(start <= end)
        {
            int mid = (start + (end - start) / 2) ;
            if(mid > 0 &&  mid < n-1) // means mid can't be 0 or n - 1;
            {
                if(nums[mid] > nums[mid +1] && nums[mid] > nums[mid -1])
                    {
                        res = mid ;
                        break;
                    }
                    else if(nums[mid+1] > nums[mid]) // 7 8 9
                    {
                        start = mid + 1;
                    }
                    else{
                        end = mid - 1;
                    }
            }
            else if(mid == 0) //only two elemnt is there at starting;
            {
                res = (nums[0] > nums[1]) ? 0 : 1 ;
                break;
            }
            else if(mid == n - 1){
                res = (nums[n-1] > nums[n-2] ) ? n-1 : n-2;
                break;
                
            }
                
            
        }
        return res;
        
        
    }
};

                            // count zeros ;
// 1st method -> o(n * n) -> bruteforce;

class Solution{
public:
	int countZeros(vector<vector<int>>arr)
	{
		int n = arr.size();
		int cnt = 0;
		for(int i = 0; i< n; i++)
		{
		    for(int j =0; j< n; j ++)
		    {
		        if(arr[i][j] == 0)
		        {
		            cnt++;
		        }
		    }
		}
		return cnt ;
	}
};

// by using two pointer ;
class Solution{
public:
	int countZeros(vector<vector<int>>arr)
	{
	    int n = arr.size() ;
	    int m = arr[0].size(); 
		int i =0 ;
		int j = m -1 ;
		int ans = 0;
		while(i < n && j >= 0)
		{
		    if(arr[i][j] == 0)
		    {
		        ans += (j + 1) ;
		        i++;
		    }
		    else{
		        j--;
		    }
		}
		
		return ans ;
	}
};

                                // row with max ones ;
class Solution{
public:
    int tp(vector<int> arr , int start , int end)
    {
        int n= arr.size() ;
        int res = -1 ;// notp exist
        while(start <= end)
        {
            int mid = start + (end - start ) / 2 ;
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

	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int ans = -1 ;
	    int noofones = 0;
	    for(int i = 0 ; i< n; i++)
	    {
	        int tpo = tp(arr[i], 0 , m - 1) ;
	        if(tpo != -1 && m - tpo > noofones)
	        {
	            ans = i;
	            noofones = m - tpo ;
	        }
	    }
	    return ans ;
	}

};


                                // Single element in sorted array ;
//  method 1;
// by using binary search
class Solution {
public:
    //o(logn) ;
    int singleNonDuplicate(vector<int>& arr) 
    {
        
        // by using binary search 
        // time -> o(logn) , space -> o(1) ;
        // base case // corner case ;
        int n = arr.size();
        if(n == 1) return arr[0];
        if(arr[0] != arr[1])
        {
            return arr[0] ;
        }
        if(arr[n - 1] != arr[n -2] )
        {
            return arr[ n - 1] ;
        }
        
        // original code 
        int start = 0 ;
        int end = arr.size() - 1;
        int res = -1; // if our ans is not formed means all element are equal ;
        while(start <= end)
        {
            // check whether is is our ans or not ;
            int mid = start + (end - start) / 2;
            if(arr[mid] != arr[mid -1] && arr[mid] != arr[mid + 1])
            {
                res = arr[mid] ;
                break;
            }
            else if(arr[mid] == arr[mid + 1]) 
            {
                int sizenew = mid - start  +1 ;
                if(sizenew % 2 == 1)
                {
                    start = mid + 2;
                }
                else{
                    end = mid - 1;
                }
            }
            else if(arr[mid] == arr[mid - 1]) 
            {
                int size = mid - start + 1 ;
                if(size % 2 == 0)
                {
                    // ans is availbe on right side ;
                    start = mid + 1 ;
                }
                else{
                    end = mid - 2;
                }
            }
        }
        return res;
        
    }

}
// by using xor ;

int singleNonDuplicate(vector<int>& arr)
    {
        // time -> o(n) , space ->o(1) ;
        int n = arr.size() ;
        int temp = arr[0] ;
        for(int i = 1 ; i< n; i++)
        {
            temp = temp ^ arr[i];
        }
        return temp;
        
    }


// by using hash map ;


    int singleNonDuplicate(vector<int>& arr)
    {
        // time  -> o(n) , space -> o(n);
        unordered_map<int,int> mp; // dictionary ;
        for(int x : arr)
        {
            mp[x]++;
        
        }
        int ans = -1;
        for(auto it : mp)
        {
            if(it.second == 1)
            {
                ans = it.first;
                break;
            }
        }
        return ans ;
    }

