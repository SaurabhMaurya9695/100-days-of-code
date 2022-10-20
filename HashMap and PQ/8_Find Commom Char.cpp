class Solution
{
public:
    vector<string> commonChars(vector<string> &s)
    {
        int n = s.size();
        map<char, int> mp;
        string temp = s[0];
        for (auto x : temp)
        {
            mp[x]++;
        }
        map<char, int> mpp;
        for (int i = 1; i < s.size(); i++)
        {
            map<char, int> mpp;
            string ss = s[i];
            for (auto x : ss)
            {
                mpp[x]++;
            }
            // check in both ;
            for (auto y : s[0])
            {
                if (mp[y] != mpp[y]) // finds in second ;
                {
                    mp[y] = min(mp[y], mpp[y]);
                }
            }
        }
        // for(auto x:  mp)
        // {
        //     cout << x.first << " " << x.second << " ";
        // }
        // cout<< endl;
        vector<string> ans;
        for (auto ch : s[0])
        {
            if (mp[ch] > 0)
            {
                ans.push_back(string(1, ch));
                mp[ch]--;
            }
        }
        return ans;
    }
};