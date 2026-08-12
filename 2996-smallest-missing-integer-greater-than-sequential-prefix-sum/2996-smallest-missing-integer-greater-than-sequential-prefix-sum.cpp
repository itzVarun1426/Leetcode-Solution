class Solution {
public:
    int missingInteger(vector<int>& nums) {
        map<int, bool> store;

        for (int i = 0; i < nums.size(); i++) {
            store[nums[i]] = true;
        }

        int prefixSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1)
                prefixSum += nums[i];
            else
                break;
        }

        while (store[prefixSum])
            prefixSum++;

        return prefixSum;
    }
};