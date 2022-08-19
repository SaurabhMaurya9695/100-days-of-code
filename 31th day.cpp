/*```````````````````````Get Subsequence`````````````````````````````*/
#include<bits/stdc++.h>
using namespace std;

vector<string> gss(string s)
{
    if(s.size() == 0)
    {
        vector<string> ans;
        ans.push_back("");
        return ans;
    }
    //taking first char;
    char ch = s[0] ;
    string rest = s.substr(1);
    vector<string> ans = gss(rest);
    vector<string> temp;
    for(string ss : ans)
    {
        temp.push_back("" + ss);
    }
    for(string ss : ans)
    {
        temp.push_back(ch + ss);
    }
    return temp;
}

int main(){
    string s;
    cin >> s;
    vector<string> ans = gss(s);
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

/*`````````````````````Get Maze Path `````````````````````````````````````*/
#include<iostream>
#include<vector>

using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column
vector <string> getMazePaths(int sr, int sc, int dr, int dc) 
{
    if((sr == dr) && (sc == dc))
    {
        return {""};
    }
    
    if((sr > dr) || (sc > dc))
    {
        return {};
    }
    //taking right call ;
    vector<string>hpath = getMazePaths(sr , sc + 1, dr , dc) ;
    vector<string>vpath = getMazePaths(sr + 1 , sc, dr , dc) ;
    vector<string> ans;
    for(auto ss : hpath)
    {
        ans.push_back("h" + ss);
    }

    for(auto ss : vpath)
    {
        ans.push_back("v" + ss);
    }

    return ans;
}

void display(vector<string>& arr){
    cout << "[";
    for(int i = 0;i < arr.size();i++){
        cout << arr[i];
        if(i < arr.size() -1) cout << ", ";
    }
    
    cout << "]"<<endl;
}


int main() {
    int n,m; cin >> n >> m;
    vector<string> ans = getMazePaths(0,0,n-1,m-1);
    display(ans);

    return 0;
}

/*````````````````````````Get stairs path`````````````````````````````*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> get_stair_paths(int n){
    // Base Case;
        if(n == 0 ){
            vector<string> bres ;
            bres.push_back("");
            return bres;
        }else if(n < 0){
            vector<string> bres ;
            return bres;
        }
        
        vector<string> path1 = get_stair_paths(n-1);
        vector<string> path2 = get_stair_paths(n-2);
        vector<string> path3 = get_stair_paths(n-3);
        
        // we are adding 1 before the everypath of 1;
        vector<string> ans ;
        for(string ss : path1)
        {
            ans.push_back("1" + ss);
        }
        
        for(string ss : path2)
        {
            ans.push_back("2" + ss);
        }
        
        for(string ss : path3)
        {
            ans.push_back("3" + ss);
        }
        
        return ans;
}

int main(){
    int n;
    cin >> n;
    vector<string> ans = get_stair_paths(n);
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
