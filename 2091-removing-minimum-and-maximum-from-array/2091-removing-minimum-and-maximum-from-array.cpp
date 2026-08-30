class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int mini = min_element(nums.begin() , nums.end())-nums.begin();
        int maxi = max_element(nums.begin() , nums.end())-nums.begin();

        int a = min(mini,maxi);
        int b = max(mini,maxi);

        return min({b + 1, n - a, a + 1 + n - b});
    }
}; 