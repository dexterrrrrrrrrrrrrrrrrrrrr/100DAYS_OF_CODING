class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int m = stoneValue.size();

        vector<int> dp(m+1,0);

        for(int i=m-1 ; i>=0 ; i--){
            dp[i] = INT_MIN;

            int sum = 0;

            for(int k=0 ; k<3 && i+k<m ; k++){
                sum+= stoneValue[i+k];
                dp[i]=max(dp[i] , sum-dp[i+k+1]);
            }
        }

        if(dp[0]>0)
            return "Alice";
        if(dp[0]<0)
            return "Bob";
        return "Tie";
    }
};