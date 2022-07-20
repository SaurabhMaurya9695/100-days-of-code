                                // Agressive cow
#include<bits/stdc++.h>
using namespace std ;

bool ispossible(int d , vector<int> arr , int n , int c)
{
    int placed = 1 ;
    int firstcow = arr[0];
    // first cow is already placed that's why we are staring our loop from i = 1 ;
    for(int i = 1 ; i < n ; i++)
    {
        if(arr[i] - firstcow >= d )
        {   
            placed++;
            firstcow = arr[i];
        }
    }
    if(placed >= c)
    {
        return true;
    }
    else{
        return false;
    }
}

int solve(vector<int> arr , int n , int c)
{
    sort(arr.begin() , arr.end());   // 1 2 4 8 9
    int start = 1; //min distance between any two cows;
    int end = arr[n-1] - arr[0] ; // maxc dist
    int ans = -1;
    int mid ;
    while(start <= end){
         mid = start + (end  - start ) / 2 ;
        if(ispossible(mid , arr , n , c) == true )
        {
            ans = mid ;
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
        
    }
    return ans ;
}


int main()
{
    int t;
    cin>> t;
    while(t--){
        int stall, c ;  // 5 3
        cin>> stall >> c;
        vector<int> pos (stall);
        for(int i = 0 ; i < stall  ;i ++)
        {
            cin>> pos[i];   // 1 2 4 8 9
        }
        cout<< solve(pos , stall , c)  << endl;
    }
}


                                        /// stock span problem
#include<bits/stdc++.h>
using namespace std ;


// bruteforce  ; time -> o(n * n) , space -> o(1) ;
// void solve1(vector<int> arr , int n)
// {
//     for(int i = 0 ; i< n ; i++)
//     {
//         int days = 0;
//         for(int j = i; j >=0 ; j--)
//         {
//             if(arr[i] >= arr[j])
//             {
//                 days++;
//             }
//             else{
//                 break;
//             }
            
//         }
//         cout<<"the span of ith day is : " << i <" " << days << endl; 
//     }
// }


// optimized
// pair<data_type,data_type> p;
// ans.push_back(make_pair(arr[i] , days) )
// ans.push_back({arr[i] , days}) ;
void solve2(vector<int>&arr , int n)
{
    // pair<int,pair<int,int>> {2 ,{3 , 4}}
    stack<pair<int,int>> stk ;
    vector<int> ans;
    for(int i = 0 ; i< n ; i++)
    {
        int days = 1;
        while(stk.size() > 0 && arr[i] >= stk.top().first)
        {
            days += stk.top().second;
            stk.pop();
            
        }
        stk.push({arr[i] , days}) ; //pushing pair inside stack ;
        ans.push_back(days);
    }
    for(int x : ans)
    {
        cout<< x << " ";
    }
    
   
}
int main()
{
    int n ;
    cin>> n;
    vector<int> arr(n);
    for(int i = 0 ; i< n ; i++)
    {
        cin>> arr[i];
    }
    solve2(arr  , n) ;
}
