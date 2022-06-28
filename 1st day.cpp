// Level 1 
// stl 
// vector , array , string , priority_queue , queue , stack , map , set ;

#include<bits/stdc++.h>
using namespace std ;
int main()
{
    // bits/stdc++.h -> it includes all the stl;

    // 1-> vector
    // main operation -> push , pop , front , back , sort , sortindec , reverse , iterrate
    // vector<int> v ;

    // syntax - vector<data-type> declartion (size , fill);

    // vector<int> v(5, 1);  // 1 1 1 1 1
    // push;
    // vector<int> v;
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(5);
    // v.push_back(4);
    // v.push_back(9);

    // print 
    // 1 st method using for loop ;
    // for(int i = 0; i < v.size() ; i++)
    // {
    //     cout<<v[i] << " ";
    // }

    // using for each loop;
    // for(auto each : v )
    // {
    //     cout<< each << " ";
    // }

    // size ;
    // int n = v.size() ;

    // get the fornt value ;
    // cout<< v.front() << endl;

    // for getting back ;
    // cout<< v.back() << endl;

    // sort
    // itertor base ;
    // sort(v.begin() , v.end()) ;

    // for(auto x : v)
    // {
    //     cout<< x << " ";
    // }

    //in reverse direction;
    // reverse(v.begin() , v.end());
    // for(auto x : v)
    // {
    //     cout<< x << " ";
    // }

    // pop ;
    // vector<int> v;
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(5);
    // v.push_back(4);
    // v.push_back(9);

    // for(auto x : v)
    // {
    //     cout<< x << " ";
    // }

    // pop ;
    // v.pop_back();
    // v.pop_back();
    
    // for(auto x : v)
    // {
    //     cout<< x << " ";
    // }

    // decleration of vector;
    // vector<int> v = { 1 , 2 , 3 , 4 , 5};

    // copying a vector;
    // vector<int> copy(v.begin() , v.end());
    // vector<int> copy = v;



                            // strings ;
    // push , pop , traverse, iterate , sort , reverse , update ;
    // string s = "vikas";
    // s.push_back('s');
    // cout<< s << endl;

    // s.pop_back() ;
    // cout<< s << endl;

    // size
    // int n = s.size() ;
    // traverse
    // for(int i = 0; i< n ; i++)
    // {
    //     cout<< s[i] << endl;
    // }

    // using for each loop
    // for(auto each : s)
    // {
    //     cout<< each << endl;
    // } 

    // sort a string;
    // sort(s.begin() , s.end());
    // cout<< s ;

    // reverse;
    // reverse(s.begin(), s.end());
    // sort(s.rbegin() , s.rend());
    // cout<< s ;


    // changing v to t;
    // string s = "viksssa";
    // for(auto & ch : s)
    // {
    //     if(ch == 'v')
    //     {
    //         ch = 't';
    //     }
    // }
    // cout<< s << endl;

    // for(int i = 0; i< s.size() ; i++)
    // {
    //     if(s[i] == 'v'){
    //         s[i] = 't';
    //     }
    // }
    // cout<< s << endl;

    // swap k and s ;
    // swap(s[2] , s[3]) ;
    // cout<< s << endl;

    // string s = "viksssa";
    // int kidx = 0 , aidx = 0;
    // for(int i = 0; i< s.size() ; i++)
    // {
    //     if(s[i] == 'k' )
    //     {
    //         kidx =i ;
    //         break;
    //     }
    // }
    // for(int i = 0; i< s.size() ; i++)
    // {
    //     if(s[i] == 'a' )
    //     {
    //         aidx =i ;
    //         break;
    //     }
    // }
    // // cout<< kidx << " " << aidx << " " << endl;
    // swap(s[kidx] , s[aidx]) ;
    // cout<< s << endl;


                            // stack;
    // operations - > push , pop , empty,  size, top , 

    stack< string > stk;

    // stk.push("vikas");
    // stk.push("simran");
    // cout<< stk.top() << endl;
    // stk.push("anushka");
    // cout<< stk.top() << endl;
    // stk.pop();

    // cout<< stk.top() << endl;

    // while(! stk.empty())
    // {
    //     cout << stk.top() << endl;
    //     stk.pop();
    // }
    





}