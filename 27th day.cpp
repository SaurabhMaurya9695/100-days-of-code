                                // Trapping rain Water Problem ;

//Method 1;  // time -> o(n) , space - o(n);
class Solution {
public:
    
    // time -> o(n) , space -> o(n); 
//     vector<int> leftboundary(vector<int>  arr ,int n)
//     {
//         vector<int> left_b(n ,  0);
//         left_b[0] = arr[0] ; // for now I'm the biggest boundary;
//         int temp = arr[0];
//         for(int i = 1 ; i< n ; i++)
//         {
//             if(arr[i] > temp) // 0 1 0 2 1 
//                                      // 0 
//             {
//                 temp = arr[i];
//                 left_b[i] = arr[i];
//             }
//             else{
//                 left_b[i] = temp;
//             }
//         }
//         return left_b;
        
//     }
//     vector<int> rightboundary(vector<int> arr , int n)
//     {
//         vector<int> right_b(n,0);
//         right_b[n-1] = arr[n-1];
//         for(int i = n-2 ; i>=0 ; i--)
//         {
//             if(arr[i] > right_b[i+1]) // n- 2 + 1; => n - 1;
//             {
//                 right_b[i] = arr[i];
//             }
//             else{
//                 right_b[i] = right_b[i+1];
//             }
//         }
//         return right_b;
        
//     }
//     int trap(vector<int>& arr) {
//         int n = arr.size();
//         vector<int> left = leftboundary(arr , n);
//         vector<int> right = rightboundary(arr , n);
//         int water =0 ;
//         for(int i = 0 ; i< n ; i++)
//         {
//             water += min(left[i] , right[i]) - arr[i];
//         }
//         return water ;
//     }
    
    
    // time-> o(n) , sapce ->o(1);
    
    int trap(vector<int>& arr) 
    {
        int n = arr.size();
        
        // base case;
        if(n<=2) return 0;
        int left_b = arr[0] ;
        int right_b = arr[n-1];
        int left = 1 , right = n-2;
        int ans = 0;
        while(left <= right)
        {
            if(left_b < right_b)
            {
                // we are in the left;
                if(arr[left] > left_b)   // 0 1
                {
                    // we cam't store water here;
                    left_b = arr[left];
                }
                else{
                    ans += left_b - arr[left];  // adding the water 
                }
                left++;
            }
            else{
                if(arr[right] > right_b)   // 0 1
                {
                    // we cam't store water here;
                    right_b = arr[right];
                }
                else{
                    ans += right_b - arr[right];
                }
                right--;
            }
        }
                       return ans;
    }
};

                    //container with most water

// time -> o(n) space->o(1) ;
class Solution {
public:
    int maxArea(vector<int>& arr){
        int n = arr.size();
        int i =0 ;
        int j = n -1 ;
        int maxarea = 0;
        while(i < j)
        {
            int level = min(arr[i] , arr[j] ) * (j - i ) ;
            maxarea = max(level , maxarea) ;
            if(arr[i] < arr[j])
            {
                i++;
            }
            else{
                j--;
            }
            
        }
        return maxarea;
        
    }
};
                        //  Remove K Digits

class Solution {
public:
    string removeKdigits(string num, int k) 
    {
        if( k == 0)
        {
            return num;
        }
        
        if(num.size() == k or num.size() == 0)
        {
            return "0";
        }
        
        stack<char> stk;
        
        for(int i=0; i<num.size(); i++)
        {
            while(k>0 and stk.size()>0 and stk.top() > num[i])
            {
                k--;
                stk.pop();
            }
            
            stk.push(num[i]);
        }
        
        while(k>0 and stk.size()>0)
        {
            k--;
            stk.pop();
        }
        
        // All elements now in stack, so now make string
        string str = "";
        
        while(!stk.empty())
        {
            str.push_back(stk.top()); stk.pop();
        }
        
        
        reverse(str.begin(), str.end());
        
        // possibility of leading zeros
        int d=0;
        int len = str.size();
        while(d<str.size())
        {
            if(str[d] == '0')
            {
                d++;
            }
            else
            {
                break;
            }
        }
        
        if(d == str.size())
        {
            return "0";
        }
        string ans = str.substr(d);
        
            
        return ans;
    }
};


                        // Remove Digit From Number to Maximize Result

class Solution {
public:
    string removeDigit(string s, char d) {
        
        // if all the number are in inc order ;
        string ans ="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == d){
                string temp= s;
                temp = temp.erase(i, 1);  //1 is length of string
                ans = max(ans,temp);
            }
        }
        return ans;
        
        
    }
};
