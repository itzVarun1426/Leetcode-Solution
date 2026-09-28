class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int check = 0;
        for(auto &i : s){
            if(i == '('){
                if(check != 0)ans+=i;
                check++;
            }
            else{
                check--;
                if(check != 0)ans+=i;
            }
        }
        return ans;
    }
};
