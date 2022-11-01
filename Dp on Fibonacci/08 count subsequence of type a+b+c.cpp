//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template 

class Solution{
  public:
  #define mod 1000000007
  #define ll long long
    int fun(string &s) {
        ll n = s.size() ;
        ll aplus = 0 ;
        ll abplus = 0 ;
        ll abcplus = 0;
        for(ll i = 0 ; i< n ; i++)
        {
            char ch = s[i];
            if(s[i] == 'a') // aplus;
            {
                aplus =( ( aplus + aplus) % mod + 1) % mod;
            }
            else if(s[i] == 'b') // abplus ;
            {
                abplus = ((abplus + abplus) % mod + aplus )% mod;
            }
            else if(s[i] == 'c') // abcplus 
            {
                //abc c'=> abc // abcc'
                abcplus = ( (abplus + abcplus) % mod + abcplus) % mod;
            }
        }
        return abcplus % mod ;
    }
};

//{ Driver Code Starts.
 
int main()
 {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.fun(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends