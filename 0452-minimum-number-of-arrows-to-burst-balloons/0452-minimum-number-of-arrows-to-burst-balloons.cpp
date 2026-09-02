class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {

        sort(points.begin(), points.end());

        int arrows = 1;
        int prevEnd = points[0][1];

        for (int i = 1; i < points.size(); i++) {

            if (prevEnd >= points[i][0]) {
                prevEnd = min(prevEnd, points[i][1]);
            }
            else {
                arrows++;
                prevEnd = points[i][1];
            }
        }

        return arrows;
    }
};