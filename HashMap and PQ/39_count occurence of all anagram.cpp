//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    int k = pat.size() ;
	    unordered_map<char , int > mp;
	    for(auto x : pat) mp[x] ++;
	    // sliding window ;
	    int i = 0 , j = 0 , ans = 0 ;
	    int size = mp.size();
	    while(j < txt.size())
	    {
	        if(mp.find(txt[j]) != mp.end())
	        {
	            mp[txt[j]] --;
	            size = (mp[txt[j]] == 0) ? size - 1 : size ;
	        }
	        
	        if(j - i + 1 == k)
	        {
	            if(size == 0)
	            {
	                ans ++;
	            }
	            if(mp.find(txt[i]) != mp.end())
    	        {
    	            mp[txt[i]] ++;
    	            size = (mp[txt[i]] == 1) ? size + 1 : size ;
    	        }
	            i++;
	        }
	       j++;
	    }
	    return ans ;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends