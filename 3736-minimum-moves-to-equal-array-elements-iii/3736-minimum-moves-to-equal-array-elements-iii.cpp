class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0;
        int maxi = INT_MIN;
        for(int &i: nums){
            if(i > maxi)maxi = i;
        }
        for(int &i : nums){
            ans += maxi - i;
        }
        return ans;
    }
};