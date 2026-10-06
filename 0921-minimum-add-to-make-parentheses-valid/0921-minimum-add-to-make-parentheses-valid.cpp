class Solution {
public:
    int minAddToMakeValid(string s) {
        int l=0 , r=0;
        for (char c : s){
            bool il = (c=='(');
            l+=il;
            (l>0)?l-=(!il):r+=(!il);
        }
        return l+r;
    }
};