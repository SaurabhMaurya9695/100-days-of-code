class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        vector<pair<long, int>> v(nums.size());
        
        for (int i = 0; i < nums.size(); i++) {
            v[i] = make_pair(nums[i], i);
        }
        sort(v.begin(), v.end());
        
        for (int i = 0; i < v.size(); i++) {
            for (int j = i + 1; j < v.size(); j++) {
                if ((v[j].first - v[i].first) <= t) {
                    if (abs(v[j].second - v[i].second) <= k) {
                        return true;
                    }
                } else {
                    break;
                }
            }
        }
        return false;
    }
};