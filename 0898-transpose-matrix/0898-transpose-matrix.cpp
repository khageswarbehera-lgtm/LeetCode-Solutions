class Solution {
public:
   vector<vector<int>> transpose(vector<vector<int>>& matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<int>> answer(
        cols,
        vector<int>(rows)
    );

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            answer[c][r] = matrix[r][c];
        }
    }

    return answer;
}
};