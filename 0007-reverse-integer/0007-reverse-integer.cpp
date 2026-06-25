class Solution {
public:
    int reverse(int x) {
        long long ans = 0;
        while(x!=0){
            long long q = x%10;
             x = x/10;

            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && q > 7)){
                return 0;
            }
            if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && q < -8)){
                return 0;
            }
            ans= 10*ans + q; 
        }

        return ans;        
    }
};