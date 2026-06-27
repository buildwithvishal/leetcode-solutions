class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;  

        for (int i = 0; i< 2*n;i++) {
            int cur = nums[i%n];

            while (!st.empty() && nums[st.top()] <cur) {
                ans[st.top()] = cur;
                st.pop();
            }

            if (i <n) {
                st.push(i);
            }
        }

        return ans;
    }
};