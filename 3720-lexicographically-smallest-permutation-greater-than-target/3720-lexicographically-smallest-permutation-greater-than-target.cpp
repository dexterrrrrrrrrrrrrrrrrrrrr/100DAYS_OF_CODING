class Solution {
public:
    string lexGreaterPermutation(string s, string t) {
        vector<int> f(26);
        for(char c : s) f[c-'a']++;

        int n = s.size();

        for(int i = 0; i < n; i++) {
            int x = t[i] - 'a';

            if(f[x]) {
                f[x]--;              // match target
                continue;
            }

            // Current char unavailable, try bigger
            for(int c = x + 1; c < 26; c++) {
                if(f[c]) {
                    string ans = t.substr(0, i) + char('a' + c);
                    f[c]--;

                    for(int j = 0; j < 26; j++)
                        ans += string(f[j], 'a' + j);

                    return ans;
                }
            }

            // Need to backtrack
            for(int j = i - 1; j >= 0; j--) {
                f[t[j] - 'a']++;

                for(int c = t[j] - 'a' + 1; c < 26; c++) {
                    if(f[c]) {
                        string ans = t.substr(0, j) + char('a' + c);
                        f[c]--;

                        for(int x = 0; x < 26; x++)
                            ans += string(f[x], 'a' + x);

                        return ans;
                    }
                }
            }

            return "";
        }

        // t itself is a permutation, so need strictly greater
        for(int j = n - 1; j >= 0; j--) {
            f[t[j] - 'a']++;

            for(int c = t[j] - 'a' + 1; c < 26; c++) {
                if(f[c]) {
                    string ans = t.substr(0, j) + char('a' + c);
                    f[c]--;

                    for(int x = 0; x < 26; x++)
                        ans += string(f[x], 'a' + x);

                    return ans;
                }
            }
        }

        return "";
    }
};