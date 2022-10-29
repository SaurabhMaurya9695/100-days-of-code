
class Solution{
public:
	#define ll long long
	#define mod 1000000007
	
	
	ll solve(vector<ll> &dp , ll n)
	{
	    if(n == 0) return 1 ;
	    if(n == 1) return 2 ;
	    if(dp[n] != -1)
	    {
	        return dp[n];
	    }
	    
	    else{
	        return dp[n] = (solve(dp , n - 1) + solve(dp , n - 2)) % mod ;
	    }
	}
	ll countStrings(int n) 
	{
	   //  for n =0 - >  possiblities are 0  ; total -> 1
	   //  for n = 1 ->  possiblities are 0 and 1 ; total -> 2 ;
	   //  for n = 2 -> possibilities are 00 , 01 ,10 ; total -> 3 ;
	   //  for n = 3-> possiblities are 000, 010, 100, 101, 001 ; total -> 5 ;
	   
	   //this shows the fibonacci sequence  1 , 2 , 3 , 5 .....
	   vector<ll> dp(n + 1 , -1) ;
	   return solve(dp , n) ;
	}
};


									// Tabulations 
class Solution{
public:
	#define ll long long
	#define mod 1000000007
	ll countStrings(int n) {
	   vector<ll > dp0 ( n + 1) ;// ending with zero ;
	   vector<ll > dp1 ( n + 1) ;// ending with ones ;
	   dp0[1] = 1; // length with 1 ;
	   dp1[1] = 1; // length with 1 ;
	   for(ll i = 2 ; i <=  n ; i++)
	   {
	       dp0[i] = (dp0[i - 1] + dp1[i - 1]) % mod;
	       dp1[i] = dp0[i -1 ];
	   }
	   return (dp0[n] + dp1[n]) % mod ;
	   
	}
};