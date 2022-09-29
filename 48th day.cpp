#include<bits/stdc++.h>
using namespace std;
int main()
{                       


    //                 // unordered_map   & map;
    // //syntax
    // // vector<int> arr = {1 , 1 ,12, 4 ,5 , 45 ,4,};

    // // unordered_map<string , int> ump = {
    // //     {"saurabh" , 1},
    // //     {"vikas" , 2},
    // //     {"yash" , 3},
    // //     {"vjhfgv", 12  },
    // //     {"vikas" , 25} ,
    // //     {"vikas" , 45},
    // // };

    // /*     1 - .at() 
    // cout<< ump.at("yash") << endl; 
    // cout<< ump["yash"] << endl;

    // ump.at("vikas") += 45;
    // cout<< ump.at("vikas") << endl;
    // */

    // /*
    //             // by for loop
    // for(auto it  = ump.begin() ; it != ump.end() ; it++)
    // {
    //     cout<< it->first << " " << it->second << "\n ";
    // }
    // cout<< endl;

    //             // by for each loop ;
    // for(auto it  : ump)
    // {
    //     cout<<it.first << " " << it.second << endl;
    // }
    // cout<< endl;
    // */
    // // /*  
    //             // Insert
    // unordered_map<string , int> ump;
    // // ump.insert({"yash" , 2});
    // // ump.insert({"vikas" , 4});
    // // ump.insert({"saurabh" ,89});

    // ump["yash"] = 2 ;
    // ump["vikas"] = 4 ;
    // ump["saurabh"] = 89;
    // ump["xyz"] = 45;

    // //defining iterator ;
    // // unordered_map<string , int>:: iterator  it;

    // for(auto  it  = ump.begin() ; it != ump.end() ; it++)
    // {
    //     cout<< it->first << " " << it->second << "\n ";
    // }
    // cout<< endl;
    

    // // */

    // /*       
    //               Find
    // if(ump.find("saurabh") != ump.end())
    // {
    //     cout<<"present";
    // }
    // else{
    //     cout<<"NP" << endl;
    // }

    // */

    // // ump.clear();
    // // cout<< ump.size() << endl;
    // // ump.erase("xyz") ;
    // // for(auto it  : ump)
    // // {
    // //     cout<<it.first << " " << it.second << endl;
    // // }
    // // cout<< endl;


                         // set & unordered_set;

    //synatx;
    // set<data_type> st ;

    // set<int , greater<int>> st ;  // sort in desending order;
                         // insert ;
    // st.insert(4);
    // st.insert(5);
    // st.insert(6);
    // st.insert(6);

                        //print;
    //  1- by for loop 

            // //defining a iterator
            // set<int>::iterator it ;
            // for(it = st.begin() ; it != st.end() ; it++)
            // {
            //     cout<< *it << endl;
            // }

    // 2 - by for each loop
    // for(auto it : st)
    // {
    //     cout<< it << endl;
    // }

    
    // cout<< *st.begin() << endl;
    // cout<< st.size() << endl;

    // st.erase(6);
    // for(auto it : st)
    // {
    //     cout<< it << endl;
    // }
    // cout<< *st.rbegin() << endl;


    // vector<int> arr = {1,2,2,3,2,4,5,6,8} ;
    // map<int,int> ump ;
    
    // // insert array using method 1 ;
    // for(int i = 0 ; i< arr.size() ; i++)
    // {
    //     int x = arr[i];
    //     ump[x]++;
    // }
    // // for(auto it : ump)
    // // {
    // //     if(it.first == 2)
    // //     {
    // //         cout<< it.second << endl;
    // //     }
    // // }
    // for(auto it : ump)
    // {
    //     cout<< it.first << " " << it.second << endl;
    // }

}


                            // find the duplicate number

class Solution {
public:
    int findDuplicate(vector<int>& arr) 
    {
        unordered_map<int,int> mp ;
        for(auto x : arr)
        {
            mp[x] ++;
        }
        int max = INT_MIN;
        int val =  0 ;
        for(auto it : mp)
        {
            if(it.second > max)
            {
                max = it.second;
                val = it.first;
            }
        }
        return val;
    }
};

                    // design hashmap

class MyHashMap {
public:
    unordered_map<int , int > ump;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        ump[key] = value;
    }
    
    int get(int key) {
        if(ump.find(key) != ump.end()) // we find that value then return true or false;
        {
            return ump[key] ;
        }
        else{
            return -1;
        }
    }
    
    void remove(int key) {
        ump.erase(key);
    }
};

                        //design hashset



