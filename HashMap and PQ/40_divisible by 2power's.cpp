// Problem: D. Divisibility by 2^n
// Contest: Codeforces - Codeforces Round  #828 (Div. 3)
// URL: https://codeforces.com/contest/1744/problem/D
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


ll getcnt(ll x) 
{
	ll cnt = 0 ;
	while(x % 2 == 0)
	{
		x /= 2;
		cnt++;
	}
	return cnt;
}
void solve()
{
	ll n ;
	cin >> n;
	vector<ll > arr = readvector(n);
	//logic is to check how many power of 2 contains arr[i] ;
	ll cnt = 0 , extra = 0;
	vector<ll> b ;
	for(int i = 0 ; i< n ; i++)
	{
		// check how many 2's there ;
		cnt += getcnt(arr[i]);
		extra += getcnt(i + 1); // how many extra we get 
		b.push_back(getcnt(i + 1));
	}
	if(cnt >= n) // easy divisible 
	{
		cout<<0<< endl;
		return ;
	}
	if(cnt + extra < n)
	{
		cout<<"-1\n";
		return ;
	}
	ll ans = 0;
	sort(b.rbegin(), b.rend());

	for(auto x : b)
	{
		ans ++;
		if(cnt + x >= n) break;
		cnt += x;
	}
	
	cout<< ans << endl;
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




