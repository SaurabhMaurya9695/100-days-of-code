// Problem: A. Number Replacement
// Contest: Codeforces - Codeforces Round  #828 (Div. 3)
// URL: https://codeforces.com/contest/1744/problem/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n ;
		cin >> n ;
		vector<int > arr(n) ;
		for(auto &x : arr)
		{
			cin >> x;
		}
		string s;
		cin >> s;
		unordered_map<int  , char > mp ;
		bool ok = true;
		for(int i = 0 ; i< n ; i++)
		{
			if(mp.find(arr[i]) == mp.end()) // no found
			{
				mp[arr[i]] = s[i];	
			}
			else if(mp.find(arr[i]) != mp.end())
			{
				if(mp[arr[i]] != s[i])
				{
					ok = false;
					break;
				}
			}
		}
		if(ok == true)
		{
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
		
	}
	return 0;
}
