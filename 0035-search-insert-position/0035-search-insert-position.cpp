class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    
        int left = 0, right = nums.size()- 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2; // prevent overflow
            if (nums[mid] == target) {
                return mid; // target found
            } else if (nums[mid] < target) {
                left = mid + 1; // search in right half
            } else {
                right = mid - 1; // search in left half
            }
        }
        
        // if not found, left is the correct insert position
        return left;

    }
};