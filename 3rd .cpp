#include<bits/stdc++.h>
using namespace std ;
int main()
{

    // 1- array

    int arr[10] ;
    for(int i = 0 ; i< 10; i++)
    {
        cin>> arr[i];
    }   

    // find the size;
    int n = sizeof(arr) / sizeof(arr[0]) ;
    // cout<< n << endl;

    //sort tghe array
      
}


// 2 -> chef and its apps
int main() {
	int t;
	cin>> t;
	while(t--)
	{
	    int a, b, c, d;
	    cin>> a>> b>> c>> d;
	    int bcsum = b + c;
	    int rem = a - bcsum ;
	    if(rem >= d)
	    {
	        cout<< 0 << endl;
	    }
	    else {
	       if(d-  rem <= b || d - rem <= c)
	       {
	           cout<< "1\n";
	       }
	       else{
	           cout << "2\n";
	       }
	    }
	    
	}
	return 0;
}


// 3 - adjcent sum parity
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>> t;
	while(t--)
	{
	    int n ;
	    cin>>n;
	    vector<int> arr(n) ;
	    for(int i = 0; i< n; i ++)
	    {
	        cin>> arr[i];
	    }
	    int sum = 0;
	   // for each loop
	   // for(int x : arr)
	   // {
	   //     sum += x;
	   // }
	   
	   for(int i = 0; i< n; i++)
	   {
	       sum += arr[i];
	   }
	   
	   if(sum % 2 == 0)
	   {
	       cout<< "YES\n";
	   }
	   else{
	       cout<<"NO\n";
	   }
	    
	    
	    
	}
	return 0;
}
https://www.codechef.com/START45D?order=desc&sortBy=successful_submissions


https://www.codechef.com/START44D?order=desc&sortBy=successful_submissions
