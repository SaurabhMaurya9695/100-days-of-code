// Problem: C. Number Game
// Contest: Codeforces - Educational Codeforces Round 138 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1749/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
/*
 *    coder :: Saurabh Maurya
 *        >>> INDIA <<<
 */
 #define sz(x) (int)(x).size()
#define ll long long
#define ff first
#define ss second
#define minheap priority_queue<long long, vector<long long>, greater<long long>>
#define endl "\n"
#define all(x) (x.begin() , x.end())
#define sortarr(arr, n) sort(arr, arr + n);
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define pb push_back
#define PI 3.14159265358979323846
#define mod 1000000007
#define print(v)                       \
    for (int i = 0; i < v.size(); i++) \
    {                                  \
        cout << v[i] << " ";           \
    }
#define maxelement(nums) *max_element(nums.begin(), nums.end());
#define minelement(nums) *min_element(nums.begin(), nums.end());
#define py "Yes"
#define debug(x) cout << #x << " " << x << endl;
#define pn "No"
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
 
// movement in grid -> 2 d
const int x8[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int y8[8] = {0, 1, 0, -1, -1, 1, -1, 1};
const int x4[4] = {1, -1, 0, 0};
const int y4[4] = {0, 0, -1, 1};

template <class T>
vector<T> readvector(T n)
{
    vector<T> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    return arr;
}

multiset<ll> st ;
bool ispossible(ll mid )
{
	multiset<ll> newst ;
	for(auto x : st) newst.insert(x);
	// max value it can choose is mid;
	for(ll k = mid ; k> 0 ; k--)
	{
		if(newst.size() == 0) return false;
		auto ptr2 = newst.upper_bound(k) ; // return that idx ;
		if(ptr2 == newst.begin())
		{
			// only one element is present ;
			return false;
		}
		//its its have more than two idx then idx--;
		ptr2--;
		//after this erase that ptr2;
		newst.erase(ptr2);
		// after this if its size is not zero;
		if(newst.size() == 0) return false;
		else{
			ll newele = *newst.begin(); 
			newst.erase(newst.begin());
			newst.insert(newele + k);
		}
	}
	return true;
}

void solve()
{
	ll  n ;
	cin >> n ;
	vector<ll >arr = readvector(n);
	st.clear();
	if(n == 1)
	{
		if(arr[0] > 1) 
		{
			cout<<arr[0] << endl;
			return;
		}
		else{
			cout<<1<< endl;
			return ;
		}
	}
	// we have to choose max k ;
	ll l = 1 , r = n ; // max value
	ll ans = 0;
	for(auto x : arr) st.insert(x);
	while(l <= r)
	{
		
		ll mid = (l + (r - l) / 2);
		if(ispossible(mid  ) == true)
		{
			ans = mid;
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}
	cout<< ans << endl ;
	return ;
	
}
 
int main()
{
	fast;
	ll t;
	cin >> t;
	while(t--)
	{
		solve();
	}
}









 