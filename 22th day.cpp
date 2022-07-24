                //valid parenthesis string 

class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size() ;
        stack<int> openstack , starstack;
        
        for(int i = 0 ; i< n; i++)
        {
            if(s[i] == '(')
            {
                openstack.push(i); // we are pushing index
            }
            else if(s[i] == '*')
            {
                starstack.push(i);
            }
            else if(s[i] ==')') // *())) , )*
            {
                if(openstack.size() > 0) // !openstack.empty();
                {
                    openstack.pop();
                }
                else if(starstack.size() > 0 )
                {
                    starstack.pop();
                }
                else {
                    return false;
                }
            }
        }
        while(!openstack.empty())
        {
            if(starstack.size() == 0 ) return false; 
            else if(openstack.top() < starstack.top())
            {
                openstack.pop();
                starstack.pop();
            }
            else { 
                // openstack.top() > starstack.top()
                return false;
            }
        }
        return true;
    }
};

                                            // Evaluate revese polish notation 

class Solution {
public:
    int evalRPN(vector<string>& s) {
        int n = s.size();
        stack<int> stk;
        for(int i = 0 ; i< n ; i++)
        {
            if(s[i] != "+" && s[i] != "-" && s[i] != "/" && s[i] != "*")
            {
                stk.push(stoi(s[i]));
            }
            else {
                if(s[i] == "+")
                {
                    int a = stk.top();
                    stk.pop();
                    int b = stk.top();
                    stk.pop();
                    int c = b + a;
                    stk.push(c);
                }
                else if(s[i] == "-")
                {
                    int a = stk.top();
                    stk.pop();
                    int b = stk.top();
                    stk.pop();
                    int  c = b - a;
                    stk.push(c);
                }
                else if(s[i] == "*")
                {
                    int a = stk.top();
                    stk.pop();
                    int b = stk.top();
                    stk.pop();
                    int  c = b * a;
                    stk.push(c);
                }
                else if(s[i] == "/")
                {
                    int a = stk.top();
                    stk.pop();
                    int b = stk.top();
                    stk.pop();
                    int  c = b / a;
                    stk.push(c);
                }
            }
        
        }
     return stk.top();
    }

};

                            //Remove outermost parenthesis

class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size() ;
        stack<char> stk;
        string ans ="";
        for(int i = 0 ; i< n ; i++)
        {
            if(s[i] == '(')
            {
                if(stk.size() > 0)
                {
                    ans += s[i];
                }
                stk.push(s[i]);
            }
            else if(s[i] == ')')
            {
                stk.pop();
                if(stk.size() > 0)
                {
                    ans += s[i];
                }
                
            }
        }
        return ans ;
    }
};
