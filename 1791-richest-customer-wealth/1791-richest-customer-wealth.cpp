class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int rich=0;
        for(int i=0;i<accounts.size();i++)
       
        {
            int currentwealth=0;
             for(int j=0;j<accounts[0].size();j++)
            
            {
                currentwealth+=accounts[i][j];

            }
            if(rich<currentwealth)
            rich=currentwealth;
        }
        return rich;
        
    }
};