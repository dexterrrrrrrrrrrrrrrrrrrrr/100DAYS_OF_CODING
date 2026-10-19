class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int l = 0;
        int r = 0;

        for (int x : nums){
            l+=(x<target);
            r+=(x==target);
        }

        vector<int> ans(r);
        iota(ans.begin() ,ans.end() , l);
        return ans;
    }
};