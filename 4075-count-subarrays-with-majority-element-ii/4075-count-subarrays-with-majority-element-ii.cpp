class Fenwick {
private:
    int n;
    vector<int> bit;

public:
    Fenwick(int n) {
        this->n = n;
        bit.resize(n + 1, 0);
    }

    // Add value to index
    void update(int index, int value) {
        while (index <= n) {
            bit[index] += value;
            index += index & -index;
        }
    }

    // Sum from 1 to index
    int query(int index) {
        int sum = 0;

        while (index > 0) {
            sum += bit[index];
            index -= index & -index;
        }

        return sum;
    }
};

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {

        int n = nums.size();

        // Prefix sums can be from -n to +n.
        // Shift them by n+1 so they become positive.
        Fenwick ft(2 * n + 1);

        int prefix = n + 1;

        // Empty prefix
        ft.update(prefix, 1);

        long long ans = 0;

        for (int x : nums) {

            // Convert:
            // target     -> +1
            // non-target -> -1
            if (x == target)
                prefix++;
            else
                prefix--;

            // Count previous prefix sums < current prefix
            ans += ft.query(prefix - 1);

            // Store current prefix
            ft.update(prefix, 1);
        }

        return ans;
    }
};