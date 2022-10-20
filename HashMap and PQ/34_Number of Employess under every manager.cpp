#include<bits/stdc++.h>
using namespace std ;
#define ll long long 

void getsize(unordered_map<string , vector<string> > & tree , string ceo , map<string , int > & ans )
{
	
}

void solve(unordered_map<string, string> &mp)
{
	unordered_map<string , vector<string> > mngrEmpMap;
	string ceo = "";
	for (auto d : mp) {
        string emp = d.first;
        string mngr = d.second;
        if (emp != mngr) // excluding emp-emp entry
        {
            // If 'emp' is the first employee under 'mngr'
            if (mngrEmpMap.find(mngr) == mngrEmpMap.end()) {
                vector<string> directReportList;
                directReportList.push_back(emp);
                mngrEmpMap[mngr] = directReportList;
            }
            else {
                mngrEmpMap[mngr].push_back(emp);
            }
        }
        else{
        	ceo = emp;
        }
    }
    map<string , int > ans;
    getsize(mngrEmpMap , ceo , ans);
}
int main()
{
	int n ;
	cin >> n ;
	unordered_map<string, string > mp;
	while(n--)
	{
		string s, t;
		cin >> s >> t;
		mp[s] = t;
	}
	solve(mp);
	return 0;
}