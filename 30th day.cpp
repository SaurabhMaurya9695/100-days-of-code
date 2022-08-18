#include <bits/stdc++.h>
#include <vector>
using namespace std;


//expectation -> []
// abcd
vector<string> gss(string s )
{
    // base case ;
    if(s.length() == 0) // " "
    {
        vector<string> temp ;
        temp.push_back("");
        return temp;
    }
    
    char fchar = s[0] ; // a // b // c // d
    string restchar = s.substr(1); // 1 till end ; -> bcd  -> cd // d // " "
    vector<string> ans =  gss(restchar) ;
    vector<string> temp ;
    for(auto x : ans)
    {
        // two choice add a before everyone or not;
        temp.push_back("" + x); // ""
    }
    for(auto x : ans)
    {
        // two choice add a before everyone or not;
        temp.push_back(fchar + x); // d 
    }
    return temp; // " " , d , cd, c , 
    
    
    
    
}

int main(){
    string s;
    cin >> s;
    vector<string> ans = gss(s );
    int cnt = 0;

    cout << '[';
    for (string str : ans){
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';
}
