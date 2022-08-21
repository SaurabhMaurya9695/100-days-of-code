// get kpc
#include<iostream>
#include<string>
#include<vector>
using namespace std;
                    // 0      1       2       3      4        5      6      7       8      9
vector<string> codes={".;" , "abc" ,"def" , "ghi" , "jkl" , "mno" ,"pqrs" ,"tu" , "vwx" , "yz"};
vector<string> getKPC(string s)
{
    //base case ;
    if(s.size() == 0)
    {
        return {""};
    }
    // exceptation : 576 -> 5 -> 76
    char fch = s[0]; // 5
    string rest =s.substr(1) ; //76;
    vector<string> ans = getKPC(rest);
    string keypad = codes[fch - '0']; //pqrs   // 54 - 48
    vector<string> res;
    for(int i = 0 ; i< keypad.size() ; i++)
    {
        char keychar = keypad[i];
        for(string ss : ans)
        {
            res.push_back(keychar + ss);
        }

    }
    return res;
  
}


int main(){
    string s;
    cin >> s;
    vector<string> ans = getKPC(s);
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


/*````````````````````````print Subsequence ```````````````````````````*/
#include <bits/stdc++.h>
using namespace std;


// yvtA
void printSS(string s, string ans)
{
    if(s.size() == 0){
        cout<< ans << endl;
        return ;
    }
   // we have two choices now ;
   char fchar = s[0]; // y
   string rest = s.substr(1);// vta
   printSS(rest , ans + fchar);  //yes
   printSS(rest , ans + ""); // no
   
}

int main(){
    string str;
    cin >> str;
    printSS(str, "");
}
