// 1st question
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	// your code goes here
	ll t ;
	cin>> t;
	while(t--)
	{
	    ll n ;
	    cin >>n;
	    if( n % 3  == 0 )
	    {
	        cout<< 0 << endl;
	        
	    }
	    else if(n % 3 == 1)
	    {
	        cout<< 2 << endl;
	        
	    }
	    else{
	        cout<< 1 << endl;
	    }
	}
	
	return 0;
}




// recursion code ;

// 2nd

void solve()
{
    ll n ;
    cin >> n;
    if( n <= 3)
    {
        cout<< -1 << endl;
        return ;
    }
    else{
        vector<ll > dp(n) ;
        dp[0] = 1;
        dp[1] = 2;
        for(int i = 2 ; i< n ; i++)
        {
            dp[i] = dp[i-1] + dp[i - 2] + 1 ;
        }
        for(ll &x : dp)
        {
            cout<< x << " ";
        }
        cout<< endl;
    }
} 


// before doing any question

//1 -> top to dowm read ;
// 2 -> complexity 
// 3-> copy and pen 
// 4- try to analyise from the tc;
// 5 -> observation and code



// 3rd->

#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
#define endl "\n"


int solve(ll n , ll d)
{
    ll cnt = 0 ;
    while(n != 0)
    {
        int r= n % 10;
        if(r== d)
        {
            cnt++;
        }
        n = n / 10;
    }
    return cnt;
}
int main()
{
    ll n;
    cin>> n;
    ll d;
    cin>> d;
    cout<<solve(n, d) << endl;
    
}
