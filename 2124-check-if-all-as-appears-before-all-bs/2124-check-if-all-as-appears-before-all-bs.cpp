class Solution {
public:
    bool checkString(string s) {
        int i = 0;
        while(i < s.length() && s[i] == 'a'){
            i++;
        }
        if(i == s.length())return true;
        else {
            while(i < s.length()){
                if(s[i] == 'a')return false;
                i++;
            }
        }
        return true;
    }
};