class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        vector<int> suffix(n+1,0);

        for(int i = n-1 ; i>=0 ; i--)   
            suffix[i] = piles[i]+suffix[i+1];

        vector<vector<int>> dp(n , vector<int>( n+1 , 0));

        for(int i = n-1 ; i>=0 ;i--){
            for(int M=1 ; M<=n ; M++){
                if(i+2*M >= n){
                    dp[i][M] = suffix[i];
                    continue;
                }

                for(int x = 1 ; x<=2*M ; x++){
                    int newM = max(M,x);

                    dp[i][M] = max(dp[i][M],suffix[i]-dp[i+x][newM]);
                }
            }
        }
        return dp[0][1];
    }
};