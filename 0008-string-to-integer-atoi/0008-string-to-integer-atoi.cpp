class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();

        while (i < n && s[i] == ' ')
            i++;

        if (i == n)
            return 0;

        int sign = 1;
        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }

        long long num = 0;

        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            if (num > INT_MAX / 10 ||
                (num == INT_MAX / 10 && digit > 7))
                return sign == 1 ? INT_MAX : INT_MIN;

            num = num * 10 + digit;
            i++;
        }

        return sign * num;
    }
};