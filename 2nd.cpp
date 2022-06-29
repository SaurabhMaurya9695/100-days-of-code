
// 1- count of digit  -> 1234567
#include<bits/stdc++.h>
using namespace std ;
// macros
#define ll long long 
#define all(x)   (x.begin(),x.end())

int main()
{
    ll  n ;
    cin>> n;  // taking input form the user
    // int cnt = 0;
    // while(n != 0)
    // {
    //     n = n/ 10;
    //     cnt++;
    // }
    // cout<< cnt << endl;

    // string s = to_string(n) ;
    // cout<< s.size() << endl;


}



// 2- sort the array ;

// int main()
// {
//     int n;
//     cin>> n; // asking from the user to give n -> size of n ;
//     //array -> int arr[n] ; // static;
//     vector<int> arr(n);
//     for(int i =0 ; i< n; i++)
//     {
//         cin>> arr[i]; // taking input in array
//     }

//     sort(arr.begin() , arr.end());
//     for(int i = 0 ; i< n ; i++)
//     {
//         cout<<arr[i] << " ";
//     }
// }


// 3- fitness codechef

// int main()
// {
//     int t;
//     cin>> t;
//     while(t--)
//     {
//         int n ;
//         cin>> n;
//         cout<< n * 10 << endl;
//         return ;
//     }
// }


// 4- codechef 2nd
// int main()
// {
//     int t;
//     cin>> t;
//     while(t--)
//     {
//         int n ;
//         cin>> n;
//         string s;
//         cin>> s;
//         for(auto & ch : s)
//         {
//             if(ch == 'A')
//             {
//                 ch ='T';
//             }
//             else if(ch == 'T')
//             {
//                 ch ='A';
//             }
//             else if(ch == 'G')
//             {
//                 ch = 'C';
//             }
//             else{
//                 ch = 'G';
//             }
//         }
//         cout<< s << endl;

//     }
// }


// 5- codechef 3;
// int main()
// {
//     int t;
//     cin >> t;
//     while(t--)
//     {
//         int n ;
//         cin >> n ;
//         int a = n % 100; // rem
//         int b = n / 100;  // solved fully
//         if(a+b <= 10)
//         {
//             cout<< a+b << endl;

//         }
//         else{
//             cout<< -1 << endl;

//         }
//     }
// }


// 6 -  is the prime number of not ?


// int main()
// {
//     int n ;
//     cin>> n ;
//     if( n == 1 || n == 0)
//     {
//         cout<<"NON prime\n";
//     }
//     for(int i = 2; i <= n / 2 ; i++)   
//     {
//         if(n % i == 0)
//         {
//             cout<<"prime\n";
//         }
//     }
// }

// 7 -> find min element
// int main()
// {
//     // int n;
    // cin>> n; // asking from the user to give n -> size of n ;
    // //array -> int arr[n] ; // static;
    // vector<int> arr(n);
    // for(int i =0 ; i< n; i++)
    // {
    //     cin>> arr[i]; // taking input in array
    // }
    // int min = INT_MAX;
    // int max = INT_MIN ;

    // for(int i = 0 ; i< n; i++)
    // {
    //     if(arr[i] > max)
    //     {
    //         max = arr[i];
    //     }        
    // }
    // for(int i = 0 ; i< n; i++)
    // {
    //     if(arr[i] < min)
    //     {
    //         min = arr[i];
    //     }        
    // }

    // cout<< "max is :" << max << "min is : "<< min << endl;

    // by using stl
    // int maxlem = *max_element(arr.begin() , arr.end()); 
    // int minele = *min_element(arr.begin() , arr.end());

    // cout<< maxlem << " " << minele << endl;
   
// }



