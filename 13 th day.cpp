// 1 broken economy;
#include<bits/stdc++.h>
using namespace std ;

vector<int> solve(vector<int> arr , int n , int k)
{
    int fv = -1;
    int cv = -1;
    int start = 0 , end = n - 1;
    while(start <= end)
    {
        int mid = start + (end - start ) / 2;
        
        if(arr[mid] == k)
        {
            fv = arr[mid] ;
            cv = arr[mid];
        }
        else if(arr[mid] > k){
            end = mid - 1;
            cv = arr[mid];
        }
        else{
            start = mid + 1;
            fv = arr[mid];
        }
    }
    
    return {fv , cv} ;
}
int main()
{
    int n ;cin>> n ;
    vector<int>arr(n) ;
    for(int i = 0; i< n ; i++)
    {
        cin>> arr[i];
    }
    int k ;
    cin>> k ;
    vector<int> ans = solve(arr , n , k) ;
    cout<< ans[1] << "\n" << ans[0] << endl;
}


// 2 -Number of occurrence 

// method 1;
int count(int arr[], int n, int k) 
{
	    int *lb = lower_bound(arr , arr + n , k) ;
	    int *ub = upper_bound(arr , arr+ n , k);
	    return (ub -lb );
}


// Method 2 ;

    int first_occ(int arr[] , int n , int x)
	{
	    int low = 0 ;
	     int high = n -1 ;
	     int ans = n;
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
	int last_occ(int arr[] , int n , int x)
	{
	     int low = 0 ;
	     int high = n -1 ;
	     int ans = n;
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
	int count(int arr[], int n, int x) 
	{
	    // code here
	    int focc = first_occ(arr , n , x);
	    if(focc == n) return 0;
	    int locc = last_occ(arr , n , x);
	    return locc - focc + 1;
	}


// 3- > heaters ; not done yet ;


// 4 -> sqrt(X) ;
class Solution {
public:
    #define ll long long
    int mySqrt(int x) {
        ll left = 1;
        ll right = x;
        ll mid;
        while (left <= right){
            mid = (right - left) / 2 + left;
            if (x / mid ==  mid){
                return mid;
            }
            else if (x  / mid>  mid){
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return right;
    }
};


// 5- > valid perfect square
class Solution {
public:
    bool isPerfectSquare(int num)
    {
        int start = 1;
        int end = num ;
        long long mid ;

        while (start <= end)
        {
            mid = start + (end - start) / 2;
            if (mid * mid == num)
                return true;

            else if (mid * mid > num)
            {
                end = mid - 1;
            }
            else 
            {
                start = mid + 1;
            }

            
        }
        return false;
    }
};

