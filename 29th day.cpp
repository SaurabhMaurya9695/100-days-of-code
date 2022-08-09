                        // print Increasing
// time -> o(n) , space -> o(n) -> stack space
#include<iostream>
using namespace std;

void printIncreasing(int n){
    
    // base case;
    if(n == 0) return ;
    printIncreasing(n-1);
    cout<< n << endl;
    
    
}


int main(){
    int n; cin>>n;
    printIncreasing(n);
}
                        
                        // Print Decreasing

// time -> o(n) , space -> o(n) -> stack space
#include <bits/stdc++.h>
using namespace std;

void printDecreasing(int n){
    if(n == 0) return ;
    cout<< n << endl;  // 5
    printDecreasing(n - 1); // p(4);
    
}

int main(){
    int n;
    cin >> n;
    printDecreasing(n);
}
                                // Print Increasing Decreasing

// time -> o(n) , space -> o(n) -> stack space
#include<iostream>
using namespace std;

void printIncDec(int n){
    if(n == 0 )return ;
    cout<< n << endl;
    printIncDec(n -1);
    cout<< n << endl;
    
    
}


int main(){
    int n; cin>>n;
    printIncDec(n);
}

                                    // factorial

// time -> o(n) , space -> o(n) -> stack space
#include<iostream>
using namespace std;

int fact(int n){
    // base case ;
    if(n == 1) return 1;
    return n * fact(n-1);
}


int main(){
    int n; cin>>n;
    cout<<fact(n);
}


                                // Power-linear

// time -> o(n) , space -> o(n) -> stack space
#include<iostream>
using namespace std;

int power(int x,int n){
   if(n == 0) return 1;
   else{
       return x * power(x , n -1) ;
   }

}


int main(){
    int n,x; cin>>x>>n;
    cout<<power(x,n);
}

                            // Power-logarithmic

// time -> o(log(n))  , space -> o(n) -> stack space
#include<iostream>
using namespace std;

int plog(int x,int n){
   
   if(n == 0) return 1;
   int xn2 = plog(x, n/ 2);
   int ans = 0;
    if(n % 2 == 0)
    {
        ans = xn2 * xn2;
    }
    else{
        ans = xn2 * xn2 * x;
    }
    return ans;
    
}

int main(){
    int x,n; cin>>x>>n;
    cout<<plog(x,n);
}


                                    //Power of Two
// time -> o(log(n)) , space -> o(n) -> stack space
class Solution {
public:
    bool isPowerOfTwo(int n) {
        // base case ;
        if(n == 1) return true;
        if(n < 1) return false;
        if(n % 2 == 0)
            return isPowerOfTwo(n/2);
        else{
            return false;
        }
        return true;
    
    }
};



