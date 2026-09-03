class Solution {
public:
    int jump(vector<int>& nums) {

        int jumps = 0;
        int currentEnd = 0;
        int farthest = 0;

        for (int i = 0; i < nums.size() - 1; i++) {

            // Find the farthest position
            // reachable from current range
            farthest = max(farthest, i + nums[i]);

            // We have reached the end of current range
            if (i == currentEnd) {

                jumps++;

                // Start a new range
                currentEnd = farthest;
            }
        }

        return jumps;
    }
};