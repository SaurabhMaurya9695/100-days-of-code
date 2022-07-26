                                    // online stock span
class StockSpanner {
public:
    stack<pair<int,int>> stk;
    StockSpanner() {
        
    }
    
    int next(int price) {
       
                            // Method 1;
        // if(stk.empty() || stk.top().first > price) // 100 > 80 
        // {
        //     stk.push({price , 1});
        //     return 1;
        // }
        // else {
        //     // 60 < 70 ;
        //     int current_span = 1;
        //     while(!stk.empty() && stk.top().first <= price)
        //     {
        //         current_span += stk.top().second;
        //         stk.pop();
        //     }
        //     stk.push({price , current_span});
        //     return current_span;
        // }
        
        
        int curr_span = 1;
        while(!stk.empty()&& stk.top().first <= price)
        {
            curr_span += stk.top().second;
            stk.pop();
        }
        stk.push({price ,curr_span});
        return curr_span;
       
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */




                                        // 132 pattern 


class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size() ;
        int thirdele = INT_MIN;  // nums[k];
        stack<int> stk;
        for(int i =  n - 1 ; i >=0 ; i--)
        {
            if(nums[i] < thirdele) return true;
            while(stk.size() > 0 && nums[i] > stk.top())
            {
                thirdele = stk.top();
                stk.pop();
            }
            stk.push(nums[i]);
        }
        return false;
    }
};


                                            // Largest area histogram
#include<bits/stdc++.h>
using namespace std ;

// next smaller to right idx;
vector<int>nsridx(vector<int> &arr , int n )
{
    vector<int> ans ;
    stack<int> stk;
    for(int i = n - 1 ; i>=0 ; i--)
    {
        while(stk.size() > 0 && arr[stk.top()] >= arr[i])
        {
            stk.pop();
        }
        if(stk.size() == 0)
        {
            ans.push_back(n);
        }
        else{
            ans.push_back(stk.top());
        }
        stk.push(i);
    }
    reverse(ans.begin() , ans.end());
    return ans;
}


// next smaller to left idx;
vector<int>nslidx(vector<int> &arr , int n )
{
    vector<int> ans2 ;
    stack<int> stk;
    for(int i = 0 ; i < n ; i ++ )
    {
        while(stk.size() > 0 && arr[stk.top()] >= arr[i])
        {
            stk.pop();
        }
        if(stk.size() == 0)
        {
            ans2.push_back(-1);
        }
        else{
            ans2.push_back(stk.top());
        }
        stk.push(i);
    }
    return ans2;
}


int solve(vector<int>&arr , int n)
{
    vector<int> nsr = nsridx(arr , n);
    vector<int> nsl = nslidx(arr , n) ;
    int maxarea = 0;
    for(int i = 0 ; i< n ; i++)
    {
       int  width = nsr[i] - nsl[i] - 1;
        int area = width * arr[i] ;
        if(area > maxarea)
        {
            maxarea = area ;
        }
    }
    return maxarea ;
    
    
    
}
int main()
{
    int n;
    cin>> n ;
    vector<int> arr(n);
    for(int i = 0 ; i< n ; i++)
    {
        cin>> arr[i];
    }
    cout<< solve(arr , n) << endl;
}
