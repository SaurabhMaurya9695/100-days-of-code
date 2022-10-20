
#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int firstRepeated(int arr[], int n) {
        vector<int> a;
        for(int i = 0 ; i< n ; i++)
        {
            a.push_back(arr[i]);
        }
        unordered_map<int , int > mp;
        for(auto x : a)
        {
            mp[x]++;
        }
    
        for(int i = 0 ; i< a.size() ; i++)
        {
            if(mp[a[i]] > 1)
            {
                return i + 1 ;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; ++i) cin >> arr[i];
        Solution ob;
        cout << ob.firstRepeated(arr, n) << "\n";
    }

    return 0;
}

// } Driver Code Ends