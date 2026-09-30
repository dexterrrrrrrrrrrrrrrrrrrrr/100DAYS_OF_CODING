class Solution {
public:
    vector<int> maxDepthAfterSplit(string s) {
        int n = s.size();
        vector<int> r(n);

        for(int i = 0 ; i < n ; i++)
            r[i] = (i ^ s[i]) & 1;

        return r;
    }
};