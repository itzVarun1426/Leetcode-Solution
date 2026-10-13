class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long>sq;
        int h = nums.size()/2;
        long long total = 0;
        for(int &x: nums) {
            long long temp = 1LL * x * x;
            total+=temp;
            sq.push_back(temp);
        }
        nth_element(sq.begin(), sq.begin() + h, sq.end());
        long long small = accumulate(sq.begin(), sq.begin() + h, 0LL);

        return total - 2 * small;
    }
};