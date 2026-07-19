class Solution {
public:
    int findGCD(vector<int>& nums) {
         int mini = nums[0];

        int maxi = nums[0];

        for(int i = 1; i < nums.size(); i++) {

            if(nums[i] < mini)

                mini = nums[i];

            if(nums[i] > maxi)

                maxi = nums[i];

        }

        while(maxi != 0) {

            int temp = maxi;

            maxi = mini % maxi;

            mini = temp;

        }

        return mini;

    }

};
