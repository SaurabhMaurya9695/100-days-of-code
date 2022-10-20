

vector<long long> findMissing(long long A[], long long B[],
                              int N, int M)
{
    // int n = sizeof(B) / sizeof(B[0]);
    unordered_map<int, int> mp;
    for (int i = 0; i < M; i++)
    {
        mp[B[i]]++;
    }
    vector<long long> ans;
    // int m = sizeof(A) / sizeof(A[0]);
    for (int i = 0; i < N; i++)
    {
        if (mp.find(A[i]) == mp.end())
        {
            ans.push_back(A[i]);
        }
    }
    return ans;
}
