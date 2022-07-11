#include<bits/stdc++.h>
using namespace std ;


// we have two codes now for finding inversion cnt;
// o(n*n) ->, brute force ,  optimize -> o(n logn) , space->o(n);

    int merge(vector<int>&arr, int l, int m, int r)
    {
            // l = start , m = mid ,r = end;
            // Your code here
            int n1 = m - l + 1; // size in left array ;
            int n2= r - m; // size in right array ;
            int arr1[n1] , arr2[n2]; // decalre
            for(int i=0;i<n1;i++)
            {
                arr1[i]=arr[i+l];
            }
            for(int i=0;i<n2;i++)
            {
                arr2[i]=arr[i+m+1];
            }
        
        // we got two arrays now;
            int c=0;
            int i, j, k;
                i = 0;
                j = 0;
                k = l;
        
        // cnt inversion 
        while(i<n1 && j<n2)
        {
            if(arr1[i]>arr2[j])
            {
                c+=n1-i;
                j++;
            }
            else
                i++;
        }
        
        // merging work;
            i=0,j=0;
        
            while (i < n1 && j < n2) {
            if (arr1[i] <= arr2[j]) {
                arr[k] = arr1[i];
                i++;
            } else {
                arr[k] = arr2[j];
                j++;
            }
            k++;
            }
            while (i < n1) {
            arr[k] = arr1[i];
            i++;
            k++;
            }
        
            while (j < n2) {
            arr[k] = arr2[j];
            j++;
            k++;
            }
        return c;
    }

    int mergeSort(vector<int>& arr, int l, int r)
    {
        //code here
        int c=0;
        if(l == r)
            return 0;
        
            int m=(l+r)/2;
            c+=mergeSort(arr,l,m); // ans from left ;
            c+=mergeSort(arr,m+1,r); // ans from right ;
            c+=merge(arr,l,m,r); // ans after merging
        
        return c;
    }

int main()
{
    int n ;
    cin>>n ;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++)
    {
        cin>> arr[i] ;
        
    }
    cout<< mergeSort(arr , 0 , n - 1) << endl;
}



// brute force to find inversion cnt o(n *n) ;
#include<bits/stdc++.h>
using namespace std ;

// o(n * n) ;
int cntinversion(vector<int>&arr , int n)
{
    int ivr = 0 ;
    for(int i = 0 ; i< n ; i++)
    {
        for(int j = i + 1 ; j < n ; j++)
        {
            if(arr[i] > arr[j] && i < j)
            {
                ivr++;
            }
        }
    }
    return ivr ;
}
int main()
{
    int n ;
    cin>> n ;
    vector<int> arr(n);
    for(int i= 0 ; i< n ; i++)
    {
        cin>> arr[i] ;
    }
    
    cout<< cntinversion(arr , n) << endl;

}


// 2- > MInimum no of swap to sort an array
class Solution{
public:	
	
        int countInv(int arr[],int l,int r)
        {
           int res=0;
           if(l<r)
           {
               int m= l+(r-l)/2;
               res+= countInv(arr,l,m);
               res+= countInv(arr,m+1,r);
               res+= countAmerge(arr,m,l,r);
           }
           return res;
        }
        int countAmerge(int arr[],int m, int l,int r)
        {
           int n1=m-l+1;
           int n2= r-m;
           int left[n1];int right[n2];
           for(int i=0;i<n1;i++){left[i]=arr[l+i];}
           for(int i=0;i<n2;i++){right[i]=arr[m+1+i];}
           int res=0,i=0;
           int j=0;
           int k=l;
           while(i<n1 && j<n2)
           {
               if(left[i]<=right[j])
               {
                   arr[k]=left[i];
                   i++;
               }
               else{
                   arr[k]=right[j];j++;
                   res= res+(n1-i);
               }
               
               k++;
               
           }
           while(i<n1){arr[k]=left[i];i++;k++;}
           while(j<n2){arr[k]= right[j];j++;k++;}
           return res;
           
        }
         
        int countSwaps(int arr[], int n)
        {
            // Your code goes here
            return countInv(arr,0,n-1);
            
        }
};

//// 3 -> reverse pair 

