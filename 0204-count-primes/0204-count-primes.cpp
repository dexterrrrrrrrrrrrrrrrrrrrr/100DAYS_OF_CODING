class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;

        int c = n - 2;
        vector<char> prime(n,1);

        for(int i = 2 ; i*i < n ; i++){
            if (prime[i]){
                for (int j = i*i ; j<n ; j+=i){
                    
                    if(prime[j]){
                        prime[j]=0;
                        c--;
                    }
                }
            }
        }
        return c;
    }
};