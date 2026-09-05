class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        vector<int> answer;

        int rows = matrix.size();
        int cols = matrix[0].size();

        int top = 0;
        int bottom = rows - 1;
        int left = 0;
        int right = cols - 1;

        while (top <= bottom && left <= right)
        {
            // Left -> Right
            for (int c = left; c <= right; c++)
                answer.push_back(matrix[top][c]);

            top++;

            // Top -> Bottom
            for (int r = top; r <= bottom; r++)
                answer.push_back(matrix[r][right]);

            right--;

            // Right -> Left
            if (top <= bottom)
            {
                for (int c = right; c >= left; c--)
                    answer.push_back(matrix[bottom][c]);

                bottom--;
            }

            // Bottom -> Top
            if (left <= right)
            {
                for (int r = bottom; r >= top; r--)
                    answer.push_back(matrix[r][left]);

                left++;
            }
        }

        return answer;
    }

};