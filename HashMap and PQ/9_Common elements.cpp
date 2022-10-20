public:
vector<int> commonElements(int AA[], int BB[], int CC[], int n1, int n2, int n3)
{
    vector<int> A(n1);
    for (int i = 0; i < n1; i++)
    {
        A[i] = AA[i];
    }
    vector<int> B(n2);
    for (int i = 0; i < n2; i++)
    {
        B[i] = BB[i];
    }
    vector<int> C(n3);
    for (int i = 0; i < n3; i++)
    {
        C[i] = CC[i];
    }
    unordered_map<int, int> mp1;
    unordered_map<int, int> mp2;
    unordered_map<int, int> mp3;
    for (auto x : A)
    {
        mp1[x]++;
    }
    for (auto x : B)
    {
        mp2[x]++;
    }
    for (auto x : C)
    {
        mp3[x]++;
    }
    vector<int> ans;
    for (auto it : A)
    {
        if (mp2.find(it) != mp2.end() && mp3.find(it) != mp3.end())
        {
            ans.push_back(it);
            mp2.erase(it);
            mp3.erase(it);
        }
    }
    for (auto it : B)
    {
        if (mp1.find(it) != mp1.end() && mp3.find(it) != mp3.end())
        {
            ans.push_back(it);
            mp1.erase(it);
            mp3.erase(it);
        }
    }
    for (auto it : C)
    {
        if (mp1.find(it) != mp1.end() && mp2.find(it) != mp2.end())
        {
            ans.push_back(it);
            mp1.erase(it);
            mp2.erase(it);
        }
    }
    if (ans.size() == 0)
    {
        return {-1};
    }
    else
    {
        return ans;
    }
}
