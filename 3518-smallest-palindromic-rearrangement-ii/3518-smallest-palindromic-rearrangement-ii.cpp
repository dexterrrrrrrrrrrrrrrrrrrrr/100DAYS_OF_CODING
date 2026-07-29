class Solution {
public:
    static const long long MAXK = 1000001;

    vector<long long> fact;

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        string mid = "";

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2) {
                mid = char('a' + i);
                break;
            }
        }

        vector<int> half(26, 0);
        int len = 0;

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            len += half[i];
        }

        computeFactorials(len);

        string left = "";

        if (!buildKthPalindrome(half, k, left, len))
            return "";

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }

private:
    bool buildKthPalindrome(vector<int>& freq, long long k,
                            string& ans, int len) {

        if (len == 0)
            return true;

        for (int i = 0; i < 26; i++) {

            if (freq[i] == 0)
                continue;

            freq[i]--;

            long long perms = multinomial(freq);

            if (k <= perms) {
                ans.push_back(char('a' + i));
                return buildKthPalindrome(freq, k, ans, len - 1);
            } else {
                k -= perms;
                freq[i]++;
            }
        }

        return false;
    }

    long long multinomial(vector<int>& cnt) {

        int total = 0;
        for (int x : cnt)
            total += x;

        long long res = 1;

        for (int i = 0; i < 26; i++) {

            if (cnt[i] == 0)
                continue;

            res *= binom(total, cnt[i]);

            if (res >= MAXK)
                return MAXK;

            total -= cnt[i];
        }

        return res;
    }

    long long binom(int n, int k) {

        if (k > n)
            return 0;

        if (k > n - k)
            k = n - k;

        long long res = 1;

        for (int i = 1; i <= k; i++) {

            res = res * (n - i + 1) / i;

            if (res >= MAXK)
                return MAXK;
        }

        return res;
    }

    void computeFactorials(int n) {
    fact.resize(n + 1);
    fact[0] = 1;

    for (int i = 1; i <= n; i++) {
        if (fact[i - 1] > MAXK)
            fact[i] = MAXK;
        else
            fact[i] = min(MAXK, fact[i - 1] * 1LL * i);
        }
    }
};