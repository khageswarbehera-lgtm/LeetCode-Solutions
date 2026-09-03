class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());

        int n = nums.size();

        int left = (n - 1) / 2;
        int right = n - 1;

        for (int i = 0; i < n; i += 2) {
            nums[i] = temp[left--];
        }

        for (int i = 1; i < n; i += 2) {
            nums[i] = temp[right--];
        }
    }
};