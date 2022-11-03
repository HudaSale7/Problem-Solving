class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map1;
        unordered_map<int, int> map2;
        vector<int> sol;
        int n = 0;
        if(nums1.size() > nums2.size())
            n = nums1.size();
        else
             n = nums2.size();
        sol.reserve(n);
        for(int i = 0; i < n; i++) {
            if(i < nums1.size()) {
                if(map1.count(nums1[i]))
                    map1[nums1[i]]++;
                else
                    map1[nums1[i]] = 1;
                }
            if(i < nums2.size()) {
                if(map2.count(nums2[i]))
                    map2[nums2[i]]++;
                else
                    map2[nums2[i]] = 1;
                }
        }
        
        auto it = map1.begin();
        while(it != map1.end()) {
            if(map2.count(it->first)) {
                if(it->second < map2[it->first]) {
                    sol.insert(sol.end(), it->second, it->first);
                }
                else {
                    sol.insert(sol.end(), map2[it->first], it->first);
                }
            }
        it++;
        }   
        return sol;            
    }
};