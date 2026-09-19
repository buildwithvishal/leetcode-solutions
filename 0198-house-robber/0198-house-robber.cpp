class Solution {
    int houseRob(int n, vector<int>& nums, vector<int>& dp) {
        if (n == 0) {
            return nums[0];
        }
        if (n < 0) {
            return 0;
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        int take = nums[n] + houseRob(n - 2, nums, dp);
        int notTake = 0 + houseRob(n - 1, nums, dp);
        dp[n] = max(take, notTake);
        return dp[n];
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        int ans = houseRob(n - 1, nums, dp);
        return ans;
    }
};