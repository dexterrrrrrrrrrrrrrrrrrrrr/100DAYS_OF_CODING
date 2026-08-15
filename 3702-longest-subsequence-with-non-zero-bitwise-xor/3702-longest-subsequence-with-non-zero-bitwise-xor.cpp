class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xr = 0 ;
        bool nz = false ; 

        for (int x : nums){
            xr ^= x;
            if(x!=0)
                nz = true ;
        }
        if(xr!=0)
            return nums.size();
        if(nz)
            return nums.size()-1;    
        return 0;
    }
};