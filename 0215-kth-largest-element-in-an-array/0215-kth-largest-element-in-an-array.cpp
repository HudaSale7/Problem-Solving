class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size() - 1;
        int sol = 0;
        for(int i = size / 2; i >= 0; i--) {
            heapify(nums, size, i);
        }
        for (int i = size; i > size - k; i--) {
            swap(nums[i], nums[0]);
            sol = nums[i];
            heapify(nums, i - 1, 0);
        }
        return sol;
    }
    
    void heapify(vector<int>& nums, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        if(left <= n && nums[left] > nums[largest])
            largest = left;
        
        if(right <= n && nums[right] > nums[largest])
            largest = right;
        
        if(largest != i) {
            swap(nums[i], nums[largest]);
            heapify(nums, n, largest);
        }
    }
};