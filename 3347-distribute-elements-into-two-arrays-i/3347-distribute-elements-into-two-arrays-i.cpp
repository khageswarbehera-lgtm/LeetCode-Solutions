class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {

        int i = 2;

        vector<int> arr1;
        vector<int> arr2;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        while (i < nums.size()) {

            if (arr1.back() > arr2.back()) {
                arr1.push_back(nums[i]);
            }
            else {
                arr2.push_back(nums[i]);
            }

            i++;
        }

        // Append arr2 to arr1
        for (int j = 0; j < arr2.size(); j++) {
            arr1.push_back(arr2[j]);
        }

        return arr1;
    }
};