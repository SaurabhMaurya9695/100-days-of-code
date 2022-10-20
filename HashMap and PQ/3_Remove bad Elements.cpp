void solve()
{
   ll n ;
   cin >> n ;
   vector<ll > arr = readvector(n);
   map<int,int> mp ;
   for(int x : arr)
   {
        mp[x]++;
   }
    ll x, y;
    ll maxif = INT_MIN;
    for(auto it : mp)
    {
        if(it.second > maxif)
        {
            maxif = it.second ;
        }    
    }
    if(mp.size() == 1) {
        cout<< 0 << endl;
        return ;
    }
    else if(mp.size() == n)
    {
        cout<< n - 1 << endl;
        return ;
    }
    else{
        cout<< abs(maxif- n) << endl;
        return ;
    }

}