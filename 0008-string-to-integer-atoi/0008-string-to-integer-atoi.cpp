class Solution {
public:
    int myAtoi(string s) {

        int n = s.size();

        int i = 0;

        while (i < n && s[i] == ' ')
            i++;

        int sign = 1;

        if (i < n && (s[i] == '+' || s[i] == '-')) {

            if (s[i] == '-')
                sign = -1;

            i++;
        }

        long long ans = 0;

        while (i < n && isdigit(s[i])) {

            int digit = s[i] - '0';

            if (ans > INT_MAX / 10 ||
                (ans == INT_MAX / 10 && digit > 7)) {

                if (sign == 1)
                    return INT_MAX;

                return INT_MIN;
            }

            ans = ans * 10 + digit;

            i++;
        }

        return sign * ans;
    }
};