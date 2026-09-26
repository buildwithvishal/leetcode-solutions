class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;

        int cnt = n / 2; // 2 ke alawa initially odd numbers

        vector<bool> s(n, true);

        for(int i = 3; i * i < n; i += 2) {
            if(s[i]) {
                for(int j = i * i; j < n; j += 2 * i) {
                    if(s[j]) {
                        s[j] = false;
                        cnt--;
                    }
                }
            }
        }

        return cnt;
    }
};