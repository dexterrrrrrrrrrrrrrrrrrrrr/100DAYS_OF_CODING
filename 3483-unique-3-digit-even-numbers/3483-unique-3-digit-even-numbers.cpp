class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int cnt[10] = {}, ans = 0;

        for (int x : digits) cnt[x]++;

        for (int i = 1; i <= 9; i++) {
            for (int j = 0; j <= 9; j++) {
                for (int k = 0; k <= 8; k += 2) {

                    int need[10] = {};
                    need[i]++;
                    need[j]++;
                    need[k]++;

                    if (need[i] <= cnt[i] &&
                        need[j] <= cnt[j] &&
                        need[k] <= cnt[k])
                        ans++;
                }
            }
        }

        return ans;
    }
};