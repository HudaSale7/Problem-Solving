class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        vector<vector<int>> v(nums.size() + 1);
        vector<int> sol(k);
        int n = 0;
        for(int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }
        auto it = map.begin();
        int i = 0;
        while(it != map.end()) {
            i = it->second;
            v[i].push_back(it->first);
            it++;
        }
        for(int i = v.size() - 1; i > 0; i--) {
            for(int j = 0; j < v[i].size(); j++) {
                if(k == 0) break;
                sol[n] = v[i][j];
                n++;
                k--;
            }
        }

        return sol;
    }
};