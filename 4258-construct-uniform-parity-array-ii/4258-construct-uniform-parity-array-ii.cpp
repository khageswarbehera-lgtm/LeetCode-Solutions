class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        int minOdd = INT_MAX;

        // Find minimum odd
        for (int x : nums1) {
            if (x % 2 == 1) {
                minOdd = min(minOdd, x);
            }
        }

        // All numbers are even
        if (minOdd == INT_MAX) {
            return true;
        }

        // Check even numbers
        for (int x : nums1) {
            if (x % 2 == 0 && x < minOdd) {
                return false;
            }
        }

        return true;
    }
};