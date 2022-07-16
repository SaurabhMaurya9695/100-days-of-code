// 1 ->  allocate number of pages ;

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int findmaxi(int pages[] , int books)
    {
        int maxi = INT_MIN;
        for(int i = 0; i< books ; i++)
        {
            if(pages[i] > maxi)
            {
                maxi = pages[i];
            }
        }
        return maxi ;
    }
    
    bool  ispossible(int pages[] , int books , int totalstu , int mid)
    {
        int currstudent = 1;
        int totalreadbystud = 0;
        for(int i = 0 ; i< books ; i++)
        {
            totalreadbystud += pages[i] ; // 20 + 10 + 30 + 40 // mid - > 70 
            if(totalreadbystud > mid)
            {
                currstudent++;
                totalreadbystud = pages[i] ;
            }
        }
        if(currstudent > totalstu) 
            return false;
        else{
            return true ;
        }
        
    }
    int findPages(int pages[], int books, int totalstud) 
    {
        int start =  findmaxi(pages , books);
        int sum = 0 ;
        for(int i = 0 ; i< books ; i++)
        {
            sum += pages[i];
        }
        int end = sum ;
        int ans = -1; // if no other possibility exist ;
        
        //starting binary Search;
        while(start <= end)
        {
            int mid = start + (end - start) / 2 ;
            if(ispossible(pages , books , totalstud , mid) == true)
            {
                ans = mid ; // we get the temp ans and check in left side ;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
            
        }
        return ans ;
    }
    
};


                                        //split array  and capacity to ship package into d days;
class Solution {
public:
    int findmaxi(vector<int>& pages , int books)
    {
        int maxi = INT_MIN;
        for(int i = 0; i< books ; i++)
        {
            if(pages[i] > maxi)
            {
                maxi = pages[i];
            }
        }
        return maxi ;
    }
    
    bool  ispossible(vector<int>& pages , int books , int totalstu , int mid)
    {
        int currstudent = 1;
        int totalreadbystud = 0;
        for(int i = 0 ; i< books ; i++)
        {
            totalreadbystud += pages[i] ; // 20 + 10 + 30 + 40 // mid - > 70 
            if(totalreadbystud > mid)
            {
                currstudent++;
                totalreadbystud = pages[i] ;
            }
        }
        if(currstudent > totalstu) 
            return false;
        else{
            return true ;
        }
        
    }
    int findpages(vector<int>& pages, int books, int totalstud) 
    {
        int start =  findmaxi(pages , books);
        int sum = 0 ;
        for(int i = 0 ; i< books ; i++)
        {
            sum += pages[i];
        }
        int end = sum ;
        int ans = -1; // if no other possibility exist ;
        
        //starting binary Search;
        while(start <= end)
        {
            int mid = start + (end - start) / 2 ;
            if(ispossible(pages , books , totalstud , mid) == true)
            {
                ans = mid ; // we get the temp ans and check in left side ;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
            
        }
        return ans ;
    }
    int splitArray(vector<int>& pages, int totalstud) {
        int books = pages.size() ; 
        int x = findpages(pages , books , totalstud);
        return x;
    }
};

                               // KOKO EATING BANANA;
class Solution {
public:
    
    bool ispossible(vector<int>& piles , int h , int mid)
    {
        long long  sum = 0 ;
        for(int i = 0 ; i< piles.size() ; i++)
        {
             sum += ((piles[i] % mid != 0) ? (piles[i] / mid) + 1 : piles[i] / mid) ;
        }
        if(sum > h)
        {
            return false;
        }
        else{
            return true;
        }
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1 ; //min eating speed
        int end = INT_MAX ; // max speed  ;
        int ans = h; // we assumed our koko can eat banana in h hours ;
        while(start <= end)
        {
            int mid = start + (end - start) / 2 ;
            if(ispossible(piles , h , mid) == true)
            {
                ans = mid ;
                end= mid - 1;
                
            }
            else{
                start = mid + 1;
            }
        }
        return ans ;
    }
};                               
