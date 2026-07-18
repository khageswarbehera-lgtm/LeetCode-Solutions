class Solution {
public:
    int gcd(int a, int b) {
        while (b) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    int findGCD(vector<int>& nums) {
        int mn = nums[0], mx = nums[0];

        for (int x : nums) {
            mn = min(mn, x);
            mx = max(mx, x);
        }

        return gcd(mn, mx);
    }
};