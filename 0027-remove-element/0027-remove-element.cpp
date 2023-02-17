class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
       
        int addPos = 0 ; 
        for(int i = 0; i < nums.size() ; i++){
            if(nums[i] != val){
                nums[addPos] = nums[i] ; 
                addPos++ ; 
            }
        }

        return addPos ;
    }
};