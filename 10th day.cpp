// 1st -> partition an array ;

void partition(int arr[], int n, int pivot) {
  int i = 0 , j = 0 ;
  while(i < n)
  {
      if(arr[i] > pivot)
      {
          // increment i ;
          i++;
      }
      else{
          swap(arr , i , j) ;
          i++;
          j++;
      }
  }
}

// 2nd question 
class Solution {
public:
    vector<int> pivotArray(vector<int>& arr, int pivot) 
    {
        int n = arr.size() ;
        int i = 0 , j = 0;
        vector<int> left , right ;
        int pcnt = 0 ;
        while(i < n)
        {
            if(arr[i]  > pivot)
            {
                right.push_back(arr[i]);
            }
            else if(arr[i] < pivot)
            {
                left.push_back(arr[i]) ;      
            }
            else {
                // equal condition ;
                pcnt++;
            }
            i++;
        }
        
        while(pcnt -- )
        {
            left.push_back(pivot);
        }
        for(int i = 0 ; i< right.size() ; i++)
        {
            left.push_back(right[i]);
        }
        return left;
    }
};

// 3rd sort 0 and 1

// in 3pass ;
#include<bits/stdc++.h>
using namespace std ;

vector<int> sort01(vector<int>&arr)
{ 
    // worst case ->  o(n) ;
    //     best case -> o(1) ;
    //         space -> o(n) ;
    int cntz = 0 , cnto = 0 ;
    for(int x : arr)
    {
        if(x == 0)
        {
            cntz++;
        }
        else{
            cnto++;
        }
    }
           // o(n) space ;
    // vector<int> ans ;
    // while(cntz--)
    // {
    //     ans.push_back(0);
    // }
    // while(cnto--)
    // {
    //     ans.push_back(1);
    // }
    // return ans;

                // o(1) in terms of space;
    arr.clear() ;
    int k = 0;
    while(cntz--)
    {
        arr.push_back(0);
    }
    while(cnto--)
    {
        arr.push_back(1);
    }
    return arr;
}
int main()
{
    vector<int> arr = {0 , 1 , 1 , 1 , 0 , 0 , 0};
    vector<int> temp = sort01(arr) ;
    for(int x : temp)
    {
        cout<<x<< " ";
    }
}

//in one pass ;
void sort01(vector<int>& arr) {
    
    // worst case ->o(n)   , best case-> o(1) ,  space-> o(1);
  int n = arr.size() ;
  int i = 0 , j = 0 ;
  int pi = 1 ;
  while(i < n)
  {
      if(arr[i] == 1) i++;
      else{
          swap(arr , i, j) ;
          i++ ;
          j++;
      }
  }
}


// 4th -> quick sort ;
// 8-> 4-> 2-> 1 => 2 's power 
// worst case ->o(n *n) ;
// best case -> o(nlogn); 
// space ->  o(logn);
void quicksort(vector<int>& arr, int lo, int hi) {
  // base case ;
  if(lo > hi)
  {
      return ;
  }
  
  //choose pivot element;
  int pivot = arr[hi];
  int pi = partition (arr , pivot , lo , hi);
  quicksort(arr , lo, pi - 1) ;
  quicksort(arr , pi + 1 , hi);
  
}

//////////////////////////// partition  in terms of i & j/////////////////////////
public static int partition(int[] arr, int pivot, int lo, int hi) {
    System.out.println("pivot -> " + pivot);
    int i = lo, j = lo;
    while (i <= hi) {
      if (arr[i] <= pivot) {
        swap(arr, i, j);
        i++;
        j++;
      } else {
        i++;
      }
    }
    System.out.println("pivot index -> " + (j - 1));
    return (j - 1);
  }




// 5-> Quick select
int partition(vector<int>& arr, int pivot, int lo, int hi) {
  cout << "pivot -> " << pivot << endl;
  int curr = lo;
  int prev = lo - 1;
  while (curr <= hi) {
    if (arr[curr] <= pivot) {
      prev++;
      swap(arr, curr, prev);
    }
    curr++;
  }
  cout << "pivot index -> " << prev << endl;
  return prev;
}


int quickselect(vector<int>& arr, int lo, int hi, int k) {
  
    int pivot = arr[hi] ;
    int pi = partition(arr , pivot , lo , hi) ;
    int tbs = k ;
    if(pi > tbs)
    {
        // calls in right ;
        quickselect(arr , pi + 1 , hi , k) ;
    }
    else if(pi < tbs) // calls in Left ;
    {
        quickselect(arr , lo , pi - 1 , k);
    }
    return pivot;
}

