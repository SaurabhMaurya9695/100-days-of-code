//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    string unique(string s)
    {
        string str;
        int len = s.length();
        for (int i = 0; i < len; i++)
        {
            char c = s[i];
            auto found = str.find(c);
            if (found == std::string::npos)
            {
                str += c;
            }
        }
        return str;
    }
    string removeDuplicates(string str)
    {
        return unique(str);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends