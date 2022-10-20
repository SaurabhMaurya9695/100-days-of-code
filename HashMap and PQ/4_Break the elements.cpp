void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    int i;
    int c = 0;
    for(int i = 0 ; i< n  ; i++)
    {
        cin >> a[i];
        if (a[i] & 1)
            c++;
    }
    if (c == n || c == 0)
        cout << 0 << endl;
    else
    {
        cout << n - c << endl;
    }

}