class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();
                int ans=0;

        for(int top = 0; top < rows; top++)
        {
            vector<int> colSum(cols, 0);

            for(int bottom = top; bottom < rows; bottom++)
            {
                for(int col = 0; col < cols; col++)
                {
                    colSum[col] += matrix[bottom][col];
                }
                unordered_map<int,int> mp;
                int sum=0;
                mp[0]=1;
                for(int x:colSum)
                {
                    sum +=x;
                    int required=sum-target;
                    if(mp.find(required)!=mp.end())
                    ans+=mp[required];
                    mp[sum]++;

                }
            }
        }
        return ans;
        
    }
};