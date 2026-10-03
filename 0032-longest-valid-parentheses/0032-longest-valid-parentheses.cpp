class Solution {
public:
    int longestValidParentheses(string s) {
        int r = 0 ;
        vector<int> stack = {-1};

        for(int j = 0 ; j<s.size() ; j++){
            if(s[j] == '(')
                stack.push_back(j);
            else{
                stack.pop_back();

                if(stack.empty())
                    stack.push_back(j);
                else
                    r = max(r,j - stack.back());
            }
        }
        return r;
    }
};