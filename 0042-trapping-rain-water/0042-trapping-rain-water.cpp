class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftMax = 0;
        int rightMax = 0;
        int l = 0;
        int r = n-1;
        int ans = 0;
        while(l<r){
            if(height[l]<=height[r]){
                if(leftMax > height[l]){
                    ans+= leftMax-height[l];
                }
                else {
                    leftMax = height[l];
                }
                l++;
            }
            else{
                if(rightMax > height[r]){
                    ans+= rightMax-height[r];
                }
                else {
                    rightMax = height[r];
                }
                r--;
            }
        }

        return ans;
    }
};