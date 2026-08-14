class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int>count(27,0);
        int n = s.length();
        int left = 0;
        int ans = 0;
        for(int right = 0;right<n;right++){
            count[s[right] - 'a']++;

            while(count[s[right]-'a'] > 2){
                count[s[left]-'a']--;
                left++;
            }
            ans = max(ans, right-left+1);
        }
        return ans;

    }
};