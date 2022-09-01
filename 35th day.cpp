                        /* Joseph problem */
class Solution {
public:
    int findTheWinner(int n, int k) {
        
        queue<int> q;
        for(int i = 1 ; i <= n ; i++)
        {
            q.push(i);    // 1 2 3 4 5 
        }
        while(q.size() != 1)
        {
            int del = k - 1;
            while(del --)
            {
                int x = q.front();
                q.pop();
                q.push(x);
            }
             q.pop();
            
        }
        return q.front();
    }
};




                    /*Gold Mine 2*/

#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> arr , int row , int col , int dr , int dc , vector<vector<bool>> &vis , vector<int> & bag)
{
    // boundary cases;
    if(row < 0 || col < 0 || row >= dr || col >= dc || arr[row][col] == 0 || vis[row][col] == true )
    {
        return;
    }
    vis[row][col] = true;
    bag.push_back(arr[row][col]);
    solve(arr , row , col + 1 , dr , dc, vis , bag); // right
    solve(arr , row , col - 1 , dr , dc, vis , bag); // left
    solve(arr , row - 1 , col , dr , dc, vis , bag); //up
    solve(arr , row + 1, col , dr , dc, vis , bag); // dowm ;
}

int main()
{
    int n , m ;
    cin >> n >> m;
    vector<vector<int>> arr(n , vector<int>(m));
    for(int i = 0; i< n ; i++)
    {
        for(int j = 0;j < m ; j ++)
        {
            cin>> arr[i][j];
        }
    }
    
    int maxi = INT_MIN;
    int sum = 0;
    vector<vector<bool>> vis(n , vector<bool> (m , false));
    for(int i = 0 ; i< n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            vector<int> bag ;
            solve(arr , i , j , n , m , vis , bag);
            for(int x : bag)
            {
                sum += x;
            }
            
            if(sum > maxi)
            {
                maxi = sum;
            }
        }
    }
    cout<<` maxi << endl;
}

                          /*Sudoko Solver */
class Solution {
public:

//check if isitsafeto place there
    bool valid(vector<vector<char>> &board,int x,int y,int po)
    {
        // checking in col
        for(int i=0;i<board[0].size();i++)
        {
            if(board[x][i]-'0' == po)
                return false;
        }

        // checking in row
        for(int i=0;i<board.size();i++)
        {
            if(board[i][y]-'0' == po)
                return false;
        }

        // checking at 3 * 3 matrix;
        x = 3 * ( x / 3);
        y = 3 * ( y / 3);
        for(int i = x; i < x + 3; i++)
        {
            for(int j = y;j < y + 3; j++)
           {
                if(board[i][j]-'0' == po) // converting into value first
                    return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board,int i,int j)
    {
        if(i == board.size()) // we are at the end ;
            return true;
        
        int ni,nj;
        if(j == board[0].size()-1) // when we are at right ending col ;
        {
            ni = i + 1; // the increase the row
            nj = 0; // col remain starting from 0;
        }
        else
        {       
            ni = i;
            nj= j + 1;
        }
        if(board[i][j] != '.') // means there is already value filled
            return solve(board,ni,nj); // we make calls in next col 
        else
        { 
            // there is a space ;
            for(int po=1;po<=9;po++) // we are putting each value 
            {
                if(valid(board,i,j,po) == true) 
                {   
                    board[i][j]= po + '0'; 
                    if(solve(board,ni,nj)) // make again from there
                        return true;
                    else
                        board[i][j]='.'; // else we are putiting space when we are backtracking 
                }
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
    }
};


