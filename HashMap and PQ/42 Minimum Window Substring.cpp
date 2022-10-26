class Solution {
public:
    string minWindow(string s, string t) 
    {
        unordered_map<char , int > mp;
        for(auto x : s) mp[x]++;
        int n = s.size() ;
        int i = 0 , j = 0;
        int ans = INT_MAX , cnt = mp.size() ;
        string res ;    
        while(j < n)
        {
            if(mp.find(s[j]) !=mp.end())
               {
                   mp[s[j]]--;
                   if(mp[s[j]] == 0)
                   {
                       cnt--;
                   }
                   
               }
               while(cnt == 0)
               {
                   if(ans >  j - i + 1)
                   {
                       ans = j - i  + 1;
                       res = s.substr(i , j- i + 1);
                   }
                   if(mp.find(s[i]) != mp.end())
                   {
                       mp[s[i]]++;
                       if(mp[s[i]] == 1)
                       {
                           cnt++;
                       }
                   }
                   i ++ ;
               }
               j++;
        }
       return res;
    }
};