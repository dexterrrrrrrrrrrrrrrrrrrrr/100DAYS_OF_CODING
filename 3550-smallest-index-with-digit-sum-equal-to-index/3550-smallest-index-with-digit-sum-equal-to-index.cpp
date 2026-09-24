class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        const int n = min (28, int(nums.size()));
        for(int i =0 ; i<n ; i++){
            int x = nums[i] , sum = 0 ;
            for(; x>0 ; x/=10){
                sum+=x%10;
            }
            if(sum == i) return i; 
        }
        return -1;
    }
};