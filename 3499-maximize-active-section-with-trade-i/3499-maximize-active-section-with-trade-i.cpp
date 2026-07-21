class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();

        int ones = 0;
        for(char ch : s)
            if(ch=='1') ones++;

            string t= "1" + s + "1";
            int m = t.size();

            int gain = 0;

            for(int i=1 ; i<m-1 ;){
                if(t[i]=='1'){
                    int l = i;
                    while(i<m && t[i]=='1')
                    i++;

                    int r=i-1;

                    if(t[l-1]=='0' && t[r+1]=='0'){

                        int leftzeros = 0;
                        int j = l-1;

                        while(j>=0 && t[j]=='0'){
                            leftzeros++;
                            j--;
                        }

                        int rightzeros = 0;
                        j=r+1;

                        while(j<m && t[j]=='0'){
                            rightzeros++;
                            j++;
                        }
                        gain = max(gain ,leftzeros+rightzeros);
                    }
                }
                else{
                    i++;
                }
            }
            return ones+gain;
    }
};