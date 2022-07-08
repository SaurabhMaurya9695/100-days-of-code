// 1st bubble sort 
// worst(n^2) , best(n) , space - o(1);

#include<bits/stdc++.h>
using namespace std;


// void swap(int & x , int &y)
// {
//     int temp ;
//     temp = x;
//     x= y ;
//     y = temp;
// }

// 1st bubble sort 
// worst(n^2) , best(n) , space - o(1);
void Bubblesort(vector<int> & arr , int n)
{
    for(int i = 1 ; i <= n - 1; i ++)  // 1 2 3 4
    {
        for(int j = 0 ; j < n - i; j ++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j] , arr[j+1]);
            }
        }
    }
    // we can also print here 

    // for(int x : arr)
    // {
    //     cout<< x << " ";
    // }
}


//2nd selection sort ;
// worst case -> o(n * n)     , best case -> o(n) (already sorted)    , space-> o(1) constant ; 
void Selectionsort(vector<int> &arr , int n)
{
    for(int i = 0 ; i < n - 1  ; i++)
    {
        int mini = i ;
        for(int j = i + 1 ; j < n ; j++)
        {
            if(arr[mini] > arr[j])
            {
                mini = j;
            }
        }
        swap( arr[mini] , arr[i]);
    }
}
int main()
{
    int n ;
    cin>> n;
    vector<int> arr(n) ;
    for(int i = 0 ; i< n; i++)
    {
        cin>> arr[i];
    }
    // Bubblesort(arr , n) ;

    Selectionsort(arr , n) ;
    // for(int x : arr)
    // {
    //     cout<< x << " ";
    // }
    
    for(int i = 0 ;i < n; i++)
    {
        cout<< arr[i] << " ";
    }
    
}


// 3rd question - > merge two arrays

class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        vector<int> c(n + m);
        int i = 0 ;
        int j = 0;
        int k = 0; // to storing in c;
        while(i< m && j < n)
        {
            if(a[i] > b[j])
            {
                c[k] = b[j];
                j++;
                k++;
            }
            else{
                c[k] = a[i] ;
                i ++ ;
                k++;
            }
        }
        
        // if element is left in i 
        while(i < m)
        {
            c[k] = a[i];
            i++;
            k++;
        }
        
        // if element is left in i 
        while(j < n)
        {
            c[k] = b[j] ;
            j ++ ;
            k++;
        }
        for(int i = 0 ; i< c.size() ; i++)
        {
            a[i] = c[i] ;
        }
    }
};


//4 merge sort 

// worst -> p(nlog(n)) , best-> o(n)     ,  space-> o(5n) = o(n);

class Solution {
public:
    
    vector<int> conq(vector<int>&a , vector<int>&b , int m , int n )
    {
        vector<int> c(n + m);
        int i = 0 ;
        int j = 0;
        int k = 0; // to storing in c;
        while(i< m && j < n)
        {
            if(a[i] > b[j])
            {
                c[k] = b[j];
                j++;
                k++;
            }
            else{
                c[k] = a[i] ;
                i ++ ;
                k++;
            }
        }
        
        // if element is left in i 
        while(i < m)
        {
            c[k] = a[i];
            i++;
            k++;
        }
        
        // if element is left in i 
        while(j < n)
        {
            c[k] = b[j] ;
            j ++ ;
            k++;
        }
        return c;
    }
    
    vector<int> divide(vector<int> &arr , int start , int end)
    {
        if(start == end)
        {
            vector<int>temp ;
            temp.push_back(arr[start]) ;
            return temp ;
        }
        int mid = start + (end- start) / 2 ;
        vector<int> left = divide(arr , start , mid);
        vector<int> right = divide(arr , mid + 1 , end) ; 
        vector<int> ans = conq(left , right , left.size() , right.size()) ;
        return ans ;
    }
    
    vector<int> sortArray(vector<int>& arr)
    {
        int n = arr.size() ;
        int start = 0 , end = n - 1 ;
        return divide(arr , start , end) ;
         
    }
};
