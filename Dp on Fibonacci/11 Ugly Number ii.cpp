class Solution {
public:
    int nthUglyNumber(int n) 
    {
        int dp[n + 1];
        dp[1] = 1;
        int p2 = 1 , p3 = 1 , p5 = 1;
        
        for(int i = 2 ; i<=n ; i++)
        {
            int p22 = 2 * dp[p2];
            int p33 = 3 * dp[p3];
            int p55 = 5 * dp[p5];
            int ans = min({p22 , p33 , p55});
            dp[i] = ans ;
            if(ans == p22) p2++;
            if(ans == p33) p3++;
            if(ans == p55) p5++;
        }
        return dp[n];
    }
};