class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int n = arr.size(); // extract the size of the array
        
        unordered_map<int, int> mp; // declaring unordered map
        
        // Step 1)  we are giving 1 to each of the elemnt
        // (Assuming that it may be the starting point of consecutive sequence)
        for(int i = 0; i < n; i++)
        {
            mp[arr[i]] = 1;
        }
        
        // step 2) validating our assumption taken in step 1
        for(int i = 0; i < n; i++)
        {
            if(mp.find(arr[i] - 1) != mp.end()) // if(arr[i] - 1) is present in map
            {
                // then arr[i] can never be the starting point some of consecutive sequence
                // so give value zero for that arr[i]
                mp[arr[i]] = 0;
            }
        }
        
        // step 3) Now the elements for which value 1 is left
        // for them we definately know they are the starting point of 
        // some consecutive sequence, using that length trick we find the maxlen
        
        int mxLen = 0; // this variable holds my answer
        
        for(int i = 0; i < n; i++) // travel in the array
        {
            // if value is 1, then they are starting point some of consecutive sequence
            if(mp[arr[i]] == 1) 
            {
                // if it is the starting point, then definately length is going to be 
                // atleast 1
                int length = 1; 
                
               // we dicuss it above
                while(mp.find(arr[i] + length) != mp.end())
                {
                    length++;
                }
                
                mxLen = max(mxLen, length); // update mxLen
            }
        }
        
        return mxLen; // Finally return mxLen
    }
};


// `````````````````````````````Method 2  ````````````````````````````````````````````
class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int n = arr.size(); // extract the size of array
        if(n == 0) return 0; // if length of array is zero, then from here simply return 0
        
        sort(arr.begin(), arr.end()); // sort the array
        
        int mxLen = 0, currLen = 1; // put mxLen = 0, and currLen as 1
        
        for(int i = 1; i < n; i++) // traverse from the array
        {
            if(arr[i] == arr[i - 1] + 1) // this is the part of consecutive sequence
            {
                currLen++; // increase the curr Length by 1
            }
            else if(arr[i] != arr[i - 1]) // but if it is not equal
            {
                mxLen = max(mxLen, currLen); // update our mxLen 
                currLen = 1; // and reset the currLen with 1
            }
        }
        
        mxLen = max(mxLen, currLen); // update our mxLen 
        return mxLen; // Finally return mxLen
    }
};