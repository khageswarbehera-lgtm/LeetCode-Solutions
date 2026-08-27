class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
            vector<int> diff(1001, 0);
            int current=0;
        for(int i=0;i<trips.size();i++)
        {
            int passengers=trips[i][0];
            int from=trips[i][1];
            int to=trips[i][2];
            diff[from] += passengers;
            diff[to]   -= passengers;

        }
        for(int x:diff)
        {
            current+=x;
            if(current>capacity)
            return false;
        }
        return true;
        
    }
};