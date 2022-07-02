#include<bits/stdc++.h>
using namespace std ;

// by default pass by value 
// void solve(int n) // print 
// {
//     cout<< n << endl;
// }

// int solve(int  n)
// {
//     return n;
// }

// int solve(string   n)
// {
//     return n.size() ;
// }


vector<int> solve(vector<vector<int>> arr)
{
    return arr[1];
}
int main()
{
    // void , int , string , vector<vector<int>> , vector<int>  <<<- these are the return types ;
    // pass by value or pass by reference ;

    // void -> return nothing 
    // int n ;
    // string s;
    // cin>> s;
    // cout<<solve(s) << endl ;


    //by array
    // int arr[n][m];
    // vector<int>arr(size , fill);
    int n , m ;
    cin >> n >> m;
    vector<vector<int>> arr( n , vector<int>(m)); // 2d matrix of size n * m;
    for(int i  = 0; i< n ; i++)
    {
        for(int j = 0 ; j< m; j++)
        {
            cin>> arr[i][j];
        }
    }
    // for(int i  = 0; i< n ; i++)
    // {
    //     for(int j = 0 ; j< m; j++)
    //     {
    //         cout<< arr[i][j] << " ";
    //     }
    //     cout<<endl;
    // }
    vector<int> store = solve(arr);
    for(int i = 0; i< store.size() ; i++)
    {
        cout<< store[i] <<" ";
    }

    
    
}
