class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map1;
        vector<int> sol;
        int n = nums1.size();
        sol.reserve(n);
        
        for(int i = 0; i < n; i++) {
            if(!map1.count(nums1[i]))
                map1[nums1[i]] = 1;
        }
        
        for(int i = 0; i < nums2.size(); i++) {
            if(map1.count(nums2[i])) {
                sol.push_back(nums2[i]);
                map1.erase(nums2[i]);
            }
        }
        return sol;
    }
};