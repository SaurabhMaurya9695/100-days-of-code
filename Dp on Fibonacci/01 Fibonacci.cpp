class Solution {
public:
    //1 recursion 
//     int fib(int n) {
       
//         if(n == 0 || n == 1)
//         {
//             return n;
//         }
//         else{
//             return fib(n - 1) + fib( n - 2 );
//         }
        
//     }
    
                        // 2 - Memorization 
//     int solve(int n , vector<int>&dp)
//     {
//         if(n == 0 || n == 1)
//         {
//             return n;
//         }
//         if(dp[n] != -1)
//         {
//             return dp[n];
//         }
        
//         dp[n] =  solve(n - 1 , dp) + solve(n - 2 , dp);
//         return dp[n];
        
//     }
    
//     int fib(int n)
//     {
//         vector<int> dp(n + 1 , -1);
//         return solve(n , dp);
//     }
    
                        // 3 - Tabulation 
//     int tab(vector<int> &dp ,int n)
//     {
//         dp[0] = 0;
//         dp[1] = 1;
//         for(int i = 2 ; i<= n; i++)
//         {
//             dp[i] = dp[i-1] + dp[i-2];
//         }
//         return dp[n];
        
        
//     }
//     int fib(int n) 
//     {   
//         // tabulation
//         vector<int> dp(n+1);
//         return tab(dp , n) ;
//     }
    
                // 4- space optimization
    int fib(int n)
    {
        if(n == 0 || n == 1) return n ;
        int prev1 = 1 , prev2 = 0 ;
        int curr = 0;
        for(int i = 2 ; i <= n ; i ++)
        {
            curr = prev1 + prev2 ;
            prev2  = prev1 ;
            prev1 = curr ;
        }
        return prev1;
    }
};




