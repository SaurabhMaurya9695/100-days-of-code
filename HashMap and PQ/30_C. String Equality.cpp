#include<bits/stdc++.h>
using namespace std ;
int main ()
{
    int t ;
    cin >> t;
    while(t--)
    {
        int n , k ;
        cin >> n >>k ;
        string s;
        cin>> s;
        string ss ;
        cin>>ss;
        bool ok = true;
        for(int i =  0 ; i< n - 1 ; i++)
        {
            if(s[i] == s[i + 1])
            {
                if(s[i] > ss[i])
                {
                    ok = false;
                    break;
                }
            }
            else if(s[i] != s[i + 1])
            {
                swap(s[i] , s[i + 1]);
            }
        }
        if(ok == false)
        {
            cout<<"No\n";
        }
        else{
            cout<<"No\n";
        }
    }
    return 0;
}
