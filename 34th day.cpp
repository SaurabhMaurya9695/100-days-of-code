#include <bits/stdc++.h>
using namespace std;

bool isQueenSafe(int row, int col, vector<vector<int>> chess)
{
    // checking in top
    for (int i = row - 1, j = col; i >= 0; i--)
    {
        if (chess[i][j] == 1)
        {
            return false;
        }
    }

    // checking in row
    for (int i = row, j = col + 1; j < chess.size(); j++)
    {
        if (chess[i][j] == 1)
        {
            return false;
        }
    }

    // checking in left upper diag
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (chess[i][j] == 1)
        {
            return false;
        }
    }

    // checking in right upper diag
    for (int i = row - 1, j = col + 1; i >= 0 && j < chess.size(); i--, j++)
    {
        if (chess[i][j] == 1)
        {
            return false;
        }
    }
    return true;
}

void printNQueens(vector<vector<int>> chess, string qsf, int row)
{
    if (row == chess.size())
    {
        cout << qsf << ". " << endl;
        return;
    }
    // loop through columns
    for (int col = 0; col < chess.size(); col++)
    {
        if (isQueenSafe(row, col, chess))
        {
            // placing at that col
            chess[row][col] = 1;
            printNQueens(chess, qsf + to_string(row) + "-" + to_string(col) + ", ", row + 1);

            //   backtracked
            chess[row][col] = 0;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> chess(n, vector<int>(n));

    printNQueens(chess, "", 0);
}


/* ````````````````SUbset ````````````````````````*/
class Solution {
    public:
    void solve(vector<int> & nums, int idx, vector<vector<int>>& result)
    {
        // we are at last index;
        if(idx == nums.size()-1){
            result.push_back({});
            result.push_back({nums[idx]});
        }
        else{
            solve(nums , idx + 1, result);
            int n = result.size();
            for(int i=0;i<n;i++)
            {
                vector<int> r = result[i];
                r.push_back(nums[idx]);
                result.push_back(r);
            }
        }
    }
    vector<vector<int>> subsets(vector<int>& nums){
        vector<vector<int>> result;
        if(nums.size() == 0) return result;
        solve(nums, 0 , result);
        return result;
    }
};

/* ``````````````Print encodings``````````````````````````*/
#include <bits/stdc++.h>
using namespace std;

void solve(string s, string ans)
{
	if (s.length()==0)
    {
        cout<<ans<<endl;
        return;
	}

	int code1 = s[0]-'0';
	char atcode1 = char('a'+code1-1);
	int code2 = stoi(s.substr(0,2));
	char atcode2 = char('a'+code2-1);

	if(code1 != 0)
		solve(s.substr(1),ans + atcode1);
	if(code2 >=10 && code2 <=26)
		solve(s.substr(2),ans + atcode2);
}

int main()
{
	string s ;
    cin>> s;
	solve(s,"");

	return 0;
}
