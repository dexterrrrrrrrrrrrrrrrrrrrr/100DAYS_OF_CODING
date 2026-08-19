class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map <int, int> mp;

        for(auto &v : reservedSeats){
            int row = v[0];
            int seat = v[1];

            mp[row]|=(1<<seat);
        }

        int ans = (n-mp.size())*2;

        for(auto &[row,mask]:mp){

            bool left = true;
            bool mid = true;
            bool right = true;

            for(int i = 2 ; i<=5 ; i++){
                if(mask & (1<<i))
                    left = false;
            }

            for(int i = 4 ; i<=7 ; i++){
                if(mask & (1<<i))
                    mid = false;
            }

            for(int i = 6 ; i<=9 ; i++){
                if(mask & (1<<i))
                    right = false;
            }

            if(left && right)
                ans += 2;

            else if(left || mid || right)
                ans += 1;
        }
        return ans;
    }
};