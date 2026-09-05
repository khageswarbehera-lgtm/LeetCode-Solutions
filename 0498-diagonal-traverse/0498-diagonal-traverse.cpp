class Solution {
public:
        vector<int> findDiagonalOrder(
        vector<vector<int>>& mat)
    {
        int rows = mat.size();
        int cols = mat[0].size();

        vector<int> answer;

        int r = 0;
        int c = 0;

        bool up = true;

        while (answer.size() < rows * cols)
        {
            answer.push_back(mat[r][c]);

            if (up)
            {
                // Moving up-right.
                if (c == cols - 1)
                {
                    r++;
                    up = false;
                }
                else if (r == 0)
                {
                    c++;
                    up = false;
                }
                else
                {
                    r--;
                    c++;
                }
            }
            else
            {
                // Moving down-left.
                if (r == rows - 1)
                {
                    c++;
                    up = true;
                }
                else if (c == 0)
                {
                    r++;
                    up = true;
                }
                else
                {
                    r++;
                    c--;
                }
            }
        }

        return answer;
    }

};