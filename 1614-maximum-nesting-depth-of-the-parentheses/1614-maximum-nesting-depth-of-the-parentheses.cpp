class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int temp = 0;
        for(auto &i: s){
            if(i == '('){
                temp++;
                ans = max(ans, temp);
            }
            if(i == ')')temp--;
        }
        return ans;
    }
};