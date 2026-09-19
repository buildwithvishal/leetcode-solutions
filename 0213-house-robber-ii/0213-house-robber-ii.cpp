class Solution {
    int solve(vector<int>& nums, int l, int r) {
        vector<int> dp(r - l + 1, -1);

        if (r - l + 1 == 1) {
            return nums[l];
        }

        dp[0] = nums[l];
        dp[1] = max(nums[l], nums[l + 1]);

        for (int i = 2; i <= r - l; i++) {
            int take = nums[l + i] + dp[i - 2];
            int notTake = dp[i - 1];

            dp[i] = max(take, notTake);
        }

        return dp[r - l];
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        int ans1 = solve(nums, 0, n - 2);
        int ans2 = solve(nums, 1, n - 1);

        return max(ans1, ans2);
    }
};