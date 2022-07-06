#include<bits/stdc++.h>
using namespace std ;



// vector<int> solve(vector<vector<int>> & arr)
// {


//     return vector;
// }
int main()
{
    int n , m ;
    cin>> n >> m ;
    vector<vector<int>>arr(n , vector<int>(m));
    for(int i = 0 ; i< n; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            cin>> arr[i][j];
        }
    }

    // vector<int> ans = solve(arr);
    // for(int i = 0; i< n ; i++)
    // {
    //     cout<< ans[i] << " ";
    // }
    // printing spiral matrix;
   
    int minr = 0 , minc = 0 , maxr = n-1 , maxc = m-1 ;
    int total = n * m ;
    int cnt = 0 ;
    while(cnt < total)
    {
        // left wall ;
        for(int i = minr , j = minc ; i<= maxr && cnt < total ; i++)
        {
            cout<<arr[i][j] << " ";
            cnt++;
        }
        minc++;
        // bottom wall ;
        
        for(int i = maxr  , j = minc  ; j <= maxc && cnt < total ; j++)
        {
            cout<< arr[i][j] << " ";
            cnt++;
        }
        maxr--;
        
        // right wall ;
        
        for(int i = maxr  , j = maxc ;  i >= minr && cnt < total ; i --)
        {
            cout<< arr[i][j] << " ";
            cnt++;
        }
        maxc--;
        // top wall ;
        for(int i =  minr, j = maxc ; j >= minc  && cnt < total; j --)
        {
            cout<< arr[i][j] << " ";
            cnt++;
        }
        minr++;
        
        
    }
    
}


// 2nd question 

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size() == 0 || nums.size() == 1) {
            return nums.size();
        }
        
        // Sorting the vector
        sort(nums.begin(), nums.end());
        
        int countLength = 0;
        int maxCountLength = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i+1] - nums[i] == 1) {
                countLength++;
            } else if(nums[i+1] == nums[i]) {
                continue;
            } else {
                // maxCountLength = max(maxCountLength, countLength);
                if(countLength > maxCountLength)
                {
                    maxCountLength = countLength ;
                }
                else{
                    maxCountLength = maxCountLength;
                }
                countLength = 0;
            }
        }
        
        maxCountLength = max(maxCountLength, countLength);
        
        return (maxCountLength + 1);
    }
};




// 3rd qusetion 
#include<bits/stdc++.h>
using namespace std;


void solve(vector<vector<int>> &arr , int k )
{
    int n = arr.size() ;
    int m = arr[0].size() ;
    int iidx = -1 , jidx = -1;
    for(int i = 0; i< n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(arr[i][j] == k)
            {
                iidx = i ;
                jidx = j;
                break;
            }
        }
    }
    // cout<< iidx << " "<<jidx << endl;
    if(iidx >= 0 && jidx >= 0)
    {
        cout<< iidx << "\n"<<jidx << endl;
    }
    else{
        cout<<"Not Found\n";   
    }

}



int main()
{
    int n ;
    cin>>n;
    vector<vector<int>>arr(n , vector<int>(n)) ;// n*n ;
    for(int i = 0; i< n; i++)
    {
        for(int j = 0 ; j< n; j++)
        {
            cin>> arr[i][j];
        }
    }

    int k ;
    cin>> k;

    solve(arr , k) ;

}



// 4th check palindrome

#include<bits/stdc++.h>
using namespace std ;

bool check(string s)
{
    int start = 0 ;
    int end = s.size() - 1 ;
    while(start < end)
    {
        if(s[start] != s[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}
void solve()
{
    string s;
    cin>> s;
    cout<< check(s) << endl;
}
int main()
{
    int t;
    cin>> t;
    while(t--)
    {
        solve() ;
    }
    
    return 0;
}



