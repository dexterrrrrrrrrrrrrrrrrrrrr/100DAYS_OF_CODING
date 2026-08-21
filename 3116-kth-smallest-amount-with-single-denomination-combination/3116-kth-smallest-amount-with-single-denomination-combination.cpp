class Solution {
public:
    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    long long count(long long x, vector<int>& coins) {
        int n = coins.size();
        long long ans = 0;

        for(int mask = 1; mask < (1 << n); mask++) {
            long long L = 1;
            int bits = 0;
            bool ok = true;

            for(int i = 0; i < n; i++) {
                if(mask & (1 << i)) {
                    bits++;

                    L = lcm(L, coins[i]);

                    if(L > x) {
                        ok = false;
                        break;
                    }
                }
            }

            if(!ok) continue;

            if(bits % 2)
                ans += x / L;
            else
                ans -= x / L;
        }

        return ans;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        long long l = 1;
        long long r = 1LL * coins[0] * k;

        while(l < r) {
            long long mid = l + (r - l) / 2;

            if(count(mid, coins) >= k)
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }
};