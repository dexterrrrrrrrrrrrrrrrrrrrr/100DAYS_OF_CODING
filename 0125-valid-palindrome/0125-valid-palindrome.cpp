class Solution {
public:
    bool isPalindrome(string s) {
        string fltr;
        for (char c : s){
            if(isalnum(c)){
                fltr += tolower(c);
            }
        }

        int l = 0;
        int r = fltr.size() - 1;

        while(l < r){
            if(fltr[l] != fltr[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};