class Solution {
public:
    #define mod 1000000007
    int numTilings(int n) 
    {
        vector<int > dp ( 1001 ) ;
        dp[1] = 1 ;
        dp[2] = 2 ;
        dp[3] = 5 ;
        for(int i = 4 ; i < 1001 ; i++)
        {
            dp[i] = ((dp[ i - 1] * 2) % mod  + (dp [i - 3])) % mod ;
        }
        return dp[n ];
    }
};