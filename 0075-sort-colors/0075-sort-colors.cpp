class Solution {
public:
    void sortColors(vector<int>& nums) {
        auto zeroP = nums.begin();
        auto twoP = nums.end() - 1;
        auto moveP = nums.begin();
        auto track = moveP;

        while(moveP <= twoP) {
            if(*moveP == 0) {
                swap(*moveP, *zeroP);
                zeroP++;
            }
            else if(*moveP == 2) {
                swap(*moveP, *twoP);
                twoP--;  
            } 
            
            if(*moveP == 1) {
                moveP++;
                track = moveP - 1;
            }
            
            else if(*moveP == 0 && *track == 0) {
                moveP++;
                track = moveP - 1;
            }
        }
    }
};