class Solution {
public:
    int merge(vector<int>&arr, int l, int m, int r)
    {
         // Your code here
         int n1 = m - l + 1;
         int n2= r - m;
         int arr1[n1] , arr2[n2];
         for(int i=0;i<n1;i++)
         {
             arr1[i]=arr[i+l];
         }
         for(int i=0;i<n2;i++)
         {
             arr2[i]=arr[i+m+1];
         }
        
          int c=0;
          int i, j, k;
              i = 0;
              j = 0;
              k = l;
        
        // cnt inversion 
        while(i<n1 && j<n2)
        {
            if(arr1[i]>2 * arr2[j] * 1LL )
            {
                c+= n1 - i ;
                j++;
            }
            else
                i++;
        }
        
            i=0,j=0;
        
           while (i < n1 && j < n2) {
            if (arr1[i] <= arr2[j]) {
              arr[k] = arr1[i];
              i++;
            } else {
              arr[k] = arr2[j];
              j++;
            }
            k++;
          }
           while (i < n1) {
            arr[k] = arr1[i];
            i++;
            k++;
          }
        
          while (j < n2) {
            arr[k] = arr2[j];
            j++;
            k++;
          }
        return c;
    }

    int mergeSort(vector<int>& arr, int l, int r)
    {
        //code here
        int c=0;
        if(l<r)
        {
            int m=(l+r)/2;
            c+=mergeSort(arr,l,m); // ans from left ;
            c+=mergeSort(arr,m+1,r); // ans from right ;
            c+=merge(arr,l,m,r); // ans after merging
        }
        return c;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};

//4->  Global and local inversion 
                        //complexity - o(n log n)  , space -> o(n) ;
class Solution {
public:
    // merging code
    int merge(vector<int>&arr, int l, int m, int r)
    {
         // Your code here
         int n1 = m - l + 1;
         int n2= r - m;
         int arr1[n1] , arr2[n2];
         for(int i=0;i<n1;i++)
         {
             arr1[i]=arr[i+l];
         }
         for(int i=0;i<n2;i++)
         {
             arr2[i]=arr[i+m+1];
         }
        
          int c=0;
          int i, j, k;
              i = 0;
              j = 0;
              k = l;
        
        // cnt inversion 
        while(i<n1 && j<n2)
        {
            if(arr1[i]>arr2[j])
            {
                c+=n1-i;
                j++;
            }
            else
                i++;
        }
        
            i=0,j=0;
        
           while (i < n1 && j < n2) {
            if (arr1[i] <= arr2[j]) {
              arr[k] = arr1[i];
              i++;
            } else {
              arr[k] = arr2[j];
              j++;
            }
            k++;
          }
           while (i < n1) {
            arr[k] = arr1[i];
            i++;
            k++;
          }
        
          while (j < n2) {
            arr[k] = arr2[j];
            j++;
            k++;
          }
        return c;
    }

    // divide code
    int mergeSort(vector<int> arr, int l, int r)
    {
        //code here
        int c=0;
        if(l<r)
        {
            int m=(l+r)/2;
            c+=mergeSort(arr,l,m); // ans from left ;
            c+=mergeSort(arr,m+1,r); // ans from right ;
            c+=merge(arr,l,m,r); // ans after merging
        }
        return c;
    }
    // main function 
    bool isIdealPermutation(vector<int>& nums) {
        int globalivr = mergeSort(nums , 0 , nums.size() - 1) ;
        int localivr = 0;
        for(int i = 0 ; i< nums.size() - 1 ; i++)
        {
            if(nums[i] > nums[i+1])
            {
                localivr++;
            }
        }
        
        if(localivr == globalivr)
            return true;
        else{
            return false;
        }
    }
};

// optimize code;
class Solution {
public:
    bool isIdealPermutation(vector<int>& arr) {
        // coming from -> 
        // brute force- >o(n *n)   , space -> o(1);
        // by mergesort ->o(nlogn)  ,space -> o(n);
        // by optimization -> o(n)  , space -> o(1);
       
        int n = arr.size() ;
        for(int i = 0 ; i<n ; i++)
        {
            if(abs(i - arr[i] ) > 1)
            {
                return false;
            }
        }
        return true;
    }
};

// 5- Sort the given array after applying the given equation

#define ll long long
vector<ll> sortArray(vector<ll>arr, int n, ll A, ll B, ll C){
    vector<ll > ans;
    for(ll x : arr)
    {
        ll aa = A * x * x ;
        ll bb = B * x ;
        
        ll  total = aa + bb + C;
        ans.push_back(total);
    }
    sort(ans.begin() , ans.end()) ;
    return ans ;
    
}
