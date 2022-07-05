// 1st Question

// void solve()
// {
    // string s;
    // cin>> s;
    // int n = s.size() ;
    // int i = 0;
    // string ans ="";
    // while(i < n)
    // {
    //     if(s[i] == '.')
    //     {
    //         ans += '0';
    //         i++;
    //     }
    //     else if(s[i] == '-')
    //     {
    //         if(i+1 < n)
    //         {
    //             if(s[i+1] == '.')
    //             {
    //                 ans += '1';
    //             }
    //             else{
    //                 ans += '2';
    //             }
    //         }
    //         i += 2;
    //     }
    // }
    // cout<< ans << endl;
//     return ;
// } 


#include<bits/stdc++.h>
using namespace std;
int  main()
{
    int n , m ;
    cin>> n  >> m ;
    vector<vector<int>> arr(n , vector<int>(m)) ;// defining 2d matrix;
    for(int i = 0; i< n; i++)
    {
        for(int j = 0; j< m ; j++)
        {
            cin>> arr[i][j];
        }
    }

    int d = 0; 
    int i = 0 , j = 0;
    while(true)  // until we get out from the loop / matrix
    {

        d = (d + arr[i][j]) % 4 ;
        if(d == 0)
        {
            // east
            j++;
        }
        else if(d == 1)
        {
            //south
            i++;
        }
        else if(d == 2)
        {
            // west ;
            j--;
        }
        else{
            // north;
            i--;
        }

        //out of bopundary condition;
        if(i < 0) // out of loop ;
        {
            i++;
            break;
        }
        else if(j < 0)
        {
            j++;
            break;
        }
        else if(i == n )
        {
            i--;
            break;
        }
        else if( j == m)
        {
            j--;
            break;
        }
    }
    cout<< "the exit point of matrix is " << i << " "<< j << endl;
}





// 3rd qusetion 



#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> arr , int n)
{
    int res = 0;
    for(int i = 0 ; i< n; i++)
    {
        int mini = INT_MAX;
        int col = 0 ;
        for(int j = 0 ; j< n ; j++)
        {
            if(arr[i][j] < mini)
            {
                mini = arr[i][j];
                col = j;
            }
        }
        
        // traverse in col ;
        int maxi = INT_MIN;
        for(int k = 0; k < n ; k++)
        {
            if(arr[k][col] > maxi)
            {
                maxi = arr[k][col];
            }
        }
        
        if(mini == maxi)
        {
            return mini;
        }
        else{
            continue;
        }
    }
    return -1;
}

int main()
{
    int n ;
    cin>> n;
    vector<vector<int>> arr(n , vector<int>(n)) ;  // n * n ;
    for(int i = 0 ; i< n ; i++)
    {
        for(int j = 0 ; j< n; j++)
        {
            cin>> arr[i][j] ;
        }
    }
    
    int ans = solve(arr , n) ;
    if(ans > 0)
    {
        cout<< ans << endl;
    }
    else{
        cout<<"Invalid input\n";
    }
    
}


// 4th question
#include<bits/stdc++.h>
using namespace std;

int main(){
    //write your code here
    int  n ;
    cin>>  n ;
    vector<int>arr(n) ;
    for(int  i =0 ; i< n; i++)
    {
        cin>> arr[i] ;
    }
    // int x = *max_element(arr.begin() , arr.end()) ;
    // int y = *min_element(arr.begin() , arr.end()) ;
    // cout<< abs(x -y) << endl;
    
    // method 2 
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for(int i = 0 ; i < n ; i++)
    {
            if(arr[i] > maxi)
            {
                maxi = arr[i] ;
            }
            if(arr[i] < mini)
            {
                mini = arr[i];
            }
    }
    cout<< abs(mini  - maxi) << endl;
}
