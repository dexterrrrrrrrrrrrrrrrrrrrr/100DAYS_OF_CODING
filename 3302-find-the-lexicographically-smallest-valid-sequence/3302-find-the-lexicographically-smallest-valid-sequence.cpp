class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();

        vector<int> last(m,-1);

        int i = n-1 , j = m-1;

        while(i>=0 && j>=0){
            if(word1[i]==word2[j])
                last[j--] = i;
            i--;
        }

        vector<int> ans;
        bool usedmismatched = false;
        j=0;

        for(i=0;i<n && j<m;i++){
            if(word1[i]==word2[j]){
                ans.push_back(i);
                j++;
            }
            else if(!usedmismatched && (j==m-1 || i<last[j+1])){
                ans.push_back(i);
                usedmismatched = true;
                j++;
            }
        }
        if(j==m){
            return ans;
        }
        return {};
    }
};