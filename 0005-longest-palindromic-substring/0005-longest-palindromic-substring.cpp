class Solution {
public:
    string longestPalindrome(string s) {
        int st=0,len=0,n=s.size();

        for(int i=0;i<n;i++){
            for(int d=0; d<2; d++){
                int l=i, r=i+d;
                while(l>=0 && r<n && s[l]==s[r]){
                    if(r-l+1>len) st=l,len=r-l+1;
                    l--; r++;
                }
            }
        }
        return s.substr(st,len);
    }
};