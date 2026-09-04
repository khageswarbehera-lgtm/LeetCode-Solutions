class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r,int c)
{
    int rows = mat.size();
    int cols = mat[0].size();

    if (rows * cols != r * c)
        return mat;

    vector<vector<int>> answer(r, vector<int>(c));

    for (int k = 0; k < rows * cols; k++)
    {
        int oldRow = k / cols;
        int oldCol = k % cols;

        int newRow = k / c;
        int newCol = k % c;

        answer[newRow][newCol] = mat[oldRow][oldCol];
    }

    return answer;
}
};