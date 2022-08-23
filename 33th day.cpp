/* print stairs path */
#include<bits/stdc++.h>
using namespace std ;


void solve(int n , string ans)
{
    if(n == 0)
    {
        cout<< ans << endl;
        return ;
    }
    if(n < 0) return ;
    
    solve(n-1 , ans + "1");
    solve(n-2 , ans + "2");
    solve(n-3 , ans + "3");
}
int main()
{
    int n ;
    cin>> n ;
    solve(n ,  "");
}

/* print permutations */
#include <iostream>
using namespace std;

void solve(string s, string ans)
{
    if(s.size() == 0)
    {
        cout<< ans << endl;
        return ;
    }

    int n = s.size() ;
    for(int i = 0 ; i< n ; i ++)
    {
        char ch = s[i];
        string left = s.substr(0 , i);
        string right = s.substr(i+1);
        string total = left + right;
        solve( total ,  ans + ch );
    }

}

int main(){
    string str;
    cin>>str;
    solve(str,"");
    
}


/* `````````````Flood Fill `````````````````````````*/

#include<iostream>
#include<vector>

using namespace std;

void floodfill(vector<vector<int>> maze , int row , int col , string psf , vector<vector<int>> &visited) 
{
    // boundary cases
    if(row < 0 || col < 0 || row >= maze.size() || col >= maze[0].size() || maze[row][col] == 1 || visited[row][col] == true)
    {
         return;
    }
    else if(row == maze.size() - 1 && col == maze[0].size() - 1) // sr == dr && sc == dc
    {
         cout<<(psf) << endl;
         return;
    }

      visited[row][col] = true; // when we are entering in the maze
      
      floodfill(maze, row - 1, col, psf + "t", visited);
      floodfill(maze, row, col - 1, psf + "l", visited);
      floodfill(maze, row + 1, col, psf + "d", visited);
      floodfill(maze, row, col + 1, psf + "r", visited);
      
      visited[row][col] = false; //when our fun is ending then we have to remove the sign 
}

int main() {
    int n, m;
    cin >> n >> m;
    vector < vector < int >> arr(n, vector < int > (m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    vector < vector < int >> vis(n, vector < int > (m));
    floodfill(arr ,  0 ,  0 , "" , vis);
}

/* `````````````````target sum subset```````````````````````*/
#include<bits/stdc++.h>
using namespace std;


void solve(vector<int> arr , int idx , string ans , int sum , int target  )
{

  // base case
  if(sum > target){
      return;
  }

  if(idx == arr.size()){
      if(sum == target){
          cout<<(ans + ".") << endl;
      }
      return;
  }

        solve(arr, idx + 1, ans + to_string(arr[idx]) + ", ", sum + arr[idx], target);
        solve(arr, idx + 1, ans , sum, target);
    
}
int main(){
  int n ;
  cin>> n;
  vector<int>arr(n );
  for(int i = 0 ; i < n ; i++)
  {
    cin>> arr[i];
  }
  int target ;
  cin>> target;

  solve(arr , 0 ,""  , 0,  target);
}

/*````````````````````N queen `````````````````````````*/
