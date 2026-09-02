class Solution {
public:
    vector<vector<int>> intervalIntersection(
        vector<vector<int>>& firstList,
        vector<vector<int>>& secondList
    ) {

        vector<vector<int>> ans;

        int i = 0;
        int j = 0;

        while (i < firstList.size() && j < secondList.size()) {

            // Find intersection start
            int start = max(firstList[i][0], secondList[j][0]);

            // Find intersection end
            int end = min(firstList[i][1], secondList[j][1]);

            // If intersection exists
            if (start <= end) {
                ans.push_back({start, end});
            }

            // Move the interval that ends earlier
            if (firstList[i][1] < secondList[j][1]) {
                i++;
            }
            else {
                j++;
            }
        }

        return ans;
    }
};