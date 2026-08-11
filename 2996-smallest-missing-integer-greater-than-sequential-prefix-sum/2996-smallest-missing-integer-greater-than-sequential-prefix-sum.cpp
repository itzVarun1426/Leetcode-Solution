class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_map<int,bool>store;
        int prefSum = nums[0];
        bool isPref = true;
        int temp = nums[0];
        store[nums[0]] = true;
        int n = nums.size();
        for(int i = 1; i<n; i++){
            store[nums[i]] = true;
            if(isPref){
                if(nums[i] == nums[i-1]+1)
                {
                    temp+=nums[i];
                    prefSum = max(prefSum,temp);
                }
                else {
                    temp = nums[i];
                    isPref= false;
                }
            }
        }
        for( ;  ;prefSum++)if(!store[prefSum])return prefSum;
        return 0;
    }
};