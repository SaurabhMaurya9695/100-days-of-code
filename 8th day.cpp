            // remove prime -> method 1;

#include<bits/stdc++.h>
using namespace std ;

bool isprime(int n)
{
    // check for prime ;
    for(int i = 2 ; i * i <= n ; i++)
    {
        if( n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void solve(vector<int> & v)
{
    int n = v.size() ;

                        // o(n) space , o(n) -> time
    // vector<int> ans;
    // for(int i = 0 ; i< n ; i++)
    // {
    //     if(isprime(arr[i]) == true)
    //     {
    //         continue;
    //     }
    //     else{
    //         ans.push_back(arr[i]);
    //     }
    // }

                 // o(1) space , o(n) -> time // inplace algorithm
    for (auto i = v.begin(); i != v.end(); ++i) {
        if (isprime(*i)) {
            v.erase(i);
            i--;
        }
    }

    for(int x : v)
    {
        cout<< x << " ";
    }
    cout<< endl;


}

int main()
{
    int n;
    cin>> n;
    vector<int> arr(n);
    for(int i= 0 ; i< n; i++)
    {
        cin>> arr[i];
    }

    solve(arr ) ;
    
}



//2nd codechef

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int x,y;
	    cin>>x>>y;
	    if(x==y || x>y)
            cout<<0<<endl;
        else if(x<y)
            cout<<abs(x-y)<<endl;
	}
	return 0;
}




//3 -> String Compression ;

#include<bits/stdc++.h>
using namespace std;


void solvefirst(string s)
{
    int n = s.size() ;
    string temp = ""; 
    temp += s[0];
    for(int i = 0 ; i< n-1 ; i++)
    {
        if(s[i] != s[i+1])
        {
            temp += s[i+1];
        }
        else{
            continue;  // s[i] == s[i + 1];
        }
    }
    
    cout<< temp << endl;

}

void solvesecond(string s )
{
    int n = s.size() ;
    string temp = ""; // empty string 
    temp += s[0] ; 
    int cnt = 1;
    for(int i = 0; i< n - 1 ; i++)
    {
        if(s[i] == s[i + 1])
        {
            cnt++;
        }
        else{
            if(cnt > 1)
            {
                temp += to_string(cnt) ;
                cnt = 1;
            }
            temp += s[i + 1];
        }
    }
    if(cnt > 1)
    {
        temp += to_string(cnt) ;
        cnt = 1;
    }
    cout<< temp << endl;


}

int main()
{
  string s;
  cin>> s;
  solvefirst(s) ;
  solvesecond(s) ;
  
}



// 4 to lower case 
class Solution {
public:
    string toLowerCase(string s) {
        string temp = "";
        // s[i] =  x
        for(auto x : s)
        {
            if(x >= 'A' && x <='Z')
            {
                temp += tolower(x);
            }
            else{
                temp += x;
            }
        }
        return temp ;
    }
};



// 5 - check palindrom 2
class Solution {
public:
    
    bool check(string s , int start , int end)
    {
        while(start < end)
        {
            if(s[start] != s[end])
            {
                return false;
            }
            start ++ ;
            end--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        
        int n = s.size() ;
        int start = 0 ;
        int end = n - 1 ;
        while(start < end)
        {
            if(s[start] != s[end])
            {
                // if(check(s , start + 1 , end) == true)
                // {
                //     return true;
                // }
                // else if (check(s , start , end - 1) == true)
                // {
                //     return true ;
                // }
                // else{
                //     return false;
                // }
                if(check(s, start + 1 , end) || check(s, start , end- 1) == true)
                {
                    return true;
                }
                else{
                    return false;
                }
                
            }
                start ++;
                end--;
        }
        return true;
    }
};
